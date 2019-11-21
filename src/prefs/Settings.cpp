#include "Settings.h"

namespace prefs {

    Settings::Settings() { }
    Settings::~Settings() { }

    void Settings::begin() {
        preferences.begin(prefNameSpaceKey, false);
    }

    void Settings::clear() {
        preferences.clear();
    }

    void Settings::finish() {
        preferences.end();
    }

    void Settings::writeGyroOffset(const float* gyroOffset) {
        preferences.putFloat(prefDataKey_gyroOffsetX, gyroOffset[0]);
        preferences.putFloat(prefDataKey_gyroOffsetY, gyroOffset[1]);
        preferences.putFloat(prefDataKey_gyroOffsetZ, gyroOffset[2]);
    }

    void Settings::readGyroOffset(float* gyroOffset) {
        gyroOffset[0] = preferences.getFloat(prefDataKey_gyroOffsetX, 0.0F);
        gyroOffset[1] = preferences.getFloat(prefDataKey_gyroOffsetY, 0.0F);
        gyroOffset[2] = preferences.getFloat(prefDataKey_gyroOffsetZ, 0.0F);
    }

} // prefs
