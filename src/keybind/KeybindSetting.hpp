#pragma once

#include <Geode/Geode.hpp>

#include "Keybind.hpp"

class KeybindSetting : public geode::SettingBaseValueV3<Keybind> {
public:
    static geode::Result<std::shared_ptr<SettingV3>> parse(std::string const& key, std::string const& modID, matjson::Value const& json);

    geode::SettingNodeV3* createNode(float width) override;
};

template <>
struct geode::SettingTypeForValueType<Keybind> {
    using SettingType = KeybindSetting;
};
