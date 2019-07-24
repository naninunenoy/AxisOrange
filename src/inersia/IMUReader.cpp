#include "IMUReader.h"

namespace inersia {
    IMUReader::IMUReader() { }
    IMUReader::~IMUReader() { }
    bool IMUReader::SetUp(void* imu) {
        if (((IMU*)imu)->Init() != 0) {
            return false;
        }
        return true;
    }
    bool IMUReader::Update(void* imu) {
        // get sensor value
        IMU* tmp = ((IMU*)imu);
        // acc
        tmp->getAccelAdc(&sensorRawAcc[0], &sensorRawAcc[1], &sensorRawAcc[2]);
        for (int i = 0; i < 3; i++) {
            sensorAcc[i] = sensorRawAcc[i] * tmp->aRes;
        }
        // gyro
        tmp->getGyroAdc(&sensorRawGyro[0], &sensorRawGyro[1], &sensorRawGyro[2]);
        for (int i = 0; i < 3; i++) {
            sensorGyro[i] = sensorRawGyro[i] * tmp->gRes;
        }
        return true;
    }
}
