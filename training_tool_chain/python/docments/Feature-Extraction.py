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

#Create features from wav file
def wav2feature(file_path):
    #print(file_path)
    wave = wavio.read(file_path)
    wave = np.squeeze(wave.data)
    if len(wave) < 7680:
        wave = np.pad(wave, pad_width=(0, 7680-len(wave)), mode='constant')
    elif len(wave) > 7680:
        wave = wave[-7680:]


    return frames2feature(wave)

#Convert each frame of wav files to feature
def frames2feature(audio):
    a=[]
    frames = chop_array(audio, 256, 256)
    frames = np.short(frames) 
#     print(frames)
    for x in range(0, (len(frames))):
        frames1 = np.short(frames[x])
        fft = np.fft.fft(frames1)
        fft = np.array(np.int32(fft.real))
        fft = fft>>7
        fft = np.short(fft)

        sqr = (fft.astype("int32")**2)
        sqr = sqr>>8
        sqr[sqr >= 32768] =  32767
        filters = filterbanks(8000, 16, 256)
        
        intfltrs = np.array(filters*32)
        intfltrs = intfltrs.round()
        intfltrs = intfltrs.astype("int8")

        mels = np.array(np.dot(sqr.astype("int32"), intfltrs.T.astype("int32")))
        mels = (mels & 0xffff)
        features = np.array((safe_log(mels)), dtype=np.int16) 
        a.append(features)
#         print(a)
  
    return a


# ### Custom Data Preprocessing function calls

#Get the labels
def get_labels(path):
    labels = os.listdir(path)
#     print(labels)
    labels_indices = np.arange(0, len(labels))
    return labels, labels_indices, to_categorical(labels_indices)

#Save the data in array
def save_data_to_array(path, folder):
    labels, _, _ = get_labels(path)
    for label in labels:
        feature_vectors = []
        wavfiles = [path + label + '/' + wavfile for wavfile in os.listdir(path + '/' + label)]
        for wavfile in tqdm(wavfiles):
            features = wav2feature(wavfile)
            feature_vectors.append(features)
        #print(feature_vectors)
        np.save(folder + '/' + label + '.npy', feature_vectors)


# ### Create .NPY files and store features for training

save_data_to_array('dataset/', 'npy-files/')

print("Feature Extraction is Completed. Find the files in npy-files folder")



