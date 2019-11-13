#include <M5StickC.h>
#include "imu/ImuReader.h"
#include "input/ButtonCheck.h"
#include "input/ButtonData.h"
#include "BluetoothSerial.h"

#define TASK_DEFAULT_CORE_ID 1
#define TASK_STACK_DEPTH 4096UL
#define TASK_NAME_IMU "IMUTask"
#define TASK_NAME_SESSION "SessionTask"
#define TASK_NAME_BUTTON "ButtonTask"
#define TASK_SLEEP_IMU 5 // = 1000[ms] / 200[Hz]
#define TASK_SLEEP_SESSION 40 // = 1000[ms] / 25[Hz]
#define TASK_SLEEP_BUTTON 1 // = 1000[ms] / 1000[Hz]
#define MUTEX_DEFAULT_WAIT 1000UL

static void ImuLoop(void* arg);
static void SessionLoop(void* arg);
static void ButtonLoop(void* arg);

imu::ImuReader* imuReader;
const float offsetGyroX = -1.76546F;
const float offsetGyroY = -6.8906F;
const float offsetGyroZ = 14.59196F;
BluetoothSerial btSpp;
input::ButtonCheck button;

imu::ImuData imuData;
input::ButtonData btnData;
bool hasButtonUpdate = false;
static SemaphoreHandle_t imuDataMutex = NULL;
static SemaphoreHandle_t btnDataMutex = NULL;

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
  M5.Lcd.println("AxisOrange");
  // bluetooth serial
  btSpp.begin("AxisOrange");
  // task
  imuDataMutex = xSemaphoreCreateMutex();
  btnDataMutex = xSemaphoreCreateMutex();
  xTaskCreatePinnedToCore(ImuLoop, TASK_NAME_IMU, TASK_STACK_DEPTH, 
    NULL, 2, NULL, TASK_DEFAULT_CORE_ID);
  xTaskCreatePinnedToCore(SessionLoop, TASK_NAME_SESSION, TASK_STACK_DEPTH, 
    NULL, 1, NULL, TASK_DEFAULT_CORE_ID);
  xTaskCreatePinnedToCore(ButtonLoop, TASK_NAME_BUTTON, TASK_STACK_DEPTH, 
    NULL, 1, NULL, TASK_DEFAULT_CORE_ID);
}

void loop() { /* Do Nothing */ }

static void ImuLoop(void* arg) {
  while (1) {
    uint32_t entryTime = millis();
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
    // imu
    if (xSemaphoreTake(imuDataMutex, MUTEX_DEFAULT_WAIT) == pdTRUE) {
      btSpp.write((uint8_t*)&imuData, imu::ImuDataLen);
    }
    xSemaphoreGive(imuDataMutex);
    // button
    if (xSemaphoreTake(btnDataMutex, MUTEX_DEFAULT_WAIT) == pdTRUE) {
      if (hasButtonUpdate) {
        btSpp.write((uint8_t*)&btnData, input::ButtonDataLen);
        hasButtonUpdate = false;
      }
    }
    xSemaphoreGive(btnDataMutex);
    // idle
    int32_t sleep = TASK_SLEEP_SESSION - (millis() - entryTime);
    vTaskDelay((sleep > 0) ? sleep : 0);
  }
}

static void ButtonLoop(void* arg) {
  uint8_t btnFlag = 0;
  while (1) {
    uint32_t entryTime = millis();
    M5.update();
    if (button.containsUpdate(M5, btnFlag)) {
        for (int i = 0; i < INPUT_BTN_NUM; i++) {
          if (xSemaphoreTake(btnDataMutex, MUTEX_DEFAULT_WAIT) == pdTRUE) {
            btnData.timestamp = millis();
            btnData.btnBits = btnFlag;
            hasButtonUpdate = true;
          }
          xSemaphoreGive(btnDataMutex);
        }
    }
    // idle
    int32_t sleep = TASK_SLEEP_BUTTON - (millis() - entryTime);
    vTaskDelay((sleep > 0) ? sleep : 0);
  }
}
