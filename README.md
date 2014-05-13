# Shotgun Kitty

Opensource quadcopter flight controller based about the Adafruit 9-DOF IMU
Breakout Board and Arduino Mega 2560. This is mainly to prove to myself that I
can do it, and it probably wont be maintained.

## Pin Definitions

### RC Pins

Pin 2 - RC Throttle  
Pin 3 - RC Aileron  
Pin 4 - RC Elevator  
Pin 5 - RC Rudder  
Pin 6 - Flight Mode  

### Motor Pins

Pin 7   - Motor 1 (Front Right Motor - Counter Clockwise - Normal Propeller)  
Pin 8   - Motor 2 (Bottom Left Motor - Counter Clockwise - Normal Propeller)  
Pin 9   - Motor 3 (Front Left Motor - Clockwise - Pusher Propeller)  
Pin 10  - Motor 4 (Back right Motor - Clockwise - Pusher Propeller)  

## Building and Verifying the Project

You must use a version of the Arduino IDE >= 1.5.

Shotgun Kitty uses rake to facilitate easy building and verifying. There is an
rvmrc that specifies the ruby version (but honestly currently any ruby version
will do) The Rakefile parses a YAML file at config/arduino.yml this file should
look something like this:

```
arduino:
  executable: "/Applications/Arduino.app/Contents/MacOS/JavaApplicationStub"
```

Note that for OS X the executable is actually inside of the application bundle.
Currently you must first load up the arduino environent, choose all your board
and port options, then quit the application to save the defaults.

Verifying the shotgun kitty code is now as easy as typing:

```
rake
```

or 

```
rake verify
```

To build the application and upload to the board type:

```
rake upload
```
