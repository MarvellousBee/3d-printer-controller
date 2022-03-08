# 3d-printer-controller
Control your printer remotely with a Raspberry Pi!


![](preview.gif)

## IMPORTANT
* Using the app makes your printer use relative mode (G91). This means a "Move to x" order will be interpreted as "Move by x". For example, "G0 X10" will "MOVE BY 10", NOT "MOVE TO 10"
* For safety, make sure you've enabled ``EMERGENCY_PARSER`` in your printer's configuration! Otherwise, "STOP" won't work. You can still use every other feature though.
* Hitting endstops WILL NOT stop the printer!
* This is a prototype. Use at your own risk!
## Installation
There are 2 components of this app:
* GUI app you interact with
* A server you run on a Raspberry Pi and connect to your printer

### Raspberry Pi Installation
* Connect your RPI to your 3D printer via USB.
* Install Flask (run `pip install flask`).
* Copy `print_server.py` to your RPI.
* Navigate your terminal to that window.
* Run `export FLASK_APP=print_server`.
* Run `flask run --host=0.0.0.0`.
### GUI app installation
* Everything inside `desktop-app` is a raw Qt creator project. Import it there.
* Put your local IP inside`put_your_local_ip_here.txt`.
* Build and run your project!

You should be able to send commands now!
