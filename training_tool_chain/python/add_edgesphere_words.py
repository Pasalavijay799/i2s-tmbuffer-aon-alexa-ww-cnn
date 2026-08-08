"""
add_edgesphere_words.py
========================
Processes the new real board-mic spoken word recordings in
C:/EdgeSphere/Collected_Data/Audio/words/ and adds augmented 1-sec clips into dataset/not-wake-word.
"""

import os
import wave
import glob
import numpy as np
from pathlib import Path

WORDS_DIR = Path("C:/EdgeSphere/Collected_Data/Audio/words")
NWW_DIR = Path("dataset/not-wake-word")
NWW_DIR.mkdir(parents=True, exist_ok=True)

TARGET_SR = 8000
CLIP_SAMPLES = 7680  # 0.96 sec frame

def save_wav(out_path, data):
    data_int16 = np.clip(data, -32768, 32767).astype(np.int16)
    with wave.open(str(out_path), 'wb') as wf:
        wf.setnchannels(1)
        wf.setsampwidth(2)
        wf.setframerate(TARGET_SR)
        wf.writeframes(data_int16.tobytes())

def main():
    word_files = list(WORDS_DIR.glob("*.wav"))
    print(f"Found {len(word_files)} real board mic word recordings in {WORDS_DIR}")

    if not word_files:
        print("No word WAV files found!")
        return

    count = 0
    for idx, f_path in enumerate(word_files):
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

            # Slice into 1-second chunks
            num_chunks = len(data) // CLIP_SAMPLES
            for chunk_i in range(max(1, num_chunks)):
                chunk = data[chunk_i * CLIP_SAMPLES : (chunk_i + 1) * CLIP_SAMPLES]
                if len(chunk) < CLIP_SAMPLES:
                    pad = CLIP_SAMPLES - len(chunk)
                    chunk = np.pad(chunk, (0, pad), mode='constant')

                # Save original chunk
                save_wav(NWW_DIR / f"board_word_{idx:03d}_{chunk_i}_orig.wav", chunk)
                count += 1

                # Gain variations
                for g_idx, gain in enumerate([0.4, 0.7, 1.3, 1.8, 2.4]):
                    save_wav(NWW_DIR / f"board_word_{idx:03d}_{chunk_i}_vol_{g_idx}.wav", chunk * gain)
                    count += 1

                # Time shifts
                for s_idx, shift in enumerate([-1200, -600, 600, 1200]):
                    save_wav(NWW_DIR / f"board_word_{idx:03d}_{chunk_i}_shift_{s_idx}.wav", np.roll(chunk, shift))
                    count += 1

        except Exception as e:
            print(f"Error processing {f_path}: {e}")

    print("\n==================================================================")
    print(f"Successfully generated {count:,} real board-mic spoken word hard negative clips!")
    print(f"Saved into: {NWW_DIR.resolve()}")
    print("==================================================================")

if __name__ == "__main__":
    main()
