"""
add_edgesphere_hey_and_mynaa_single_words.py
=============================================
Processes 10 real board mic 'HEY' recordings and 10 real board mic 'MYNAA' recordings
from C:/EdgeSphere/Collected_Data/Audio/hey and C:/EdgeSphere/Collected_Data/Audio/mynaa.
Generates 1,500+ targeted hard negative clips into dataset/not-wake-word.
"""

import os
import wave
import glob
import numpy as np
from pathlib import Path
from tqdm import tqdm

HEY_DIR = Path("C:/EdgeSphere/Collected_Data/Audio/hey")
MYNAA_DIR = Path("C:/EdgeSphere/Collected_Data/Audio/mynaa")
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

def process_word_folder(folder_path, prefix):
    files = list(folder_path.glob("*.wav"))
    print(f"Found {len(files)} real board mic '{prefix}' recordings in {folder_path}")
    count = 0
    np.random.seed(42)

    for idx, f_path in enumerate(tqdm(files, desc=f"Generating '{prefix}' Hard Negatives")):
        base_audio = load_resample(f_path)
        if base_audio is None:
            continue

        # 1. Clean original
        save_wav(NWW_DIR / f"board_single_{prefix}_{idx:03d}_orig.wav", base_audio)
        count += 1

        # 2. Gain variations (10 levels)
        for g_idx, gain in enumerate([0.3, 0.5, 0.7, 1.0, 1.3, 1.6, 2.0, 2.5, 3.0, 3.5]):
            save_wav(NWW_DIR / f"board_single_{prefix}_{idx:03d}_vol_{g_idx}.wav", base_audio * gain)
            count += 1

        # 3. Speed / Pitch variations (8 levels)
        for s_idx, speed in enumerate([0.85, 0.90, 0.95, 1.0, 1.05, 1.10, 1.15, 1.20]):
            save_wav(NWW_DIR / f"board_single_{prefix}_{idx:03d}_speed_{s_idx}.wav", change_speed(base_audio, speed))
            count += 1

        # 4. Time shifts (6 positions)
        for t_idx, shift in enumerate([-1200, -600, -300, 300, 600, 1200]):
            save_wav(NWW_DIR / f"board_single_{prefix}_{idx:03d}_shift_{t_idx}.wav", np.roll(base_audio, shift))
            count += 1

        # 5. Combination augmentations (50 variations)
        for c_idx in range(50):
            spd = np.random.uniform(0.85, 1.18)
            gn = np.random.uniform(0.4, 2.5)
            shf = np.random.randint(-1000, 1000)
            noise_lvl = np.random.uniform(10, 60)
            noise = np.random.normal(0, noise_lvl, CLIP_SAMPLES)
            combo = (np.roll(change_speed(base_audio, spd), shf) * gn) + noise
            save_wav(NWW_DIR / f"board_single_{prefix}_{idx:03d}_combo_{c_idx}.wav", combo)
            count += 1

    return count

def main():
    c_hey = process_word_folder(HEY_DIR, "hey")
    c_mynaa = process_word_folder(MYNAA_DIR, "mynaa")
    total = c_hey + c_mynaa

    print("\n==================================================================")
    print(f"Successfully generated {total:,} single-word ('HEY' + 'MYNAA') hard negative clips!")
    print(f"Saved into: {NWW_DIR.resolve()}")
    print("==================================================================")

if __name__ == "__main__":
    main()
