#include <M5StickC.h>
#include "ImuReader.h"

namespace imu {
    ImuReader::ImuReader() : ahrs(), imuData() {
        memset(gyroOffsets, 0, sizeof(float) * ImuXyz);
    }

    bool ImuReader::initialize() {
        return (M5.IMU.Init() == 0);
    }

    bool ImuReader::writeGyroOffset(float x, float y, float z) {
        gyroOffsets[0] = x;
        gyroOffsets[1] = y;
        gyroOffsets[2] = z;
        return true;
    }

    bool ImuReader::update() {
        float& ax = imuData.acc[0];
        float& ay = imuData.acc[1];
        float& az = imuData.acc[2];
        float& gx = imuData.gyro[0];
        float& gy = imuData.gyro[1];
        float& gz = imuData.gyro[2];
        float& qw = imuData.quat[0];
        float& qx = imuData.quat[1];
        float& qy = imuData.quat[2];
        float& qz = imuData.quat[3];
        
        M5.IMU.getAccelData(&ax, &ay, &az);
        M5.IMU.getGyroData(&gx, &gy, &gz);

        gx -= gyroOffsets[0];
        gy -= gyroOffsets[1];
        gz -= gyroOffsets[2];

        ahrs.UpdateQuaternion(
            gx * DEG_TO_RAD, gy * DEG_TO_RAD,  gz * DEG_TO_RAD, 
            ax, ay, az,
            qw, qx, qy, qz);
        imuData.timestamp = millis();
        lastUpdated = imuData.timestamp;
        return true;
    }

    bool ImuReader::read(ImuData& outImuData) const {
        if (lastUpdated == outImuData.timestamp) {
            return false; // not updated
        }
        memcpy(&outImuData, &imuData, ImuDataLen);
        return true;
    }

} // imu
