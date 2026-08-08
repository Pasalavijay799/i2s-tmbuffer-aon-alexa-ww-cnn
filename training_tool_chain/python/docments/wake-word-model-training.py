# Sample Model building toolchain for Speech applications.

# Import TF/Keras Libraries
print("Model Training in Progress")

# import required libraries
import os
import sys

# Register pip-installed NVIDIA CUDA DLLs if present
for pkg_name in ['nvidia.cuda_runtime', 'nvidia.cublas', 'nvidia.cudnn', 'nvidia.cusolver', 'nvidia.cusparse']:
    try:
        mod = __import__(pkg_name, fromlist=['*'])
        dll_dir = os.path.join(os.path.dirname(mod.__file__), 'bin')
        if os.path.isdir(dll_dir):
            os.environ['PATH'] = dll_dir + os.pathsep + os.environ.get('PATH', '')
            if hasattr(os, 'add_dll_directory'):
                os.add_dll_directory(dll_dir)
    except Exception:
        pass

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

import warnings
warnings.filterwarnings("ignore", message=r"Passing", category=FutureWarning)
from keras.utils import to_categorical
import numpy as np
from tqdm import tqdm
import os
import wavio
import shutil
import keras
from keras.models import Sequential
from keras.layers import Dense, Dropout, Flatten, Conv2D, MaxPooling2D
from keras.utils import to_categorical, plot_model
from keras.callbacks import ModelCheckpoint
import matplotlib.pyplot as plt
from keras.optimizers import RMSprop, SGD, Adam
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, confusion_matrix
from sklearn.utils.class_weight import compute_class_weight
import itertools
import tensorflow as tf
from keras import layers, models

# --------------------------------------------------------------------------
# GPU CONFIGURATION — detect the GPU, enable memory growth, and pick the
# device that training/inference ops will run on.
# --------------------------------------------------------------------------
gpus = tf.config.list_physical_devices('GPU')
if gpus:
    try:
        # Prevent TF from grabbing all GPU memory up front — avoids OOM
        # crashes when other processes also need the GPU.
        for gpu in gpus:
            tf.config.experimental.set_memory_growth(gpu, True)
        print(f"GPU(s) detected: {[g.name for g in gpus]}")
        DEVICE = '/GPU:0'
    except RuntimeError as e:
        # set_memory_growth must be called before GPUs are initialized;
        # if TF already initialized them this will raise — training will
        # still use GPU, this just means the memory-growth setting didn't apply.
        print(f"Could not set memory growth (device already initialized): {e}")
        DEVICE = '/GPU:0'
else:
    print("No GPU detected by TensorFlow. Falling back to CPU.")
    print("If you expect a GPU here, check: (1) you installed 'tensorflow' "
          "with GPU support (not tensorflow-cpu), (2) NVIDIA driver is "
          "installed, (3) CUDA/cuDNN versions match your TF version, "
          "(4) `nvidia-smi` shows the GPU on this machine.")
    DEVICE = '/CPU:0'

print("TensorFlow will place training ops on:", DEVICE)
print("Built with CUDA support:", tf.test.is_built_with_cuda())

# Specify Data Path
train_path = 'dataset/'  # provide path of your data. Source could be either on your local machine or internet

DATA_PATH1 = 'npy-files/'


# Get data labels for trainset (Class 0 = not-wake-word.npy, Class 1 = a_wake-word.npy matching C firmware obj_id == 1)
def get_labels(path=DATA_PATH1):
    expected_order = ['not-wake-word.npy', 'a_wake-word.npy']
    labels = [f for f in expected_order if os.path.exists(os.path.join(path, f))]
    for f in sorted(os.listdir(path)):
        if f.endswith('.npy') and f not in labels:
            labels.append(f)
    labels_indices = np.arange(0, len(labels))
    return labels, labels_indices, to_categorical(labels_indices)


# Train test split on data (1:1 balanced sampling matching Alexa working model profile)
def get_train_test1(split_ratio=0.80, random_state=42):
    labels, indices, _ = get_labels()
    print("Labels:", labels)
    print("Indices:", indices)
    
    x0 = np.load(DATA_PATH1 + '/' + labels[0])  # not-wake-word
    x1 = np.load(DATA_PATH1 + '/' + labels[1])  # a_wake-word
    
    min_len = min(len(x0), len(x1))
    print(f"Balancing dataset 1:1 -> using exactly {min_len} samples per class")
    
    np.random.seed(random_state)
    idx0 = np.random.choice(len(x0), min_len, replace=False)
    idx1 = np.random.choice(len(x1), min_len, replace=False)
    
    X1 = np.vstack((x0[idx0], x1[idx1]))
    y1 = np.concatenate((np.zeros(min_len), np.ones(min_len)))
    
    assert X1.shape[0] == len(y1)
    return train_test_split(X1, y1, test_size=(1 - split_ratio), random_state=random_state, stratify=y1)


# check the size and classes of data
CLASSES_NUM = 2  # 2 classes: wake-word and not-wake-word
X_train, X_test, y_train, y_test = get_train_test1()

# One hot encoding
y_train_hot = to_categorical(y_train, num_classes=CLASSES_NUM)
y_test_hot = to_categorical(y_test, num_classes=CLASSES_NUM)

# Reshape the input data
X_train = X_train.reshape(X_train.shape[0], 1, 30, 16)
X_test = X_test.reshape(X_test.shape[0], 1, 30, 16)

print(X_train.shape, y_train_hot.shape, X_test.shape, y_test_hot.shape)

with tf.device(DEVICE):
    # Define the model
    model = Sequential()
    model.add(Conv2D(10, kernel_size=(3, 3), strides=1, padding='same', activation='relu',
                      input_shape=(1, 30, 16), data_format='channels_first'))
    model.add(MaxPooling2D((2, 2), data_format='channels_first'))
    model.add(Conv2D(20, kernel_size=(3, 3), strides=1, padding='same', activation='relu',
                      data_format='channels_first'))
    model.add(MaxPooling2D((2, 2), data_format='channels_first'))
    model.add(Conv2D(30, kernel_size=(3, 3), strides=1, padding='same', activation='relu',
                      data_format='channels_first'))
    model.add(MaxPooling2D((2, 2), data_format='channels_first'))
    model.add(Flatten())
    model.add(Dense(30, activation='relu'))
    model.add(Dropout(0.3))
    model.add(Dense(CLASSES_NUM, activation='softmax', bias_initializer='zeros'))
    model.summary()

    # Model compile
    model.compile(loss=keras.losses.categorical_crossentropy, optimizer=keras.optimizers.Adam(learning_rate=0.001), metrics=['acc'])

    # Model Fit on 1:1 balanced data
    model.fit(X_train, y_train_hot, batch_size=32, epochs=20, verbose=1,
              validation_data=(X_test, y_test_hot))

# User can have its own name to save the model
model.save("wake-word-model.h5")
model.save("final_try.h5")

# Load keras model
model = models.load_model('wake-word-model.h5')

# Predict the model
np.set_printoptions(threshold=np.inf)
np.set_printoptions(suppress=True)
with tf.device(DEVICE):
    preds_valid = model.predict(X_test)

from sklearn.metrics import classification_report, confusion_matrix
cf_valid = confusion_matrix(y_test_hot.argmax(axis=1), preds_valid.argmax(axis=1))


# Confusion Matrix
def plot_confusion_matrix(cm, target_names, title='Confusion matrix', cmap=None, normalize=True):
    accuracy = np.trace(cm) / float(np.sum(cm))
    misclass = 1 - accuracy

    if cmap is None:
        cmap = plt.get_cmap('Blues')

    plt.figure(figsize=(15, 5))
    plt.imshow(cm, interpolation='nearest', cmap=cmap)
    plt.title(title)
    plt.colorbar()

    if target_names is not None:
        tick_marks = np.arange(len(target_names))
        plt.xticks(tick_marks, target_names, rotation=45, fontsize=10)
        plt.yticks(tick_marks, target_names, fontsize=10)

    if normalize:
        cm = cm.astype('float') / cm.sum(axis=1)[:, np.newaxis]

    thresh = cm.max() / 1.5 if normalize else cm.max() / 2
    for i, j in itertools.product(range(cm.shape[0]), range(cm.shape[1])):
        if normalize:
            plt.text(j, i, "{:0.4f}".format(cm[i, j]), fontsize=10,
                      horizontalalignment="center",
                      color="white" if cm[i, j] > thresh else "black")
        else:
            plt.text(j, i, "{:,}".format(cm[i, j]), fontsize=10,
                      horizontalalignment="center",
                      color="white" if cm[i, j] > thresh else "black")

    plt.tight_layout()
    plt.ylabel('True label')
    plt.xlabel('Predicted label\naccuracy={:0.4f}; misclass={:0.4f}'.format(accuracy, misclass))
    plt.savefig('confusion_matrix_float.png')
    plt.close()


target_names = ['not-wake-word', 'wake-word']
plot_confusion_matrix(cm=cf_valid, normalize=False,
                       target_names=['not-wake-word.npy', 'wake-word.npy'])

# --------------------------------------------------------------------------
# Quantize the model to INT8 and save in TFlite.
# NOTE: The TFLite interpreter below runs on CPU. TFLite's GPU delegate does
# not support full-integer (uint8) quantized inference, so this is expected
# to be CPU-only even with a GPU present — that's standard for edge/embedded
# deployment targets (that's the whole point of quantizing to int8).
# --------------------------------------------------------------------------
X_test = np.float32(np.array(X_test))


def representative_dataset():
    for data in tf.data.Dataset.from_tensor_slices(X_test).batch(1).take(100):
        yield [data]


converter = tf.lite.TFLiteConverter.from_keras_model(model)
converter.optimizations = [tf.lite.Optimize.DEFAULT]
converter.target_spec.supported_types = [tf.int8]
converter.inference_input_type = tf.uint8
converter.inference_output_type = tf.uint8
converter.representative_dataset = representative_dataset
tflite_model_quantized = converter.convert()

tflite_model_quantized_name = "wake-word-model-quantized.tflite"
with open(tflite_model_quantized_name, "wb") as f:
    f.write(tflite_model_quantized)

interpreter = tf.lite.Interpreter(model_path=tflite_model_quantized_name)
interpreter.allocate_tensors()

input_index = interpreter.get_input_details()[0]['index']
output_index = interpreter.get_output_details()[0]['index']


def evaluate_tflite_model(interpreter, X_test):
    predictions = []
    input_details = interpreter.get_input_details()[0]
    output_details = interpreter.get_output_details()[0]
    scale, zero_point = input_details['quantization']
    input_index = input_details['index']
    output_index = output_details['index']

    for x in X_test:
        if scale > 0:
            qx = np.round(x / scale + zero_point).astype(np.uint8)
        else:
            qx = x.astype(np.uint8)
        if qx.ndim == 3:
            qx = np.expand_dims(qx, axis=0)
        interpreter.set_tensor(input_index, qx)
        interpreter.invoke()
        output = interpreter.get_tensor(output_index)
        predictions.append(output.argmax())
    return np.array(predictions)


predictions = evaluate_tflite_model(interpreter, X_test)

accuracy = accuracy_score(y_test, predictions)
print("TFLite model accuracy:", accuracy)

cm = confusion_matrix(y_test, predictions)

class_labels = ['not-wake-word', 'wake-word']

plt.figure(figsize=(6, 6))
plt.imshow(cm, interpolation='nearest', cmap=plt.cm.Blues)
plt.title('Confusion matrix')
plt.colorbar()
tick_marks = np.arange(len(class_labels))
plt.xticks(tick_marks, class_labels, rotation=45)
plt.yticks(tick_marks, class_labels)

fmt = 'd'
thresh = cm.max() / 2.
for i, j in itertools.product(range(cm.shape[0]), range(cm.shape[1])):
    plt.text(j, i, format(cm[i, j], fmt),
              horizontalalignment="center",
              color="white" if cm[i, j] > thresh else "black")

plt.tight_layout()
plt.ylabel('True label')
plt.xlabel('Predicted label')
plt.savefig('confusion_matrix_tflite.png')
plt.close()

print("Model Training is Completed.")
# # End