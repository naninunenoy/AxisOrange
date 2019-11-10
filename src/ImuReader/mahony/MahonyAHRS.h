#ifndef __IMU_READER_MAHONY_AHRS_H__
#define __IMU_READER_MAHONY_AHRS_H__

namespace imuReader {
namespace mahony {

class MahonyAHRS {
public:
    void UpdateQuaternion(
        float gx, float gy, float gz, 
        float ax, float ay, float az,
        float& q0, float& q1, float& q2, float& q3);

    void QuaternionToEuler(
        float q0, float q1, float q2, float q3, 
        float& pitch, float& roll, float& yaw);
};

} // mahony
} // imuReader

#endif // __IMU_READER_MAHONY_AHRS_H__
