#pragma once

#include <Geode/Geode.hpp>

class KeybindSettingPopup : public geode::Popup {
public:
    static KeybindSettingPopup* create(cocos2d::enumKeyCodes curr, geode::Function<void(cocos2d::enumKeyCodes)> func);

protected:
    bool init(cocos2d::enumKeyCodes curr, geode::Function<void(cocos2d::enumKeyCodes)> func);
    void keyDown(cocos2d::enumKeyCodes key, double fuckyou);

    void updateKeyLabel();

    cocos2d::CCLabelBMFont* m_label = nullptr;
    cocos2d::enumKeyCodes m_key = cocos2d::enumKeyCodes::KEY_None;
    geode::Function<void(cocos2d::enumKeyCodes)> m_func;
};
