# # Feature Extraction

print("Feature Extraction is in progress...")

import warnings

# Suppress DeprecationWarnings related to NumPy conversion of out-of-bound integers
warnings.filterwarnings("ignore", category=DeprecationWarning, message=".*NumPy will stop allowing conversion.*")

# Suppress RuntimeWarnings related to division by zero
warnings.filterwarnings("ignore", category=RuntimeWarning, message=".*divide by zero encountered in divide.*")
from keras.utils import to_categorical
import numpy as np
from tqdm import tqdm
import os
import wavio
import shutil
import numpy as np
np.set_printoptions(threshold=np.inf)
np.set_printoptions(suppress=True)


# ### Custom Data Preprocessing function (FFT, MelScale)
# ### User can define their own preprocessing steps

# create directory to story .npy files
try:
    shutil.rmtree('npy-files')
except:
    pass
os.mkdir('npy-files')

#Divide 1 second sample into of 32 milli seconds part
def chop_array(arr, window_size, hop_size):
    """chop_array([1,2,3], 2, 1) -> [[1,2], [2,3]]"""
    return [arr[i - window_size:i] for i in range(window_size, len(arr) + 1, hop_size)]

#Perform Log2
def safe_log(x):
    """Prevents error on log(0) or log(-1)"""
    return np.log2(x)#(np.clip(x, (np.finfo(np.float16).eps), None))

#Create filterbanks
def filterbanks(sample_rate, num_filt, fft_len):
    """Makes a set of triangle filters focused on {num_filter} mel-spaced frequencies"""
    def hertz_to_mels(f):
        return 1127. * np.log(1. + f / 700.)

    def mel_to_hertz(mel):
        return 700. * (np.exp(mel / 1127.) - 1.)

    def correct_grid(x):
        """Push forward duplicate points to prevent useless filters"""
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

# High-speed WAV loader using Python built-in wave module
import wave as wave_module

def wav2feature(file_path):
    try:
        with wave_module.open(file_path, 'rb') as wf:
            raw = wf.readframes(wf.getnframes())
            data = np.frombuffer(raw, dtype=np.int16)
        if len(data) < 7680:
            data = np.pad(data, (0, 7680 - len(data)), mode='constant')
        elif len(data) > 7680:
            data = data[:7680]
        return frames2feature(data)
    except Exception:
        return frames2feature(np.zeros(7680, dtype=np.int16))

# Global filterbanks matrix pre-computed once for maximum performance
GLOBAL_FBANKS = filterbanks(8000, 16, 256)
GLOBAL_INTFLTRS_T = (GLOBAL_FBANKS * 32).round().astype(np.int32).T

# Convert each frame of wav files to feature
def frames2feature(audio):
    a = []
    frames = chop_array(audio, 256, 256)
    for x in range(0, len(frames[:30])):
        frames1 = np.short(frames[x])
        fft = np.fft.fft(frames1)
        fft_real = np.int32(fft.real) >> 7
        fft_short = np.short(fft_real)

        sqr = (fft_short.astype(np.int32) ** 2) >> 8
        sqr[sqr >= 32768] = 32767

        mels = (np.dot(sqr, GLOBAL_INTFLTRS_T)) & 0xFFFF
        features = np.array(safe_log(mels), dtype=np.int16)
        a.append(features)
    return a


# ### Custom Data Preprocessing function calls

#Get the labels
def get_labels(path):
    labels = os.listdir(path)
#     print(labels)
    labels_indices = np.arange(0, len(labels))
    return labels, labels_indices, to_categorical(labels_indices)

from concurrent.futures import ThreadPoolExecutor

#Save the data in array
def save_data_to_array(path, folder):
    labels, _, _ = get_labels(path)
    for label in labels:
        wavfiles = [os.path.join(path, label, f) for f in os.listdir(os.path.join(path, label))]
        print(f"Extracting features for '{label}' ({len(wavfiles):,} files) using 16 parallel threads...")
        with ThreadPoolExecutor(max_workers=16) as executor:
            feature_vectors = list(tqdm(executor.map(wav2feature, wavfiles), total=len(wavfiles)))
        np.save(os.path.join(folder, label + '.npy'), feature_vectors)


# ### Create .NPY files and store features for training

save_data_to_array('dataset/', 'npy-files/')

print("Feature Extraction is Completed. Find the files in npy-files folder")



