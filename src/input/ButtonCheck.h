#ifndef __INPUT_BUTTON_CHECK_H
#define __INPUT_BUTTON_CHECK_H 

#include <M5Unified.h>
#include <map>

namespace input {
enum Btn { BtnA = 0x01, BtnB = 0x02, BtnC = 0x04 };
enum BtnState { BtnStateRelease = 0, BtnStatePress = 1,  };

#define INPUT_BTN_NUM 3
static const Btn AllBtns[INPUT_BTN_NUM] = { BtnA, BtnB, BtnC };

class ButtonCheck {
public:
    explicit ButtonCheck();
    ~ButtonCheck();
    bool containsUpdate(m5::M5Unified& runningDevice, uint8_t& outBtnBits);
private:
    uint8_t updateFlag;
    BtnState getBtnState(Btn of) const;
    uint8_t getCurrentBits() const;
    bool isButtonStateChanged(Btn of, BtnState ithink, m5::M5Unified& device);
    BtnState getCurrentDeviceBtnState(Btn of, m5::M5Unified& device) const;
    std::map<Btn, BtnState> buttonStateMap;
}; // ButtonCheck

} // input

#endif // __INPUT_BUTTON_CHECK_H
