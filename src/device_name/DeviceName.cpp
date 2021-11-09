#include "DeviceName.h"

namespace device_name {
    DeviceName::DeviceName(const char* prefix) : prefixName(prefix) {
    }
    
    const char* DeviceName::getName(m5gfx::board_t board) {
        switch (board) {
            case m5gfx::board_t::board_M5Stack:
                concatDeviceName(DEVICE_NAME_UNKNOWN);
                break;
            case m5gfx::board_t::board_M5StackCore2:
                concatDeviceName(DEVICE_NAME_M5STACK_CORE2);
                break;
            case m5gfx::board_t::board_M5StickC:
                concatDeviceName(DEVICE_NAME_M5STICK_C);
                break;
            case m5gfx::board_t::board_M5StickCPlus:
                concatDeviceName(DEVICE_NAME_M5STICK_CPLUS);
                break;
            case m5gfx::board_t::board_M5StackCoreInk:
                concatDeviceName(DEVICE_NAME_M5STACK_COREINK);
                break;
            case m5gfx::board_t::board_M5Paper:
                concatDeviceName(DEVICE_NAME_M5PAPER);
                break;
            case m5gfx::board_t::board_M5Tough:
                concatDeviceName(DEVICE_NAME_M5TOUGH);
                break;
            case m5gfx::board_t::board_M5ATOM:
                concatDeviceName(DEVICE_NAME_M5ATOM);
                break;
            case m5gfx::board_t::board_M5TimerCam:
                concatDeviceName(DEVICE_NAME_M5TIMER_CAM);
                break;
            case m5gfx::board_t::board_unknown:
            default:
                concatDeviceName(DEVICE_NAME_UNKNOWN);
                break;
        }
        return name;
    }
    
    void DeviceName::concatDeviceName(const char* deviceName) {
        snprintf(name, DEVICE_NAME_MAX_LEN, "%s(%s)", DEVICE_NAME_PREFIX, deviceName);
    }
} // device_name
