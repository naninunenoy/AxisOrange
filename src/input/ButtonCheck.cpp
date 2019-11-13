#include "ButtonCheck.h"

namespace input {
    ButtonCheck::ButtonCheck() {
        updateFlag = 0;
        for(int i = 0; i < INPUT_BTN_NUM; i++) {
            buttonStateMap.insert(std::make_pair(AllBtns[i], BtnStateRelease));
        }
    }

    ButtonCheck::~ButtonCheck() { }

    bool ButtonCheck::containsUpdate(M5StickC& runningDevice) {
        updateFlag = 0;
        for(int i = 0; i < INPUT_BTN_NUM; i++) {
            const Btn btn = AllBtns[i];
            const BtnState ithink = getBtnState(btn);
            if (isButtonStateChanged(btn, ithink, runningDevice)) {
                updateFlag |= btn;
            }
        }
        return updateFlag != 0;
    }

    bool ButtonCheck::isBtnUpdate(Btn of) const {
        return (updateFlag & of) != 0;
    }

    BtnState ButtonCheck::getBtnState(Btn of) const { 
        const auto itr = buttonStateMap.find(of);
        if (itr == buttonStateMap.end()) {
            return BtnStateRelease; /// not found
        }
        return itr->second;
    }

    bool ButtonCheck::isButtonStateChanged(Btn of, BtnState ithink, M5StickC& device) {
        BtnState current = getCurrentDeviceBtnState(of, device);
        if (ithink == current) {
            return false; // not changed
        }
        buttonStateMap[of] = current;
        return true;
    }

    BtnState ButtonCheck::getCurrentDeviceBtnState(Btn of, M5StickC& device) const {
        switch (of) {
        case BtnA: return (device.BtnA.isPressed() == 0) ? BtnStateRelease : BtnStatePress;
        case BtnB: return (device.BtnB.isPressed() == 0) ? BtnStateRelease : BtnStatePress;
        }
        return BtnStateRelease;
    }
} // input
