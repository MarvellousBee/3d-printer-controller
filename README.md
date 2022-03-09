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
* A server you run on a Raspberry Pi and connect to your printer
* GUI app you interact with

So, things you'll need:
* FDM 3D printer
* Linux-based Raspberry Pi (for ex. 4B)
* PC (Windows works, Linux *should* work, no idea about Mac)
* A local network, which manages the RPI and PC (Directly connecting through an Ethernet cable should also work).
* Any USB cable that can connect your RPI to your 3D printer
### Raspberry Pi Installation
* Connect your RPI to your 3D printer via USB.
* On the RPI, install Flask (run `pip install flask`).
* Copy `print_server.py` to your RPI.
* Navigate your terminal to that directory.
* Run `export FLASK_APP=print_server`.
* Run `flask run --host=0.0.0.0`.
### GUI app installation
* switch back to your PC
* get [curl](https://github.com/curl/curl)
* Everything inside `desktop-app` is a raw Qt creator project. Import it there.
* Put your RPI's local IP inside `put_your_local_ip_here.txt`.
* Build and run your project!

You should be able to send commands now!
