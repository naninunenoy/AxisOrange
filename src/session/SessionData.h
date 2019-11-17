#ifndef __SESSION_SESSION_DATA_H__
#define __SESSION_SESSION_DATA_H__

#include <inttypes.h>
#include <Arduino.h>
#include "SessionHeader.h"

namespace session {

struct SessionData {
public:
    SessionHeader header;
    uint8_t data[data_length::max] = {0};

    explicit SessionData(DataDefine define) : header(define) {
    }
    void write(const uint8_t* data, uint16_t len) {
        memcpy(this->data, data, len);
    }
    uint32_t length() const { return data_length::header + header.dataLength; }
};

} // session

#endif // __SESSION_SESSION_DATA_H__
