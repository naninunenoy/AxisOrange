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
        tmp->getAccelData(&sensorRawAcc[0], &sensorRawAcc[1], &sensorRawAcc[2]);
        tmp->getGyroData(&sensorRawGyro[0], &sensorRawGyro[1], &sensorRawGyro[2]);
        // acc
        for (int i = 0; i < 3; i++) {
            sensorAcc[i] = sensorRawAcc[i] * tmp->aRes;
        }
        // gyro
        for (int i = 0; i < 3; i++) {
            sensorGyro[i] = sensorRawGyro[i] * tmp->aRes;
        }
        return true;
    }
}
