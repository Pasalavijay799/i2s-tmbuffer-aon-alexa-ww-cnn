import os
import sys
import time

# Auto-register all pip-installed NVIDIA CUDA DLL directories for TensorFlow GPU support
for root, dirs, files in os.walk(r'C:\AmbientScientific\ambient_env\lib\site-packages\nvidia'):
    if 'bin' in dirs:
        dll_dir = os.path.join(root, 'bin')
        os.environ['PATH'] = dll_dir + os.pathsep + os.environ.get('PATH', '')
        if hasattr(os, 'add_dll_directory'):
            try:
                os.add_dll_directory(dll_dir)
            except Exception:
                pass

import numpy as np
import tensorflow as tf
import sounddevice as sd

# Force GPU placement if available
gpus = tf.config.list_physical_devices('GPU')
if gpus:
    DEVICE = '/GPU:0'
    print(f"GPU Detected: {gpus[0].name}")
else:
    DEVICE = '/CPU:0'
    print("Running on CPU mode.")

# Load trained model (final_try.h5, new_model.h5, or wake-word-model.h5)
MODEL_PATH = 'final_try.h5'

print("==================================================================")
print("     LIVE VOICE WAKE-WORD DEMO (MYNAA) - LOCAL PC")
print("==================================================================")
print(f"Loading Model: {MODEL_PATH} ...")
model = tf.keras.models.load_model(MODEL_PATH)
print("Model Loaded Successfully!\n")

SAMPLE_RATE = 8000
CHUNK_SAMPLES = 7680  # 30 frames * 256 samples

def chop_array(arr, window_size, hop_size):
    return [arr[i - window_size:i] for i in range(window_size, len(arr) + 1, hop_size)]

def safe_log(x):
    x = np.clip(x, 1, None)
    return np.log2(x)

def filterbanks(sample_rate=8000, num_filt=16, fft_len=256):
    def hertz_to_mels(f):
        return 1127. * np.log(1. + f / 700.)

    def mel_to_hertz(mel):
        return 700. * (np.exp(mel / 1127.) - 1.)

    def correct_grid(x):
        offset = 0
        for prev, i in zip([x[0] - 1] + x, x):
            offset = max(0, offset + prev + 1 - i)
            yield i + offset

    grid_mels = np.linspace(hertz_to_mels(0), hertz_to_mels(sample_rate), num_filt + 2, True)
    grid_hertz = mel_to_hertz(grid_mels)
    grid_indices = (grid_hertz * fft_len / sample_rate).astype(int)
    grid_indices = list(correct_grid(grid_indices))

    banks = np.zeros([num_filt, fft_len])
    for i, (left, middle, right) in enumerate(chop_array(grid_indices, 3, 1)):
        banks[i, left:middle] = np.linspace(0., 1., middle - left, False)
        banks[i, middle:right] = np.linspace(1., 0., right - middle, False)
    return banks

FBANKS = filterbanks(SAMPLE_RATE, 16, 256)
INTFLTRS = np.array(FBANKS * 32).round().astype("int8")
INTFLTRS_T = INTFLTRS.T.astype(np.int32)

def frames2feature(signal):
    """EXACT 100% math matching Ambient Scientific Feature-Extraction.py."""
    frames = chop_array(signal, 256, 256)
    features_out = []

    for frame in frames[:30]:
        fft = np.fft.fft(frame.astype(np.int16))
        fft_real = np.int32(fft.real) >> 7
        fft_short = np.int16(np.clip(fft_real, -32768, 32767))

        sqr = (fft_short.astype(np.int32) ** 2) >> 8
        sqr[sqr >= 32768] = 32767

        mels = (np.dot(sqr, INTFLTRS_T)) & 0xFFFF
        log_mels = np.log2(np.maximum(mels, 1)).astype(np.int16)

        features_out.append(log_mels)

    return np.array(features_out, dtype=np.float32).reshape(1, 1, 30, 16)

print("------------------------------------------------------------------")
print("Microphone Active! Testing on Local PC.")
print("Speak 'MYNAA' into your microphone.")
print("   Other words ('hello', 'hi', 'where are you') will be ignored.")
print("   Press Ctrl+C to exit.")
print("------------------------------------------------------------------\n")

try:
    with sd.InputStream(samplerate=SAMPLE_RATE, channels=1, dtype='int16') as stream:
        buffer = np.zeros(0, dtype=np.int16)
        cooldown = 0
        consecutive_detections = 0
        CONFIDENCE_THRESHOLD = 0.55  # 55% confidence threshold
        ENERGY_THRESHOLD     = 0     # 0 threshold so all mic gains work
        CONSECUTIVE_NEEDED   = 1     # Trigger immediately on detection
        COOLDOWN_CHUNKS      = 4     # ~1 second cooldown between triggers

        while True:
            audio_chunk, _ = stream.read(2048)
            buffer = np.append(buffer, audio_chunk.flatten())

            if len(buffer) >= CHUNK_SAMPLES:
                current_audio = buffer[-CHUNK_SAMPLES:]
                features = frames2feature(current_audio)

                with tf.device(DEVICE):
                    preds = model(features, training=False).numpy()[0]

                prob_nww = preds[0] # Class 0 = Silence / Noise (not-wake-word.npy)
                prob_ww  = preds[1] # Class 1 = Hey Mynaa Wake Word (a_wake-word.npy, matches C firmware obj_id==1)
                rms = np.sqrt(np.mean(current_audio.astype(np.float32) ** 2))

                if cooldown > 0:
                    cooldown -= 1
                    consecutive_detections = 0

                elif np.argmax(preds) == 1 and prob_ww > CONFIDENCE_THRESHOLD and rms > ENERGY_THRESHOLD:
                    consecutive_detections += 1
                    if consecutive_detections >= CONSECUTIVE_NEEDED:
                        print(f"\n\n==========================================================")
                        print(f" KEYWORD DETECTED: 'MYNAA' | Confidence: {prob_ww * 100:.1f}% | Energy: {int(rms)}")
                        print(f"==========================================================\n")
                        cooldown = COOLDOWN_CHUNKS
                        consecutive_detections = 0
                    else:
                        print(f"\r... Candidate ({consecutive_detections}/{CONSECUTIVE_NEEDED}) | Conf: {prob_ww*100:.1f}% | Energy: {int(rms)}      ", end='', flush=True)
                else:
                    consecutive_detections = 0
                    print(f"\r... Listening | Conf: {prob_nww*100:.1f}% WW:{prob_ww*100:.1f}% | Energy: {int(rms)}      ", end='', flush=True)

                buffer = buffer[2048:]
except KeyboardInterrupt:
    print("\n\nLive voice demo stopped.")
