#include <M5StickC.h>
#include "inersia/IMUReader.h"

inersia::IMUReader imuReader;

void setup() {
  M5.begin();
  M5.Lcd.fillScreen(BLACK);

  // IMU setup
  imuReader.SetUp((void*)&M5.Imu);

  // text print
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(1);
  M5.Lcd.printf("SH200Q Test!");

}

void loop(){
  // IMU update
  imuReader.Update((void*)&M5.Imu);
  
}