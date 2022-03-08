import serial
import time
from flask import Flask
import atexit

ser = serial.Serial("/dev/ttyUSB0",115200)

#this function should be executed if something goes wrong
def failure():
    ser.write(b"M410\r\n")
    ser.close()
    print("[FAIL]")

atexit.register(failure)
app = Flask(__name__)
#relative mode
ser.write(b"G91\r\n")

@app.route("/button_down/<direction>")
def button_up(direction):
    print(f"[UP] {direction}")
    if direction=="forward":
        ser.write(b"G0 Y10 X0\r\n")
    elif direction=="backward":
        ser.write(b"G0 Y-10 X0\r\n")
    elif direction=="left":
        ser.write(b"G0 X-10 Y0\r\n")
    elif direction=="right":
        ser.write(b"G0 X10 Y0\r\n")
    elif direction=="up":
        ser.write(b"G0 Z10 X0\r\n")
    elif direction=="down":
        ser.write(b"G0 Z-10 X0\r\n")
    else:
        ser.write(b"M410\r\n")
        return "error"
    return "ok"

@app.route("/custom/<command>")
def custom(command):
    print(f"[CUSTOM] {command}")
    command = str(command).replace('%', ' ')
    ser.write(f"{command}\r\n".encode('ascii'))
    return "ok"

@app.route("/stop")
def stop():
    print("[STOP]")
    ser.write(b"M410\r\n")
    return "ok"
