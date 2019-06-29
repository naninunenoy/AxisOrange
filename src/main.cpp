#include <M5StickC.h>
#include "inersia/IMUReader.h"

inersia::IMUReader imuReader;
  
void setup() {
  // put your setup code here, to run once:
  M5.begin();
  // M5.IMU.Init();
  imuReader.SetUp((void*)&(M5.Imu));
  M5.Lcd.setRotation(3);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setCursor(40, 0);
  M5.Lcd.println("SH200I TEST");
  M5.Lcd.setCursor(0, 15);
  M5.Lcd.println("  X       Y       Z");
}
  
void loop() {
  imuReader.Update((void*)&(M5.Imu));
  float accX = imuReader.getAccXYZ()[0];
  float accY = imuReader.getAccXYZ()[1];
  float accZ = imuReader.getAccXYZ()[2];
  float gyroX = imuReader.getGyroRPY()[0];
  float gyroY = imuReader.getGyroRPY()[1];
  float gyroZ = imuReader.getGyroRPY()[2];
 
  M5.Lcd.setCursor(0, 24);
  M5.Lcd.printf("%+7.2f %+7.2f %+7.2f\n", accX, accY, accZ);
  M5.Lcd.setCursor(0, 36);
  M5.Lcd.printf("%+7.2f %+7.2f %+7.2f\n", gyroX, gyroY, gyroZ);

  M5.update();
}