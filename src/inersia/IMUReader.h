#ifndef __IMU_IMUREADER_H
#define __IMU_IMUREADER_H 

#include <IMU.h>

namespace inersia {
class IMUReader {
public:
    explicit IMUReader();
    ~IMUReader();
    // i cannnot use arg IMU*/IMU& because of compile error
    bool SetUp(void* imu);
    bool Update(void* imu);
    const float* getAccXYZ() const { return sensorAcc; }
    const float* getGyroRPY() const { return sensorGyro; };
private:
    float sensorAcc[3];
    float sensorGyro[3];
    int16_t sensorRawAcc[3];
    int16_t sensorRawGyro[3];
}; // IMUReader

} // inersia

#endif // __IMU_IMUREADER_H
