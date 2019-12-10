AxisOrange
===

<img src="https://github.com/naninunenoy/AxisOrange/blob/doc/doc/logo.png?raw=true" width="200" />

M5StickC firmware to send 6DOF sensor(SH200Q or MPU6886) data and quaternion by Bluetooth serial port protocol(SPP).

<img src="https://github.com/naninunenoy/AxisOrange/blob/doc/doc/demo.gif?raw=true" width="200" />

This is demo. M5StickC calucutates and sends quaternion to PC by SPP.
PC receives quaternion via serial port.

# Detail

## Sensor Data

M5StickC sends raw value of 6DOF sensor.

* Acc(xyz) [G]
* Gyro(xyz) [deg/s]

## Quaternion

M5StickC calucutates quaternion by acc/gyro and sends it.

* Quaternion(xyzw)

## Button

M5StickC sends button A/B push/release event trigger.

* Button A Push/Release event
* Button B Push/Release event

## Install
This project use [PlatformIO](https://platformio.org/).

## Library
 * M5StickC
    - https://github.com/m5stack/M5StickC
    - MIT
 * BluetoothSerial
    - https://github.com/espressif/arduino-esp32/tree/master/libraries/
    - http://www.apache.org/licenses/LICENSE-2.0
 * Mahony filter
    - https://x-io.co.uk/open-source-imu-and-ahrs-algorithms/

## License
MIT

## Author
[@naninunenoy](https://github.com/naninunenoy)
