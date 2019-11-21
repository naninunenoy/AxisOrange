#ifndef __IMU_AVERAGE_CALC_H__
#define __IMU_AVERAGE_CALC_H__

#include <Arduino.h>

namespace imu {

static const int DataMaxCount = 1000;

class AverageCalc {
public:
    explicit AverageCalc();
    ~AverageCalc();
    bool push(float data);
    float average() const;
    int count() const { return cnt; }
    void reset() { cnt = 0; }
private:
    float data[DataMaxCount];
    int cnt;
};

class AverageCalcXYZ {
public:
    explicit AverageCalcXYZ() { }
    ~AverageCalcXYZ() { }
    bool push(float x, float y, float z) { return aveX.push(x) && aveY.push(y) && aveZ.push(z); }
    float averageX() const { return aveX.average(); }
    float averageY() const { return aveY.average(); }
    float averageZ() const { return aveZ.average(); }
    int countX() const { return aveX.count(); }
    int countY() const { return aveY.count(); }
    int countZ() const { return aveZ.count(); }
    void reset() { aveX.reset(); aveY.reset(); aveZ.reset(); }
private:
    AverageCalc aveX;
    AverageCalc aveY;
    AverageCalc aveZ;
};

} // imu

#endif // __IMU_AVERAGE_CALC_H__
