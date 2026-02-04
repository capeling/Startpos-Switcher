#include "KeybindSettingPopup.hpp"

#include "util.hpp"

using namespace geode::prelude;

KeybindSettingPopup* KeybindSettingPopup::create(cocos2d::enumKeyCodes curr, geode::Function<void(cocos2d::enumKeyCodes)> func) {
    auto ret = new KeybindSettingPopup();
    if (ret->init(curr, std::move(func))) {
        ret->autorelease();
        return ret;
    }

    delete ret;
    return nullptr;
}


bool KeybindSettingPopup::init(cocos2d::enumKeyCodes curr, geode::Function<void(cocos2d::enumKeyCodes)> func) {
    if (!Popup::init(250.f, 150.f))
        return false;

    setTitle("Change Key");

    m_key = curr;
    m_func = std::move(func);

    m_label = CCLabelBMFont::create("", "goldFont.fnt");
    this->updateKeyLabel();

    m_mainLayer->addChildAtPosition(m_label, Anchor::Center, ccp(0, 7));

    auto submitSpr = ButtonSprite::create("Submit", "goldFont.fnt", "GJ_button_01.png");
    submitSpr->setScale(0.9);
    auto submitBtn = CCMenuItemExt::createSpriteExtra(submitSpr, [this](auto sender) {
        m_func(m_key);
        this->onClose(nullptr);
    });
    m_buttonMenu->addChildAtPosition(submitBtn, Anchor::Bottom, ccp(0, 22));

    return true;
}

void KeybindSettingPopup::updateKeyLabel() {
    auto keyName = ss::util::keyToString(m_key);
    m_label->setString(keyName.c_str());
}

void KeybindSettingPopup::keyDown(cocos2d::enumKeyCodes key, double fuckyou) {
    switch (key) {
        case KEY_Escape: {
            m_key = KEY_None;
            break;
        }

        default: {
            m_key = key;
            break;
        }
    }

    updateKeyLabel();
}
