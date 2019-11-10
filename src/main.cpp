#include <M5StickC.h>
#include "imu/ImuReader.h"

imu::ImuReader imuReader;
imu::ImuData imuData;
const float offsetGyroX = -1.76546F;
const float offsetGyroY = -6.8906F;
const float offsetGyroZ = 14.59196F;

void setup() {
  // put your setup code here, to run once:
  M5.begin();
  // imu
  imuReader.initialize();
  imuReader.writeGyroOffset(offsetGyroX, offsetGyroY, offsetGyroZ);
  // lcd
  M5.Lcd.setRotation(3);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setCursor(40, 0);
  M5.Lcd.println("IMU TEST");
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.println("  X       Y       Z");
  M5.Lcd.setCursor(0, 50);
  M5.Lcd.println("  Pitch   Roll    Yaw");
  // serial
  Serial.begin(115200);
}

void loop() {
  imuReader.update();
  if (imuReader.read(imuData)) {
    Serial.printf("%f, %f, %f %f\n", 
      imuData.quat[0], imuData.quat[1], imuData.quat[2], imuData.quat[3]);

    M5.Lcd.setCursor(0, 20);
    M5.Lcd.printf("%6.2f  %6.2f  %6.2f      ", 
      imuData.gyro[0], imuData.gyro[1], imuData.gyro[2]);
    M5.Lcd.setCursor(140, 20);
    M5.Lcd.print("o/s");
    M5.Lcd.setCursor(0, 30);
    M5.Lcd.printf(" %5.2f   %5.2f   %5.2f   ", 
      imuData.acc[0], imuData.acc[1], imuData.acc[2]);
    M5.Lcd.setCursor(140, 30);
    M5.Lcd.print("G");
    M5.Lcd.setCursor(0, 60);
    M5.Lcd.printf(" %4.2f  %4.2f  %4.2f  %4.2f", 
      imuData.quat[0], imuData.quat[1], imuData.quat[2], imuData.quat[3]);
  }
  delay(1000);
}
