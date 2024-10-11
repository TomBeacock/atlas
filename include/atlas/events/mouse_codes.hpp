#pragma once

#include <cstdint>
#include <format>
#include <ostream>

namespace Atlas {
enum class MouseButton : Nat8 {
    None = 0,
    Left = 1,
    Right = 2,
    Middle = 3,
    X1 = 4,
    X2 = 5,
};

inline std::string to_string(MouseButton mouse_button)
{
    switch (mouse_button) {
        case MouseButton::Left:   return "Left";
        case MouseButton::Right:  return "Right";
        case MouseButton::Middle: return "Middle";
        case MouseButton::X1:     return "X1";
        case MouseButton::X2:     return "X2";
    }
    return "Unknown";
}

inline std::ostream &operator<<(std::ostream &os, MouseButton mouse_button);
}  // namespace Atlas

template<>
struct std::formatter<Atlas::MouseButton> {
    constexpr auto parse(std::format_parse_context &ctx) { return ctx.begin(); }

    auto format(
        const Atlas::MouseButton &mouse_button, std::format_context &ctx) const
    {
        return std::format_to(ctx.out(), "{}", Atlas::to_string(mouse_button));
    }
};

#include "mouse_codes.inl"
