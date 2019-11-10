#ifndef __IMU_READER_IMU_DATA_H__
#define __IMU_READER_IMU_DATA_H__

#include <Arduino.h>

namespace ImuReader {

static const int ImuXyz = 3;
static const int ImuWxyz = 4;

struct IMUData {
public:
    float Acc[ImuXyz];
    float Gyro[ImuXyz];
    float Quat[ImuWxyz];

    IMUData() {
        memset(Acc, 0, sizeof(float) * ImuXyz);
        memset(Gyro, 0, sizeof(float) * ImuXyz);
        memset(Quat, 0, sizeof(float) * ImuWxyz);
        Quat[0] = 1.0F;
    }
};

}

#endif // __IMU_READER_IMU_DATA_H__
