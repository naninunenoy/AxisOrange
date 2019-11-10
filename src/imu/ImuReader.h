#ifndef __IMU_IMU_READER_H__
#define __IMU_IMU_READER_H__

#include <inttypes.h>
#include "mahony/MahonyAHRS.h"
#include "ImuData.h"

namespace imu {

class ImuReader {
public:
    explicit ImuReader();
    bool initialize();
    bool writeGyroOffset(float x, float y, float z);
    bool update();
    bool read(ImuData& outImuData) const;
private:
    mahony::MahonyAHRS ahrs;
    ImuData imuData;
    uint32_t lastUpdated;
    float gyroOffsets[ImuXyz];
};

} // imu

#endif // __IMU_IMU_READER_H__
