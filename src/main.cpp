#include <M5StickC.h>

int16_t accX = 0;
int16_t accY = 0;
int16_t accZ = 0;

int16_t gyroX = 0;
int16_t gyroY = 0;
int16_t gyroZ = 0;

void setup() {
  M5.begin();
  M5.IMU.Init();
  Serial.begin(115200);
}

void loop() {
  M5.IMU.getGyroData(&gyroX,&gyroY,&gyroZ);
  M5.IMU.getAccelData(&accX,&accY,&accZ);
  
  Serial.printf("g= ( 0x%04X 0x%04X 0x%04X ), a= ( 0x%04X 0x%04X 0x%04X )\n", 
    ((uint16_t) gyroX), ((uint16_t) gyroY), ((uint16_t) gyroZ),
    ((uint16_t) accX), ((uint16_t) accY), ((uint16_t) accZ));
  delay(1000);
}
