#include <M5StickC.h>
#include "imu/IMUReader.h"

imu::IMUReader* imuReader;

void setup() {
  M5.begin();
  imuReader = new imu::IMUReader(M5.Imu);
  M5.Lcd.fillScreen(BLACK);
  // text print
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(1);
  M5.Lcd.printf("SH200Q Test!");

}

void loop(){

}