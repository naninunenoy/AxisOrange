#include "ButtonCheck.h"

namespace input {
    ButtonCheck::ButtonCheck() : updateFlag(0) {
        for(int i = 0; i < INPUT_BTN_NUM; i++) {
            buttonStateMap.insert(std::make_pair(AllBtns[i], BtnStateRelease));
        }
    }

    ButtonCheck::~ButtonCheck() { }

    bool ButtonCheck::containsUpdate(m5::M5Unified& runningDevice, uint8_t& outBtnBits) {
        updateFlag = 0;
        for(int i = 0; i < INPUT_BTN_NUM; i++) {
            const Btn btn = AllBtns[i];
            const BtnState ithink = getBtnState(btn);
            if (isButtonStateChanged(btn, ithink, runningDevice)) {
                updateFlag |= btn;
            }
        }
        bool hasUpdate = updateFlag != 0;
        if (hasUpdate) {
            outBtnBits = getCurrentBits();
        }
        return hasUpdate;
    }

    uint8_t ButtonCheck::getCurrentBits() const {
        return (
            BtnB * getBtnState(BtnB) +
            BtnA * getBtnState(BtnA)
        );
    }

    BtnState ButtonCheck::getBtnState(Btn of) const { 
        const auto itr = buttonStateMap.find(of);
        if (itr == buttonStateMap.end()) {
            return BtnStateRelease; /// not found
        }
        return itr->second;
    }

    bool ButtonCheck::isButtonStateChanged(Btn of, BtnState ithink, m5::M5Unified& device) {
        BtnState current = getCurrentDeviceBtnState(of, device);
        if (ithink == current) {
            return false; // not changed
        }
        buttonStateMap[of] = current;
        return true;
    }

    BtnState ButtonCheck::getCurrentDeviceBtnState(Btn of, m5::M5Unified& device) const {
        switch (of) {
        case BtnA: return (device.BtnA.isPressed() == 0) ? BtnStateRelease : BtnStatePress;
        case BtnB: return (device.BtnB.isPressed() == 0) ? BtnStateRelease : BtnStatePress;
        }
        return BtnStateRelease;
    }
} // input
