#include "KeybindSettingNode.hpp"

#include "KeybindSettingPopup.hpp"
#include "util.hpp"

using namespace geode::prelude;

KeybindSettingNode* KeybindSettingNode::create(std::shared_ptr<KeybindSetting> setting, float width) {
    auto ret = new KeybindSettingNode();
    if (ret->init(setting, width)) {
        ret->autorelease();
        return ret;
    }

    delete ret;
    return nullptr;
}

geode::SettingNodeV3* KeybindSetting::createNode(float width) {
    return KeybindSettingNode::create(
        std::static_pointer_cast<KeybindSetting>(shared_from_this()),
        width
    );
}

bool KeybindSettingNode::init(std::shared_ptr<KeybindSetting> setting, float width) {
    if (!SettingValueNodeV3::init(setting, width))
        return false;

    auto keyName = ss::util::keyToString(setting->getValue().v);
    m_label = CCLabelBMFont::create(keyName.c_str(), "bigFont.fnt");
    m_label->setScale(0.6f);

    m_button = CCMenuItemExt::createSpriteExtra(m_label, [this](auto sender) {
        KeybindSettingPopup::create(this->getValue().v, [this](auto key) {
            this->setValue(key, nullptr);
        })->show();
    });

    this->getButtonMenu()->addChild(m_button);
    this->getButtonMenu()->setContentWidth(40);
    this->getButtonMenu()->setLayout(RowLayout::create());

    this->updateState(nullptr);

    return true;
}

void KeybindSettingNode::updateState(CCNode* invoker) {
    SettingValueNodeV3::updateState(invoker);
    
    auto shouldEnable = this->getSetting()->shouldEnable();

    m_label->setOpacity(shouldEnable ? 255 : 155);
    m_label->setColor(shouldEnable ? ccWHITE : ccGRAY);

    auto keyName = ss::util::keyToString(this->getValue().v);
    m_label->setString(keyName.c_str());

    m_button->setEnabled(shouldEnable);
}
