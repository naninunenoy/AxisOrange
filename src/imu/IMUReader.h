#ifndef __IMU_IMUREADER_H
#define __IMU_IMUREADER_H 

#include <IMU.h>

namespace imu {
class IMUReader {
public:
    explicit IMUReader(IMU& imu);
    ~IMUReader();
    bool SetUp();
    bool Update();
    const float* getAccXYZ() const { return sensorAcc; }
    const float* getGyroRPY() const { return sensorGyro; };
private:
    IMU& imu;
    float sensorAcc[3];
    float sensorGyro[3];
    int16_t sensorRawAcc[3];
    int16_t sensorRawGyro[3];
}; // IMUReader

} // imu

#endif // __IMU_IMUREADER_H
