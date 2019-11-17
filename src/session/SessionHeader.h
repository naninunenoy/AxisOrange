#ifndef __SESSION_SESSION_HEADER_H__
#define __SESSION_SESSION_HEADER_H__

#include <inttypes.h>
#include "SessionDefine.h"

namespace session {

struct SessionHeader {
public:
    uint16_t dataType;
    uint16_t dataLength;

    explicit SessionHeader(DataDefine define) {
        switch (define) {
        case DataDefineImu:
            dataType = data_type::imu;
            dataLength = data_length::imu;
            break;
        case DataDefineButton:
            dataType = data_type::button;
            dataLength = data_length::button;
            break;
        default:
            dataType = 0;
            dataLength = 0;
            break;
        }
    }
};

} // session

#endif // __SESSION_SESSION_HEADER_H__
