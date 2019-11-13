#ifndef __INPUT_BUTTON_CHECK_H
#define __INPUT_BUTTON_CHECK_H 

#include <M5StickC.h>
#include <map>

namespace input {
enum Btn { BtnA = 0x01, BtnB = 0x02 };
enum BtnState { BtnStateRelease = 0, BtnStatePress = 1,  };

#define INPUT_BTN_NUM 2
static const Btn AllBtns[INPUT_BTN_NUM] = { BtnA, BtnB };

class ButtonCheck {
public:
    explicit ButtonCheck();
    ~ButtonCheck();
    bool containsUpdate(M5StickC& runningDevice);
    bool isBtnUpdate(Btn of) const;
    BtnState getBtnState(Btn of) const;
private:
    uint8_t updateFlag;
    bool isButtonStateChanged(Btn of, BtnState ithink, M5StickC& device);
    BtnState getCurrentDeviceBtnState(Btn of, M5StickC& device) const;
    std::map<Btn, BtnState> buttonStateMap;
}; // ButtonCheck

inline uint8_t toBtnCode(Btn btn) {
    switch (btn) {
    case BtnA: return 'A';
    case BtnB: return 'B';
    }
    return '?';
}

inline uint8_t toBtnPress(BtnState btn) {
    if (btn == BtnStatePress) {
        return 1;
    }
    return 0;
}

} // input

#endif // __INPUT_BUTTON_CHECK_H
