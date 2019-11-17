#ifndef __SESSION_SESSION_DEFINE_H__
#define __SESSION_SESSION_DEFINE_H__

#include <inttypes.h>

namespace session {

enum DataDefine {
    DataDefineUnknown = 0,
    DataDefineImu = 1,
    DataDefineButton = 2
};

namespace data_type {
static const uint16_t imu = 0x0001;
static const uint16_t button = 0x0002;
}

namespace data_length {
static const uint16_t max = 64;
static const uint16_t header = 4;
static const uint16_t imu = 44;
static const uint16_t button = 5;
}

} // session

#endif // __SESSION_SESSION_DEFINE_H__
