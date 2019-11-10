#include <M5StickC.h>
#include "imu/ImuReader.h"
#include "BluetoothSerial.h"

#define TASK_DEFAULT_CORE_ID 1
#define TASK_STACK_DEPTH 4096UL
#define TASK_NAME_IMU "IMUTask"
#define TASK_NAME_SESSION "SessionTask"
#define TASK_SLEEP_IMU 5 // = 1000[ms] / 200[Hz]
#define TASK_SLEEP_SESSION 40 // = 1000[ms] / 25[Hz]
#define MUTEX_DEFAULT_WAIT 1000UL

static void ImuLoop(void* arg);
static void SessionLoop(void* arg);

imu::ImuReader* imuReader;
imu::ImuData imuData;
const float offsetGyroX = -1.76546F;
const float offsetGyroY = -6.8906F;
const float offsetGyroZ = 14.59196F;
static SemaphoreHandle_t imuDataMutex = NULL;
BluetoothSerial btSpp;

void setup() {
  M5.begin();
  // imu
  imuReader = new imu::ImuReader(M5.Imu);
  imuReader->initialize();
  imuReader->writeGyroOffset(offsetGyroX, offsetGyroY, offsetGyroZ);
  // lcd
  M5.Lcd.setRotation(3);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setCursor(40, 0);
  M5.Lcd.println("IMU TEST");
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.println("  X       Y       Z");
  M5.Lcd.setCursor(0, 50);
  M5.Lcd.println("  Quaternion(WXYZ)");
  // bluetooth serial
  btSpp.begin("AxisOrange");
  // task
  imuDataMutex = xSemaphoreCreateMutex();
  xTaskCreatePinnedToCore(ImuLoop, TASK_NAME_IMU, TASK_STACK_DEPTH, NULL, 2, NULL, TASK_DEFAULT_CORE_ID);
  xTaskCreatePinnedToCore(SessionLoop, TASK_NAME_SESSION, TASK_STACK_DEPTH, NULL, 1, NULL, TASK_DEFAULT_CORE_ID);
}

void loop() { /* Do Nothing */ }

static void ImuLoop(void* arg) {
  while (1) {
    uint32_t entryTime = millis();
    xSemaphoreGive(imuDataMutex);
      if (xSemaphoreTake(imuDataMutex, MUTEX_DEFAULT_WAIT) == pdTRUE) {
        imuReader->update();
        imuReader->read(imuData);
      }
      xSemaphoreGive(imuDataMutex);
    // idle
    int32_t sleep = TASK_SLEEP_IMU - (millis() - entryTime);
    vTaskDelay((sleep > 0) ? sleep : 0);
  }
}

static void SessionLoop(void* arg) {
  while (1) {
    uint32_t entryTime = millis();
    xSemaphoreGive(imuDataMutex);
      if (xSemaphoreTake(imuDataMutex, MUTEX_DEFAULT_WAIT) == pdTRUE) {
        float* a = imuData.acc;
        float* g = imuData.gyro;
        float* q = imuData.quat;
        // lcd
        M5.Lcd.setCursor(0, 20);
        M5.Lcd.printf("%6.2f  %6.2f  %6.2f      ", g[0], g[1], g[2]);
        M5.Lcd.setCursor(140, 20);
        M5.Lcd.print("o/s");
        M5.Lcd.setCursor(0, 30);
        M5.Lcd.printf(" %5.2f   %5.2f   %5.2f   ",  a[0], a[1], a[2]);
        M5.Lcd.setCursor(140, 30);
        M5.Lcd.print("G");
        M5.Lcd.setCursor(0, 60);
        M5.Lcd.printf(" %4.2f  %4.2f  %4.2f  %4.2f", q[0], q[1], q[2], q[3]);
        // bluetooth
        btSpp.printf("%f,%f,%f,%f\r\n", q[0], q[1], q[2], q[3]);
      }
      xSemaphoreGive(imuDataMutex);
    // idle
    int32_t sleep = TASK_SLEEP_SESSION - (millis() - entryTime);
    vTaskDelay((sleep > 0) ? sleep : 0);
  }
}
