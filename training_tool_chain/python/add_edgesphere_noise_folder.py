"""
add_edgesphere_noise_folder.py
==============================
Processes the 5 new real GPX-I2S board mic noise recordings (~16.6 minutes)
in C:/EdgeSphere/Collected_Data/Audio/noise/ and adds ~1,000 clips into dataset/not-wake-word.
"""

import os
import wave
import glob
import numpy as np
from pathlib import Path

NOISE_DIR = Path("C:/EdgeSphere/Collected_Data/Audio/noise")
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

def main():
    noise_files = list(NOISE_DIR.glob("*.wav"))
    print(f"Found {len(noise_files)} new real board noise recordings in {NOISE_DIR}")

    if not noise_files:
        print("No noise WAV files found!")
        return

    clip_count = 0

    for idx, f_path in enumerate(noise_files):
        try:
            with wave.open(str(f_path), 'rb') as wf:
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

            num_clips = len(data) // CLIP_SAMPLES
            for c in range(num_clips):
                clip = data[c * CLIP_SAMPLES : (c + 1) * CLIP_SAMPLES]
                save_wav(NWW_DIR / f"board_new_noise_{idx:02d}_{c:04d}.wav", clip)
                clip_count += 1
        except Exception as e:
            print(f"Error processing {f_path}: {e}")

    print("\n==================================================================")
    print(f"Successfully processed {clip_count:,} new real board noise clips (~{clip_count*0.96/60:.1f} mins)!")
    print(f"Saved into: {NWW_DIR.resolve()}")
    print("==================================================================")

if __name__ == "__main__":
    main()
