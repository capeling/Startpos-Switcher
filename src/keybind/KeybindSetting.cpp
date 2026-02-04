#include "KeybindSetting.hpp"

using namespace geode::prelude;

Result<std::shared_ptr<SettingV3>> KeybindSetting::parse(std::string const& key, std::string const& modID, matjson::Value const& json) {
    auto res = std::make_shared<KeybindSetting>();
    auto root = checkJson(json, "KeybindSetting");

    res->parseBaseProperties(key, modID, root);
    root.checkUnknownKeys();

    return root.ok(std::static_pointer_cast<SettingV3>(res));
}

$execute {
    // You can also handle the errors, but if this fails, the game is probably about to crash anyway
    (void)Mod::get()->registerCustomSettingType("keybind", &KeybindSetting::parse);
}
