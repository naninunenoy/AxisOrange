#include "IMUReader.h"

namespace imu {
    IMUReader::IMUReader(IMU& imu) : imu(imu) { 

    }
    IMUReader::~IMUReader() {
        
    }
    bool IMUReader::SetUp() {
        if (imu.Init() != 0) {
            return false;
        }
        return true;
    }
    bool IMUReader::Update() {
        // get sensor value
        imu.getAccelData(&sensorRawAcc[0], &sensorRawAcc[1], &sensorRawAcc[2]);
        imu.getGyroData(&sensorRawGyro[0], &sensorRawGyro[1], &sensorRawGyro[2]);
        // acc
        for (int i = 0; i < 3; i++) {
            sensorAcc[i] = sensorRawAcc[i] * imu.aRes;
        }
        // gyro
        for (int i = 0; i < 3; i++) {
            sensorGyro[i] = sensorRawGyro[i] * imu.aRes;
        }
        return true;
    }
}
