#pragma once

#include <Geode/Geode.hpp>

namespace ss::util {

// taken from (https://github.com/geode-sdk/CustomKeybinds/blob/ba9cfc1562b19b52d52117b1f4b307e5868c7b60/src/Keybinds.cpp#L30)
static std::string keyToString(cocos2d::enumKeyCodes key) {
    switch (key) {
        case cocos2d::KEY_None:      return "None";
        case cocos2d::KEY_C:         return "C";
        case cocos2d::KEY_Multiply:  return "Mul";
        case cocos2d::KEY_Divide:    return "Div";
        case cocos2d::KEY_OEMPlus:   return "Plus";
        case cocos2d::KEY_OEMMinus:  return "Minus";
        case cocos2d::CONTROLLER_LTHUMBSTICK_DOWN: return "L_THUMBSTICK_DOWN";
        case cocos2d::CONTROLLER_LTHUMBSTICK_LEFT: return "L_THUMBSTICK_LEFT";
        case cocos2d::CONTROLLER_LTHUMBSTICK_UP: return "L_THUMBSTICK_UP";
        case cocos2d::CONTROLLER_LTHUMBSTICK_RIGHT: return "L_THUMBSTICK_RIGHT";
        case cocos2d::CONTROLLER_RTHUMBSTICK_RIGHT: return "R_THUMBSTICK_RIGHT";
        case cocos2d::CONTROLLER_RTHUMBSTICK_LEFT: return "L_THUMBSTICK_RIGHT";
        case cocos2d::CONTROLLER_RTHUMBSTICK_DOWN: return "L_THUMBSTICK_DOWN";
        case cocos2d::CONTROLLER_RTHUMBSTICK_UP: return "L_THUMBSTICK_UP";
        case static_cast<cocos2d::enumKeyCodes>(-1): return "Unknown";
        default: {
            auto s = cocos2d::CCKeyboardDispatcher::get()->keyToString(key);
            return (s != nullptr) ? s : "Unknown";
        }
    }
}

}
