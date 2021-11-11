AxisOrange
===

# Overview
<img src="https://user-images.githubusercontent.com/15327448/141321892-37214815-c0ff-4db5-9817-3dd100d4d2f2.png?raw=true" width="200" />

M5Stack series firmware to send 6DOF sensor(SH200Q or MPU6886) data and quaternion by Bluetooth serial port protocol(SPP).

<img src="https://github.com/naninunenoy/AxisOrange/blob/doc/doc/demo.gif?raw=true" width="200" />

This is demo. M5StickC calucutates and sends quaternion to PC by SPP.
PC receives quaternion via serial port.

# Usage
AxisOrange supports [M5Unified](https://github.com/m5stack/M5Unified) devices. like

 * M5Stack Gray (without MPU9250 model)
 * M5Stack Core2
 * M5StickC
 * M5StickCPlus

## Simple viewer
<img src="https://user-images.githubusercontent.com/15327448/141324212-97e6ac0a-0219-42c3-8227-692bb46485a2.png" width="450" />

This is AxisOrange data viewer by web serial port.

0. Build and write AxisOrange.
1. Paring AxisOrange with your PC.
2. Open `HtmlViewer/index.html`. Reccomend: Google Chrome.
3. Push [list serial device] and select AxisOrange Port. May be named `ESP32SPP`.
4. AxisOrange can calculate and save gyro zero point error. push [gyro-offset install]
5. You can copy raw output of AxisOrange as csv text. 

# Features

## Sensor Data

AxisOrange sends raw value of 6DOF sensor.

* Acc(xyz) [G]
* Gyro(xyz) [deg/s]

## Quaternion

AxisOrange calucutates quaternion by acc/gyro and sends it.

* Quaternion(xyzw)

## Button

AxisOrange sends button A/B(/C) push/release event trigger.

* Button A Push/Release event
* Button B Push/Release event
* Button C Push/Release event (if 3rd button is installed)

## Install
This project use [PlatformIO](https://platformio.org/).

## Library
 * M5Unified and M5GFX
    - https://github.com/m5stack/M5Unified
    - https://github.com/m5stack/M5GFX
    - MIT
 * BluetoothSerial
    - https://github.com/espressif/arduino-esp32/tree/master/libraries/BluetoothSerial
    - http://www.apache.org/licenses/LICENSE-2.0
 * Mahony filter
    - https://x-io.co.uk/open-source-imu-and-ahrs-algorithms/

## License
MIT

## Author
[@naninunenoy](https://github.com/naninunenoy)
