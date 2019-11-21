#include "Settings.h"

namespace prefs {

    Settings::Settings() { }
    Settings::~Settings() { }

    void Settings::begin() {
        preferences.begin(PrefNameSpaceKey, false);
    }

    void Settings::clear() {
        preferences.clear();
    }

    void Settings::finish() {
        preferences.end();
    }

    void Settings::writeGyroOffset(const float* gyroOffset) {
        preferences.putFloat(PrefDataKey_gyroOffsetX, gyroOffset[0]);
        preferences.putFloat(PrefDataKey_gyroOffsetY, gyroOffset[1]);
        preferences.putFloat(PrefDataKey_gyroOffsetZ, gyroOffset[2]);
    }

    bool Settings::readGyroOffset(float* gyroOffset) {
        float x = preferences.getFloat(PrefDataKey_gyroOffsetX, 0.0F);
        float y = preferences.getFloat(PrefDataKey_gyroOffsetY, 0.0F);
        float z = preferences.getFloat(PrefDataKey_gyroOffsetZ, 0.0F);
        gyroOffset[0] = x;
        gyroOffset[1] = y;
        gyroOffset[2] = z;
        return x != 0.0F || y != 0.0F || z != 0.0F;
    }

} // prefs
