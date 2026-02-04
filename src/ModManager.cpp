#include "ModManager.hpp"

#include "keybind/KeybindSetting.hpp"

using namespace geode::prelude;

ModManager* ModManager::sharedState() {
    static ModManager instance;
    return &instance;
}

ModManager::ModManager() {
    m_dontFadeOnStart = Mod::get()->getSettingValue<bool>("hide");
    m_hideBtns = Mod::get()->getSettingValue<bool>("hideBtns");
    m_ignoreDisabled = Mod::get()->getSettingValue<bool>("ignoreDisabled");
    m_opacity = Mod::get()->getSettingValue<double>("opacity") / 100 * 255;

    m_prevKey = Mod::get()->getSettingValue<Keybind>("leftSwitch");
    m_nextKey = Mod::get()->getSettingValue<Keybind>("rightSwitch");
}

$on_mod(Loaded) {
    auto mm = ModManager::sharedState();
    
    listenForSettingChanges<bool>("hide", [mm](bool val) {
        mm->m_dontFadeOnStart = val;
    });
    
    listenForSettingChanges<bool>("hideBtns", [mm](bool val) {
        mm->m_hideBtns = val;
    });
    
    listenForSettingChanges<bool>("ignoreDisabled", [mm](bool val) {
        mm->m_ignoreDisabled = val;
    });
    
    listenForSettingChanges<double>("opacity", [mm](double val) {
        mm->m_opacity = val / 100 * 255;
    });
 
    listenForSettingChanges<Keybind>("leftSwitch", [mm](Keybind val) {
        mm->m_prevKey = val;
    });

    listenForSettingChanges<Keybind>("rightSwitch", [mm](Keybind val) {
        mm->m_nextKey = val;
    });
}
