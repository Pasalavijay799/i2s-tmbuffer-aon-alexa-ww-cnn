"""
add_board_noise_to_dataset.py
==============================
The board outputs near-zero uint16 feature matrices during silence.
Our training data only had PC-mic samples (values 0-15).
This script adds REALISTIC BOARD SILENCE NOISE to not-wake-word.npy
so the model learns: silence/near-zero → NOT wake word.

Board silence profile (observed from UART stream):
  - Most values: 0x0000 (zero)
  - Occasional values: 1-15 (sensor noise)
  - Rarely up to 30-50 in some bins
"""

import numpy as np
from pathlib import Path

NPY_DIR = Path("npy-files")
rng = np.random.default_rng(seed=42)

NUM_SILENCE_SAMPLES     = 5000   # pure zero frames (like board sends in silence)
NUM_LOW_NOISE_SAMPLES   = 3000   # very low energy frames (quiet room)
NUM_MEDIUM_NOISE_SAMPLES = 2000  # moderate noise (fans, AC, talking in distance)

print("Generating synthetic board-realistic noise samples...")
print(f"  Shape of each sample: (30, 16)")

# --- Type 1: Pure silence (all zeros) ---
# The board sends all-zero frames when completely silent
silence = np.zeros((NUM_SILENCE_SAMPLES, 30, 16), dtype=np.uint16)
print(f"  Type 1 - Pure silence: {NUM_SILENCE_SAMPLES} samples (all zeros)")

# --- Type 2: Very low noise (0-8 range, sparse) ---
# Board sensor noise / microphone idle noise
low_noise = rng.integers(0, 9, size=(NUM_LOW_NOISE_SAMPLES, 30, 16), dtype=np.uint16)
# Make it sparse - most values still zero
mask = rng.random((NUM_LOW_NOISE_SAMPLES, 30, 16)) > 0.7  # only 30% non-zero
low_noise = (low_noise * mask).astype(np.uint16)
print(f"  Type 2 - Low noise (0-8, sparse): {NUM_LOW_NOISE_SAMPLES} samples")

# --- Type 3: Moderate ambient (0-25 range) ---
# Fan noise, office noise, AC
medium_noise = rng.integers(0, 7, size=(NUM_MEDIUM_NOISE_SAMPLES, 30, 16), dtype=np.uint16)
# Concentrate energy in lower frequency bins (rows 0-10) where fan/AC noise lives
medium_noise[:, 10:, :] = rng.integers(0, 8, size=(NUM_MEDIUM_NOISE_SAMPLES, 20, 16), dtype=np.uint16)
print(f"  Type 3 - Medium noise (0-25, low-freq): {NUM_MEDIUM_NOISE_SAMPLES} samples")

# Stack all new noise samples
new_noise = np.vstack([silence, low_noise, medium_noise])
print(f"\nTotal new board noise samples: {len(new_noise)}")

# Load existing not-wake-word data
existing_path = NPY_DIR / "not-wake-word.npy"
existing_nww = np.load(existing_path)
print(f"Existing NWW samples: {len(existing_nww)} | dtype: {existing_nww.dtype}")

# Ensure dtypes match
if existing_nww.dtype != np.uint16:
    existing_nww = existing_nww.astype(np.uint16)
    print(f"  Converted existing NWW to uint16")

# Combine
combined = np.vstack([existing_nww, new_noise])
print(f"Combined NWW samples: {len(combined)}")

# Save
np.save(existing_path, combined)
print(f"Saved updated NWW dataset to: {existing_path}")

# Stats
print(f"\nDataset statistics:")
print(f"  Not-wake-word: {len(combined)} samples")
ww = np.load(NPY_DIR / "a_wake-word.npy")
print(f"  Wake-word:     {len(ww)} samples")
print(f"\nBoard noise samples breakdown:")
print(f"  Pure silence (all-zero):  {NUM_SILENCE_SAMPLES}")
print(f"  Low noise (0-8):          {NUM_LOW_NOISE_SAMPLES}")
print(f"  Medium noise (0-25):      {NUM_MEDIUM_NOISE_SAMPLES}")
print(f"\nDone! Now retrain the model.")
