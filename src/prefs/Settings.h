#ifndef __PREFS_SETTINGS_H
#define __PREFS_SETTINGS_H 

#include <Preferences.h>

namespace prefs {

static const char* prefNameSpaceKey = "axis_orange";
static const char* prefDataKey_gyroOffsetX = "settings_gyro_offset_x";
static const char* prefDataKey_gyroOffsetY = "settings_gyro_offset_y";
static const char* prefDataKey_gyroOffsetZ = "settings_gyro_offset_z";

class Settings {
public:
    explicit Settings();
    ~Settings();
    void begin();
    void clear();
    void finish();
    void writeGyroOffset(const float* gyroOffset);
    void readGyroOffset(float* gyroOffset);
private:
    Preferences preferences;
}; // ButtonCheck

} // prefs

#endif // __PREFS_SETTINGS_H
