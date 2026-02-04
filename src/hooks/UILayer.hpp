#pragma once

#include <Geode/modify/UILayer.hpp>
#include <Geode/Geode.hpp>

struct HookUILayer : geode::Modify<HookUILayer, UILayer> {
	struct Fields {
		geode::Ref<CCMenuItemSpriteExtra> m_nextSwitcherBtn = nullptr;
		geode::Ref<CCMenuItemSpriteExtra> m_prevSwitcherBtn = nullptr;
		geode::Ref<cocos2d::CCLabelBMFont> m_switcherLabel = nullptr;

		geode::Ref<cocos2d::CCMenu> m_switcherMenu = nullptr;

		bool m_firstUpdate = true;
		bool m_dontUpdate = false;
	};

	bool init(GJBaseGameLayer* baseGame);
    void handleKeypress(cocos2d::enumKeyCodes key, bool down, double timestamp);

	void updateUI();
};
