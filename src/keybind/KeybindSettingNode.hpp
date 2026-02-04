#pragma once

#include <Geode/Geode.hpp>

#include "KeybindSetting.hpp"

class KeybindSettingNode : public geode::SettingValueNodeV3<KeybindSetting> {
public:
    static KeybindSettingNode* create(std::shared_ptr<KeybindSetting> setting, float width);

    geode::SettingNodeV3* createNode(float width);

    void updateState(CCNode* invoker) override;

protected:
    bool init(std::shared_ptr<KeybindSetting> setting, float width);

    cocos2d::CCLabelBMFont* m_label = nullptr;
    CCMenuItemSpriteExtra* m_button = nullptr;
};

