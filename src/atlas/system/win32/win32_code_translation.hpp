#pragma once

#include "atlas/system/win32/win32.hpp"
#include "atlas/types.hpp"

#include <cstdint>

namespace Atlas {
enum class KeyCode : Nat16;
enum class ScanCode : Nat16;
enum class MouseButton : Nat8;
}  // namespace Atlas

namespace Atlas::Win32 {
Atlas::KeyCode translate_key_code(USHORT key_code);
Atlas::ScanCode translate_scan_code(USHORT scan_code);
Atlas::MouseButton translate_mouse_button(USHORT mouse_button);
}  // namespace Atlas::Win32
