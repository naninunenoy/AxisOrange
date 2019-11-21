#include "AverageCalc.h"

namespace imu {

    AverageCalc::AverageCalc() : cnt(0) { 
        memset(data, 0, sizeof(float) * DataMaxCount);
    }

    AverageCalc::~AverageCalc() { }

    bool AverageCalc::push(float data) {
        if (cnt >= DataMaxCount) {
            return false;
        }
        this->data[cnt] = data;
        cnt++;
        return true;
    }

    float AverageCalc::average() const {
        float sum = 0;
        for (int i = 0; i < cnt; i++) {
            sum += data[i];
        }
        return sum / (float)cnt;
    }

} // imu
