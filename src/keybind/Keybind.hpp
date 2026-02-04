#pragma once

#include <Geode/Geode.hpp>

struct Keybind {
    cocos2d::enumKeyCodes v;

	bool operator==(Keybind const& other) const = default;
	operator int() const { return v; };

    Keybind() = default;
    Keybind(int value) : v(static_cast<cocos2d::enumKeyCodes>(value)) {}
    Keybind(Keybind const&) = default;
};

template <>
struct matjson::Serialize<Keybind> {
    static matjson::Value toJson(Keybind const& value) {
        return static_cast<int>(value.v);
    }
    static geode::Result<Keybind> fromJson(matjson::Value const& value) {
        GEODE_UNWRAP_INTO(auto num, value.asInt());
        return geode::Ok(Keybind(static_cast<cocos2d::enumKeyCodes>(num)));
    }
};
