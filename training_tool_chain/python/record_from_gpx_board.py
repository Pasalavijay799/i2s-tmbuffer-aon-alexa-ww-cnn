"""
record_from_gpx_board.py
========================
Python script to record live feature matrices directly from the GPX10PRO board microphone over UART (COM-5).

How to use:
1. Make sure GPX10PRO board is plugged in via USB/UART (COM5).
2. Run this script to record live board microphone data directly into training dataset files!
"""

import sys
import time
import os
import numpy as np
import serial
import serial.tools.list_ports
from pathlib import Path

# Find active COM port
ports = list(serial.tools.list_ports.comports())
default_port = 'COM5'
found_ports = [p.device for p in ports]

print("==================================================================")
print("  RECORD DIRECTLY FROM GPX10PRO BOARD MICROPHONE OVER UART       ")
print("==================================================================")
print(f"Available Serial Ports: {found_ports}")

port_name = default_port
if default_port not in found_ports and len(found_ports) > 0:
    port_name = found_ports[0]

print(f"Connecting to GPX10PRO Board on {port_name} at 9600 baud...")

NPY_DIR = Path("npy-files")
NPY_DIR.mkdir(exist_ok=True)

ww_matrices = []
nww_matrices = []

try:
    ser = serial.Serial(port_name, 9600, timeout=1.0)
    print(f"✅ Connected to {port_name} successfully!")
except Exception as e:
    print(f"❌ Error connecting to {port_name}: {e}")
    print("Please verify board USB cable connection and COM port number.")
    sys.exit(1)

print("\n--- RECORDING INSTRUCTIONS ---")
print("Press 'w' + [ENTER] to record a WAKE-WORD ('HEY MYNAA') sample from board mic.")
print("Press 'n' + [ENTER] to record a NOT-WAKE-WORD (ambient office noise/silence) sample.")
print("Press 'q' + [ENTER] to stop and save dataset.")
print("-------------------------------\n")

buffer = ""
while True:
    try:
        cmd = input("👉 Enter command ('w' = Wake Word, 'n' = Ambient Noise, 'q' = Quit & Save): ").strip().lower()
        if cmd == 'q':
            break
        elif cmd == 'w':
            print("   🎙️ Speak 'HEY MYNAA' into the GPX10PRO board microphone now...")
            start_time = time.time()
            captured = False
            while time.time() - start_time < 3.0:
                line = ser.readline().decode('utf-8', errors='ignore').strip()
                if '[HW_FRAME_START]' in line or len(line) == 960:
                    hex_str = line.replace('[HW_FRAME_START]', '').replace('[HW_FRAME_END]', '').strip()
                    if len(hex_str) >= 960:
                        vals = [int(hex_str[i:i+4], 16) for i in range(0, 960, 4)]
                        arr = np.array(vals, dtype=np.uint16).reshape(30, 16)
                        ww_matrices.append(arr)
                        captured = True
                        print(f"   ✅ Captured Wake-Word matrix from board mic! (Total WW: {len(ww_matrices)})")
                        break
            if not captured:
                print("   ⚠️ No frame captured in 3s window. Speak louder into board mic and try again.")
        elif cmd == 'n':
            print("   🎙️ Capturing ambient office noise from board mic...")
            start_time = time.time()
            captured = False
            while time.time() - start_time < 3.0:
                line = ser.readline().decode('utf-8', errors='ignore').strip()
                if '[HW_FRAME_START]' in line or len(line) == 960:
                    hex_str = line.replace('[HW_FRAME_START]', '').replace('[HW_FRAME_END]', '').strip()
                    if len(hex_str) >= 960:
                        vals = [int(hex_str[i:i+4], 16) for i in range(0, 960, 4)]
                        arr = np.array(vals, dtype=np.uint16).reshape(30, 16)
                        nww_matrices.append(arr)
                        captured = True
                        print(f"   ✅ Captured Ambient Noise matrix from board mic! (Total NWW: {len(nww_matrices)})")
                        break
            if not captured:
                print("   ⚠️ No frame captured in 3s window.")

    except KeyboardInterrupt:
        break

ser.close()

if len(ww_matrices) > 0:
    new_ww = np.array(ww_matrices, dtype=np.uint16)
    ww_path = NPY_DIR / "a_wake-word.npy"
    if ww_path.exists():
        old_ww = np.load(ww_path)
        combined_ww = np.vstack((old_ww, new_ww))
    else:
        combined_ww = new_ww
    np.save(ww_path, combined_ww)
    print(f"🎉 Saved {len(ww_matrices)} board mic wake-word samples to {ww_path}!")

if len(nww_matrices) > 0:
    new_nww = np.array(nww_matrices, dtype=np.uint16)
    nww_path = NPY_DIR / "not-wake-word.npy"
    if nww_path.exists():
        old_nww = np.load(nww_path)
        combined_nww = np.vstack((old_nww, new_nww))
    else:
        combined_nww = new_nww
    np.save(nww_path, combined_nww)
    print(f"🎉 Saved {len(nww_matrices)} board mic ambient noise samples to {nww_path}!")

print("✅ Board microphone data recording session complete.")
