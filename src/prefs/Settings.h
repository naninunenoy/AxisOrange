#ifndef __PREFS_SETTINGS_H__
#define __PREFS_SETTINGS_H__ 

#include <Preferences.h>

namespace prefs {

static const char* PrefNameSpaceKey = "axis_orange";
static const char* PrefDataKey_gyroOffsetX = "gyro_offset_x";
static const char* PrefDataKey_gyroOffsetY = "gyro_offset_y";
static const char* PrefDataKey_gyroOffsetZ = "gyro_offset_z";

class Settings {
public:
    explicit Settings();
    ~Settings();
    void begin();
    void clear();
    void finish();
    void writeGyroOffset(const float* gyroOffset);
    bool readGyroOffset(float* gyroOffset);
private:
    Preferences preferences;
}; // ButtonCheck

} // prefs

#endif // __PREFS_SETTINGS_H__
