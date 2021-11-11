#ifndef __DEVICE_NAME_DEVICE_NAME_H__
#define __DEVICE_NAME_DEVICE_NAME_H__

#include <M5GFX.h>

namespace device_name {

#define DEVICE_NAME_MAX_LEN 32
#define DEVICE_NAME_PREFIX "AxisOrange"
#define DEVICE_NAME_UNKNOWN "???"
#define DEVICE_NAME_M5STACK "M5Stack"
#define DEVICE_NAME_M5STACK_CORE2 "M5StackCore2"
#define DEVICE_NAME_M5STICK_C "M5StickC"
#define DEVICE_NAME_M5STICK_CPLUS "M5StickCPlus"
#define DEVICE_NAME_M5STACK_COREINK "M5StackCoreInk"
#define DEVICE_NAME_M5PAPER "M5Paper"
#define DEVICE_NAME_M5TOUGH "M5Tough"
#define DEVICE_NAME_M5ATOM "M5ATOM"
#define DEVICE_NAME_M5TIMER_CAM "M5TimerCam"

class DeviceName {
public:
    explicit DeviceName(const char* prefix);
    const char* getName(m5gfx::board_t board);
private:
    const char* prefixName;
    char name[DEVICE_NAME_MAX_LEN] = {0};
    void concatDeviceName(const char* deviceName);
}; 

} // device_name

#endif // __DEVICE_NAME_DEVICE_NAME_H__
