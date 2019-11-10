#ifndef __IMU_MAHONY_AHRS_H__
#define __IMU_MAHONY_AHRS_H__

#ifdef imu
#undef imu
#endif

namespace imu {
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
} // imu

#endif // __IMU_MAHONY_AHRS_H__
