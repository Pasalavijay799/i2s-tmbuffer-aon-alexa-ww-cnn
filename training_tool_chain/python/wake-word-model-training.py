# Sample Model building toolchain for Speech applications (2-Class Wake Word).

print("Model Training in Progress...")

import os
import sys

# Auto-register all pip-installed NVIDIA CUDA DLL directories for TensorFlow GPU support
for root, dirs, files in os.walk(r'C:\AmbientScientific\ambient_env\lib\site-packages\nvidia'):
    if 'bin' in dirs:
        dll_dir = os.path.join(root, 'bin')
        os.environ['PATH'] = dll_dir + os.pathsep + os.environ.get('PATH', '')
        if hasattr(os, 'add_dll_directory'):
            try: os.add_dll_directory(dll_dir)
            except: pass

import warnings
warnings.filterwarnings("ignore")

import numpy as np
import tensorflow as tf
import keras
from keras.models import Sequential
from keras.layers import Dense, Dropout, Flatten, Conv2D, MaxPooling2D
from keras.utils import to_categorical
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix
import itertools

# GPU CONFIGURATION
gpus = tf.config.list_physical_devices('GPU')
if gpus:
    try:
        for gpu in gpus:
            tf.config.experimental.set_memory_growth(gpu, True)
        print(f"GPU(s) detected: {[g.name for g in gpus]}")
        DEVICE = '/GPU:0'
    except Exception as e:
        DEVICE = '/GPU:0'
else:
    print("No GPU detected by TensorFlow. Falling back to CPU.")
    DEVICE = '/CPU:0'

print("TensorFlow will place training ops on:", DEVICE)

DATA_PATH1 = 'npy-files'

def get_labels(path=DATA_PATH1):
    # Class 0 MUST be not-wake-word.npy (obj_id = 0, ignored)
    # Class 1 MUST be a_wake-word.npy (obj_id = 1, triggers KEYWORD DETECTED)
    expected_order = ['not-wake-word.npy', 'a_wake-word.npy']
    labels = [f for f in expected_order if os.path.exists(os.path.join(path, f))]
    labels_indices = np.arange(0, len(labels))
    return labels, labels_indices, to_categorical(labels_indices)

def get_train_test1(split_ratio=0.80, random_state=42):
    labels, indices, _ = get_labels()
    print("Ordered Labels:", labels)
    print("Class 0 (Ignored)  :", labels[0])
    print("Class 1 (Detected) :", labels[1])

    x0 = np.load(os.path.join(DATA_PATH1, labels[0]))  # not-wake-word
    x1 = np.load(os.path.join(DATA_PATH1, labels[1]))  # a_wake-word

    print(f"Total Not-Wake-Word (Class 0): {len(x0)} samples (100% used)")
    print(f"Total Wake-Word (Class 1)    : {len(x1)} samples (100% used)")

    X1 = np.vstack((x0, x1))
    y1 = np.concatenate((np.zeros(len(x0)), np.ones(len(x1))))

    # Exact balanced class weights for NPU logit optimization
    n0, n1 = len(x0), len(x1)
    w0 = (n0 + n1) / (2.0 * n0)
    w1 = (n0 + n1) / (2.0 * n1)
    class_weights = {0: w0, 1: w1}
    print(f"Computed Class Weights -> Class 0: {w0:.3f}, Class 1: {w1:.3f}")

    return train_test_split(X1, y1, test_size=(1 - split_ratio), random_state=random_state, stratify=y1), class_weights

CLASSES_NUM = 2
(X_train, X_test, y_train, y_test), class_weights = get_train_test1()

y_train_hot = to_categorical(y_train, num_classes=CLASSES_NUM)
y_test_hot = to_categorical(y_test, num_classes=CLASSES_NUM)

# NHWC Reshape for Ambient Scientific GPX10PRO Compiler (30, 16, 1)
X_train = X_train.reshape(X_train.shape[0], 30, 16, 1)
X_test = X_test.reshape(X_test.shape[0], 30, 16, 1)

print(f"Train Shape: {X_train.shape}, Test Shape: {X_test.shape}")

with tf.device(DEVICE):
    model = Sequential([
        Conv2D(10, kernel_size=(3, 3), strides=1, padding='same', activation='relu',
               input_shape=(30, 16, 1), data_format='channels_last'),
        MaxPooling2D((2, 2), data_format='channels_last'),

        Conv2D(20, kernel_size=(3, 3), strides=1, padding='same', activation='relu',
               data_format='channels_last'),
        MaxPooling2D((2, 2), data_format='channels_last'),

        Conv2D(30, kernel_size=(3, 3), strides=1, padding='same', activation='relu',
               data_format='channels_last'),
        MaxPooling2D((2, 2), data_format='channels_last'),

        Flatten(),
        Dense(30, activation='relu'),
        Dropout(0.3),
        Dense(CLASSES_NUM, activation='softmax', bias_initializer=tf.keras.initializers.Constant([0, 0]))
    ])

    model.summary()

    model.compile(
        loss='categorical_crossentropy',
        optimizer=keras.optimizers.Adam(learning_rate=0.001),
        metrics=['acc']
    )

    model.fit(
        X_train, y_train_hot,
        batch_size=64,
        epochs=30,
        verbose=1,
        validation_data=(X_test, y_test_hot),
        class_weight=class_weights
    )

model.save("wake-word-model.h5")
model.save("final_try.h5")
print("Models saved successfully: 'wake-word-model.h5' and 'final_try.h5'.")
