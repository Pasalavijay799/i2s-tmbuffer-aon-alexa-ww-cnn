"""
add_edgesphere_heymeta.py
=========================
Generates 3,000+ targeted hard negative clips for 'HEY META' directly from real board mic
recordings in C:/EdgeSphere/Collected_Data/Audio/hey meta.
"""

import os
import wave
import glob
import numpy as np
from pathlib import Path
from tqdm import tqdm

HEYMETA_DIR = Path("C:/EdgeSphere/Collected_Data/Audio/hey meta")
NWW_DIR = Path("dataset/not-wake-word")
NWW_DIR.mkdir(parents=True, exist_ok=True)

TARGET_SR = 8000
CLIP_SAMPLES = 7680

def save_wav(out_path, data):
    data_int16 = np.clip(data, -32768, 32767).astype(np.int16)
    with wave.open(str(out_path), 'wb') as wf:
        wf.setnchannels(1)
        wf.setsampwidth(2)
        wf.setframerate(TARGET_SR)
        wf.writeframes(data_int16.tobytes())

def load_resample(wav_path):
    try:
        with wave.open(str(wav_path), 'rb') as wf:
            sr = wf.getframerate()
            n_ch = wf.getnchannels()
            raw = wf.readframes(wf.getnframes())

        data = np.frombuffer(raw, dtype=np.int16).astype(np.float32)
        if n_ch > 1:
            data = data.reshape(-1, n_ch).mean(axis=1)

        if sr != TARGET_SR:
            new_len = int(len(data) * TARGET_SR / sr)
            indices = np.linspace(0, len(data) - 1, new_len).astype(int)
            data = data[indices]

        if len(data) >= CLIP_SAMPLES:
            return data[:CLIP_SAMPLES]
        else:
            pad = CLIP_SAMPLES - len(data)
            return np.pad(data, (pad // 2, pad - pad // 2), mode='constant')
    except Exception as e:
        print(f"Error loading {wav_path}: {e}")
        return None

def change_speed(audio, speed_factor):
    new_len = int(len(audio) / speed_factor)
    indices = np.linspace(0, len(audio) - 1, new_len)
    resampled = np.interp(indices, np.arange(len(audio)), audio)
    if len(resampled) >= CLIP_SAMPLES:
        return resampled[:CLIP_SAMPLES]
    else:
        pad = CLIP_SAMPLES - len(resampled)
        return np.pad(resampled, (pad // 2, pad - pad // 2), mode='constant')

def main():
    meta_files = list(HEYMETA_DIR.glob("*.wav"))
    print(f"Found {len(meta_files)} real board mic 'HEY META' recordings in {HEYMETA_DIR}")

    count = 0
    np.random.seed(42)

    for idx, f_path in enumerate(tqdm(meta_files, desc="Generating HEY META Hard Negatives")):
        base_audio = load_resample(f_path)
        if base_audio is None:
            continue

        # 1. Clean original
        save_wav(NWW_DIR / f"board_heymeta_{idx:03d}_orig.wav", base_audio)
        count += 1

        # 2. Dense Gain variations (15 levels)
        for g_idx, gain in enumerate([0.2, 0.35, 0.5, 0.65, 0.8, 1.0, 1.2, 1.4, 1.6, 1.8, 2.0, 2.3, 2.6, 3.0, 3.5]):
            save_wav(NWW_DIR / f"board_heymeta_{idx:03d}_vol_{g_idx}.wav", base_audio * gain)
            count += 1

        # 3. Dense Speed / Pitch variations (12 levels)
        for s_idx, speed in enumerate([0.80, 0.85, 0.88, 0.92, 0.95, 0.98, 1.02, 1.05, 1.10, 1.15, 1.20, 1.25]):
            save_wav(NWW_DIR / f"board_heymeta_{idx:03d}_speed_{s_idx}.wav", change_speed(base_audio, speed))
            count += 1

        # 4. Dense Time shifts (10 positions)
        for t_idx, shift in enumerate([-1600, -1200, -800, -400, -200, 200, 400, 800, 1200, 1600]):
            save_wav(NWW_DIR / f"board_heymeta_{idx:03d}_shift_{t_idx}.wav", np.roll(base_audio, shift))
            count += 1

        # 5. Heavy Combination augmentations (200 variations per clip)
        for c_idx in range(250):
            spd = np.random.uniform(0.82, 1.22)
            gn = np.random.uniform(0.3, 2.8)
            shf = np.random.randint(-1200, 1200)
            noise_lvl = np.random.uniform(10, 80)
            noise = np.random.normal(0, noise_lvl, CLIP_SAMPLES)
            combo = (np.roll(change_speed(base_audio, spd), shf) * gn) + noise
            save_wav(NWW_DIR / f"board_heymeta_{idx:03d}_combo_{c_idx}.wav", combo)
            count += 1

    print("\n==================================================================")
    print(f"Successfully generated {count:,} targeted 'HEY META' hard negative clips!")
    print(f"Saved into: {NWW_DIR.resolve()}")
    print("==================================================================")

if __name__ == "__main__":
    main()
