"""
augment_edgesphere_mynaa.py
===========================
Reads real board-recorded "HEY MYNAA" WAV files from EdgeSphere
(C:/EdgeSphere/Collected_Data/Audio/hey mynaa) and creates ~3,000+
acoustically augmented WAV files in dataset/a_wake-word.
"""

import os
import wave
import glob
import numpy as np
from pathlib import Path
from tqdm import tqdm

EDGESPHERE_DIR = Path("C:/EdgeSphere/Collected_Data/Audio/hey mynaa")
OUT_DIR = Path("dataset/a_wake-word")
OUT_DIR.mkdir(parents=True, exist_ok=True)

TARGET_SR = 8000
CLIP_SAMPLES = 7680  # 1-second audio frame for 30x16 Mel matrix

def load_resample_format(wav_path):
    try:
        with wave.open(str(wav_path), 'rb') as wf:
            sr = wf.getframerate()
            n_ch = wf.getnchannels()
            raw = wf.readframes(wf.getnframes())

        data = np.frombuffer(raw, dtype=np.int16).astype(np.float32)
        if len(data) == 0:
            return None

        if n_ch > 1:
            data = data.reshape(-1, n_ch).mean(axis=1)

        if sr != TARGET_SR:
            new_len = int(len(data) * TARGET_SR / sr)
            indices = np.linspace(0, len(data) - 1, new_len).astype(int)
            data = data[indices]

        if len(data) >= CLIP_SAMPLES:
            data = data[:CLIP_SAMPLES]
        else:
            pad_len = CLIP_SAMPLES - len(data)
            left = pad_len // 2
            right = pad_len - left
            data = np.pad(data, (left, right), mode='constant')

        return data
    except Exception as e:
        print(f"Error reading {wav_path}: {e}")
        return None

def save_wav(out_path, data):
    data_int16 = np.clip(data, -32768, 32767).astype(np.int16)
    with wave.open(str(out_path), 'wb') as wf:
        wf.setnchannels(1)
        wf.setsampwidth(2)
        wf.setframerate(TARGET_SR)
        wf.writeframes(data_int16.tobytes())

def change_speed(audio, speed_factor):
    new_len = int(len(audio) / speed_factor)
    indices = np.linspace(0, len(audio) - 1, new_len)
    resampled = np.interp(indices, np.arange(len(audio)), audio)
    if len(resampled) >= CLIP_SAMPLES:
        return resampled[:CLIP_SAMPLES]
    else:
        pad = CLIP_SAMPLES - len(resampled)
        return np.pad(resampled, (pad // 2, pad - pad // 2), mode='constant')

def add_synthetic_noise(audio, noise_type="gaussian", level=30.0):
    if noise_type == "gaussian":
        noise = np.random.normal(0, level, CLIP_SAMPLES)
    elif noise_type == "brown":
        noise = np.cumsum(np.random.normal(0, level/3, CLIP_SAMPLES))
        noise = noise - np.mean(noise)
        if np.max(np.abs(noise)) > 0:
            noise = noise / np.max(np.abs(noise)) * level
    elif noise_type == "fan":
        t = np.linspace(0, 0.96, CLIP_SAMPLES)
        noise = level * np.sin(2 * np.pi * 60 * t) + (level * 0.7) * np.sin(2 * np.pi * 120 * t)
    else:
        noise = np.zeros(CLIP_SAMPLES)
    return audio + noise

def main():
    wav_files = list(EDGESPHERE_DIR.glob("*.wav"))
    print(f"Found {len(wav_files)} real GPX-I2S mic recordings in {EDGESPHERE_DIR}")

    if not wav_files:
        print("No WAV files found in EdgeSphere folder!")
        return

    count = 0
    np.random.seed(42)

    for i, wav_file in enumerate(tqdm(wav_files, desc="Augmenting HEY MYNAA recordings")):
        base_audio = load_resample_format(wav_file)
        if base_audio is None:
            continue

        # 1. Clean original
        save_wav(OUT_DIR / f"board_real_{i:03d}_orig.wav", base_audio)
        count += 1

        # 2. Volume variations
        for g_idx, gain in enumerate([0.3, 0.5, 0.7, 1.2, 1.6, 2.0, 2.5]):
            save_wav(OUT_DIR / f"board_real_{i:03d}_vol_{g_idx}.wav", base_audio * gain)
            count += 1

        # 3. Speed / Tempo variations
        for s_idx, speed in enumerate([0.85, 0.90, 0.95, 1.05, 1.12, 1.20, 1.28]):
            sped = change_speed(base_audio, speed)
            save_wav(OUT_DIR / f"board_real_{i:03d}_speed_{s_idx}.wav", sped)
            count += 1

        # 4. Time shifts
        for t_idx, shift in enumerate([-1200, -800, -400, 400, 800, 1200]):
            shifted = np.roll(base_audio, shift)
            save_wav(OUT_DIR / f"board_real_{i:03d}_shift_{t_idx}.wav", shifted)
            count += 1

        # 5. Acoustic Noise Mixing (Gaussian, Brownian, Fan hum)
        for n_idx, noise_type in enumerate(["gaussian", "brown", "fan"]):
            for lvl_idx, lvl in enumerate([20.0, 50.0, 100.0]):
                noised = add_synthetic_noise(base_audio, noise_type, lvl)
                save_wav(OUT_DIR / f"board_real_{i:03d}_noise_{n_idx}_{lvl_idx}.wav", noised)
                count += 1

        # 6. Combined Speed + Volume + Shift
        for c_idx in range(15):
            spd = np.random.uniform(0.88, 1.18)
            gn = np.random.uniform(0.4, 1.8)
            shf = np.random.randint(-800, 800)
            combo = np.roll(change_speed(base_audio, spd), shf) * gn
            save_wav(OUT_DIR / f"board_real_{i:03d}_combo_{c_idx}.wav", combo)
            count += 1

    print("\n==================================================================")
    print(f"Successfully generated {count:,} augmented 'HEY MYNAA' WAV files!")
    print(f"Saved in: {OUT_DIR.resolve()}")
    print("==================================================================")

if __name__ == "__main__":
    main()
