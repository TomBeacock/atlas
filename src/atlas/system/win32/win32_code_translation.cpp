#include "atlas/system/win32/win32_code_translation.hpp"

#include "atlas/debug/assert.hpp"
#include "atlas/events/event.hpp"

namespace Atlas::Win32 {
const KeyCode key_code_table[] = {
    /* 0x0000 */ Atlas::KeyCode::None,
    /* 0x0001 */ Atlas::KeyCode::None,
    /* 0x0002 */ Atlas::KeyCode::None,
    /* 0x0003 */ Atlas::KeyCode::None,
    /* 0x0004 */ Atlas::KeyCode::None,
    /* 0x0005 */ Atlas::KeyCode::None,
    /* 0x0006 */ Atlas::KeyCode::None,
    /* 0x0007 */ Atlas::KeyCode::None,
    /* 0x0008 */ Atlas::KeyCode::Backspace,
    /* 0x0009 */ Atlas::KeyCode::Tab,
    /* 0x000A */ Atlas::KeyCode::None,
    /* 0x000B */ Atlas::KeyCode::None,
    /* 0x000C */ Atlas::KeyCode::Clear,
    /* 0x000D */ Atlas::KeyCode::Return,
    /* 0x000E */ Atlas::KeyCode::None,
    /* 0x000F */ Atlas::KeyCode::None,
    /* 0x0010 */ Atlas::KeyCode::LeftShift,
    /* 0x0011 */ Atlas::KeyCode::LeftControl,
    /* 0x0012 */ Atlas::KeyCode::LeftAlt,
    /* 0x0013 */ Atlas::KeyCode::PauseBreak,
    /* 0x0014 */ Atlas::KeyCode::CapsLock,
    /* 0x0015 */ Atlas::KeyCode::None,
    /* 0x0016 */ Atlas::KeyCode::None,
    /* 0x0017 */ Atlas::KeyCode::None,
    /* 0x0018 */ Atlas::KeyCode::None,
    /* 0x0019 */ Atlas::KeyCode::None,
    /* 0x001A */ Atlas::KeyCode::None,
    /* 0x001B */ Atlas::KeyCode::Escape,
    /* 0x001C */ Atlas::KeyCode::None,
    /* 0x001D */ Atlas::KeyCode::None,
    /* 0x001E */ Atlas::KeyCode::None,
    /* 0x001F */ Atlas::KeyCode::None,
    /* 0x0020 */ Atlas::KeyCode::Space,
    /* 0x0021 */ Atlas::KeyCode::PageUp,
    /* 0x0022 */ Atlas::KeyCode::PageDown,
    /* 0x0023 */ Atlas::KeyCode::End,
    /* 0x0024 */ Atlas::KeyCode::Home,
    /* 0x0025 */ Atlas::KeyCode::LeftArrow,
    /* 0x0026 */ Atlas::KeyCode::UpArrow,
    /* 0x0027 */ Atlas::KeyCode::RightArrow,
    /* 0x0028 */ Atlas::KeyCode::DownArrow,
    /* 0x0029 */ Atlas::KeyCode::Select,
    /* 0x002A */ Atlas::KeyCode::PrintScreen,
    /* 0x002B */ Atlas::KeyCode::Execute,
    /* 0x002C */ Atlas::KeyCode::PrintScreen,
    /* 0x002D */ Atlas::KeyCode::Insert,
    /* 0x002E */ Atlas::KeyCode::Delete,
    /* 0x002F */ Atlas::KeyCode::Help,
    /* 0x0030 */ Atlas::KeyCode::Alpha0,
    /* 0x0031 */ Atlas::KeyCode::Alpha1,
    /* 0x0032 */ Atlas::KeyCode::Alpha2,
    /* 0x0033 */ Atlas::KeyCode::Alpha3,
    /* 0x0034 */ Atlas::KeyCode::Alpha4,
    /* 0x0035 */ Atlas::KeyCode::Alpha5,
    /* 0x0036 */ Atlas::KeyCode::Alpha6,
    /* 0x0037 */ Atlas::KeyCode::Alpha7,
    /* 0x0038 */ Atlas::KeyCode::Alpha8,
    /* 0x0039 */ Atlas::KeyCode::Alpha9,
    /* 0x003A */ Atlas::KeyCode::None,
    /* 0x003B */ Atlas::KeyCode::None,
    /* 0x003C */ Atlas::KeyCode::None,
    /* 0x003D */ Atlas::KeyCode::None,
    /* 0x003E */ Atlas::KeyCode::None,
    /* 0x003F */ Atlas::KeyCode::None,
    /* 0x0040 */ Atlas::KeyCode::None,
    /* 0x0041 */ Atlas::KeyCode::A,
    /* 0x0042 */ Atlas::KeyCode::B,
    /* 0x0043 */ Atlas::KeyCode::C,
    /* 0x0044 */ Atlas::KeyCode::D,
    /* 0x0045 */ Atlas::KeyCode::E,
    /* 0x0046 */ Atlas::KeyCode::F,
    /* 0x0047 */ Atlas::KeyCode::G,
    /* 0x0048 */ Atlas::KeyCode::H,
    /* 0x0049 */ Atlas::KeyCode::I,
    /* 0x004A */ Atlas::KeyCode::J,
    /* 0x004B */ Atlas::KeyCode::K,
    /* 0x004C */ Atlas::KeyCode::L,
    /* 0x004D */ Atlas::KeyCode::M,
    /* 0x004E */ Atlas::KeyCode::N,
    /* 0x004F */ Atlas::KeyCode::O,
    /* 0x0050 */ Atlas::KeyCode::P,
    /* 0x0051 */ Atlas::KeyCode::Q,
    /* 0x0052 */ Atlas::KeyCode::R,
    /* 0x0053 */ Atlas::KeyCode::S,
    /* 0x0054 */ Atlas::KeyCode::T,
    /* 0x0055 */ Atlas::KeyCode::U,
    /* 0x0056 */ Atlas::KeyCode::V,
    /* 0x0057 */ Atlas::KeyCode::W,
    /* 0x0058 */ Atlas::KeyCode::X,
    /* 0x0059 */ Atlas::KeyCode::Y,
    /* 0x005A */ Atlas::KeyCode::Z,
    /* 0x005B */ Atlas::KeyCode::LeftGUI,
    /* 0x005C */ Atlas::KeyCode::RightGUI,
    /* 0x005D */ Atlas::KeyCode::Application,
    /* 0x005E */ Atlas::KeyCode::None,
    /* 0x005F */ Atlas::KeyCode::SystemSleep,
    /* 0x0060 */ Atlas::KeyCode::Keypad0,
    /* 0x0061 */ Atlas::KeyCode::Keypad1,
    /* 0x0062 */ Atlas::KeyCode::Keypad2,
    /* 0x0063 */ Atlas::KeyCode::Keypad3,
    /* 0x0064 */ Atlas::KeyCode::Keypad4,
    /* 0x0065 */ Atlas::KeyCode::Keypad5,
    /* 0x0066 */ Atlas::KeyCode::Keypad6,
    /* 0x0067 */ Atlas::KeyCode::Keypad7,
    /* 0x0068 */ Atlas::KeyCode::Keypad8,
    /* 0x0069 */ Atlas::KeyCode::Keypad9,
    /* 0x006A */ Atlas::KeyCode::KeypadMultiply,
    /* 0x006B */ Atlas::KeyCode::KeypadPlus,
    /* 0x006C */ Atlas::KeyCode::Separator,
    /* 0x006D */ Atlas::KeyCode::KeypadMinus,
    /* 0x006E */ Atlas::KeyCode::KeypadPeriod,
    /* 0x006F */ Atlas::KeyCode::KeypadDivide,
    /* 0x0070 */ Atlas::KeyCode::F1,
    /* 0x0071 */ Atlas::KeyCode::F2,
    /* 0x0072 */ Atlas::KeyCode::F3,
    /* 0x0073 */ Atlas::KeyCode::F4,
    /* 0x0074 */ Atlas::KeyCode::F5,
    /* 0x0075 */ Atlas::KeyCode::F6,
    /* 0x0076 */ Atlas::KeyCode::F7,
    /* 0x0077 */ Atlas::KeyCode::F8,
    /* 0x0078 */ Atlas::KeyCode::F9,
    /* 0x0079 */ Atlas::KeyCode::F10,
    /* 0x007A */ Atlas::KeyCode::F11,
    /* 0x007B */ Atlas::KeyCode::F12,
    /* 0x007C */ Atlas::KeyCode::F13,
    /* 0x007D */ Atlas::KeyCode::F14,
    /* 0x007E */ Atlas::KeyCode::F15,
    /* 0x007F */ Atlas::KeyCode::F16,
    /* 0x0080 */ Atlas::KeyCode::F17,
    /* 0x0081 */ Atlas::KeyCode::F18,
    /* 0x0082 */ Atlas::KeyCode::F19,
    /* 0x0083 */ Atlas::KeyCode::F20,
    /* 0x0084 */ Atlas::KeyCode::F21,
    /* 0x0085 */ Atlas::KeyCode::F22,
    /* 0x0086 */ Atlas::KeyCode::F23,
    /* 0x0087 */ Atlas::KeyCode::F24,
    /* 0x0088 */ Atlas::KeyCode::None,
    /* 0x0089 */ Atlas::KeyCode::None,
    /* 0x008A */ Atlas::KeyCode::None,
    /* 0x008B */ Atlas::KeyCode::None,
    /* 0x008C */ Atlas::KeyCode::None,
    /* 0x008D */ Atlas::KeyCode::None,
    /* 0x008E */ Atlas::KeyCode::None,
    /* 0x008F */ Atlas::KeyCode::None,
    /* 0x0090 */ Atlas::KeyCode::NumLock,
    /* 0x0091 */ Atlas::KeyCode::ScrollLock,
    /* 0x0092 */ Atlas::KeyCode::None,
    /* 0x0093 */ Atlas::KeyCode::None,
    /* 0x0094 */ Atlas::KeyCode::None,
    /* 0x0095 */ Atlas::KeyCode::None,
    /* 0x0096 */ Atlas::KeyCode::None,
    /* 0x0097 */ Atlas::KeyCode::None,
    /* 0x0098 */ Atlas::KeyCode::None,
    /* 0x0099 */ Atlas::KeyCode::None,
    /* 0x009A */ Atlas::KeyCode::None,
    /* 0x009B */ Atlas::KeyCode::None,
    /* 0x009C */ Atlas::KeyCode::None,
    /* 0x009D */ Atlas::KeyCode::None,
    /* 0x009E */ Atlas::KeyCode::None,
    /* 0x009F */ Atlas::KeyCode::None,
    /* 0x00A0 */ Atlas::KeyCode::LeftShift,
    /* 0x00A1 */ Atlas::KeyCode::RightShift,
    /* 0x00A2 */ Atlas::KeyCode::LeftControl,
    /* 0x00A3 */ Atlas::KeyCode::RightControl,
    /* 0x00A4 */ Atlas::KeyCode::LeftAlt,
    /* 0x00A5 */ Atlas::KeyCode::RightAlt,
    /* 0x00A6 */ Atlas::KeyCode::WebBack,
    /* 0x00A7 */ Atlas::KeyCode::WebForward,
    /* 0x00A8 */ Atlas::KeyCode::WebRefresh,
    /* 0x00A9 */ Atlas::KeyCode::WebStop,
    /* 0x00AA */ Atlas::KeyCode::WebSearch,
    /* 0x00AB */ Atlas::KeyCode::WebBookmarks,
    /* 0x00AC */ Atlas::KeyCode::WebHome,
    /* 0x00AD */ Atlas::KeyCode::MediaMute,
    /* 0x00AE */ Atlas::KeyCode::MediaVolumeDown,
    /* 0x00AF */ Atlas::KeyCode::MediaVolumeUp,
    /* 0x00B0 */ Atlas::KeyCode::MediaNext,
    /* 0x00B1 */ Atlas::KeyCode::MediaPrevious,
    /* 0x00B2 */ Atlas::KeyCode::MediaStop,
    /* 0x00B3 */ Atlas::KeyCode::MediaPlayPause,
    /* 0x00B4 */ Atlas::KeyCode::Mail,
    /* 0x00B5 */ Atlas::KeyCode::MediaSelect,
    /* 0x00B6 */ Atlas::KeyCode::None,
    /* 0x00B7 */ Atlas::KeyCode::None,
    /* 0x00B8 */ Atlas::KeyCode::None,
    /* 0x00B9 */ Atlas::KeyCode::None,
    /* 0x00BA */ Atlas::KeyCode::Semicolon,
    /* 0x00BB */ Atlas::KeyCode::Plus,
    /* 0x00BC */ Atlas::KeyCode::Comma,
    /* 0x00BD */ Atlas::KeyCode::Minus,
    /* 0x00BE */ Atlas::KeyCode::Period,
    /* 0x00BF */ Atlas::KeyCode::Slash,
    /* 0x00C0 */ Atlas::KeyCode::Grave,
    /* 0x00C1 */ Atlas::KeyCode::None,
    /* 0x00C2 */ Atlas::KeyCode::None,
    /* 0x00C3 */ Atlas::KeyCode::None,
    /* 0x00C4 */ Atlas::KeyCode::None,
    /* 0x00C5 */ Atlas::KeyCode::None,
    /* 0x00C6 */ Atlas::KeyCode::None,
    /* 0x00C7 */ Atlas::KeyCode::None,
    /* 0x00C8 */ Atlas::KeyCode::None,
    /* 0x00C9 */ Atlas::KeyCode::None,
    /* 0x00CA */ Atlas::KeyCode::None,
    /* 0x00CB */ Atlas::KeyCode::None,
    /* 0x00CC */ Atlas::KeyCode::None,
    /* 0x00CD */ Atlas::KeyCode::None,
    /* 0x00CE */ Atlas::KeyCode::None,
    /* 0x00CF */ Atlas::KeyCode::None,
    /* 0x00D0 */ Atlas::KeyCode::None,
    /* 0x00D1 */ Atlas::KeyCode::None,
    /* 0x00D2 */ Atlas::KeyCode::None,
    /* 0x00D3 */ Atlas::KeyCode::None,
    /* 0x00D4 */ Atlas::KeyCode::None,
    /* 0x00D5 */ Atlas::KeyCode::None,
    /* 0x00D6 */ Atlas::KeyCode::None,
    /* 0x00D7 */ Atlas::KeyCode::None,
    /* 0x00D8 */ Atlas::KeyCode::None,
    /* 0x00D9 */ Atlas::KeyCode::None,
    /* 0x00DA */ Atlas::KeyCode::None,
    /* 0x00DB */ Atlas::KeyCode::LeftBracket,
    /* 0x00DC */ Atlas::KeyCode::Backslash,
    /* 0x00DD */ Atlas::KeyCode::RightBracket,
    /* 0x00DE */ Atlas::KeyCode::Apostrophe,
    /* 0x00DF */ Atlas::KeyCode::Grave,
    /* 0x00E0 */ Atlas::KeyCode::None,
    /* 0x00E1 */ Atlas::KeyCode::None,
    /* 0x00E2 */ Atlas::KeyCode::Backslash,
    /* 0x00E3 */ Atlas::KeyCode::None,
    /* 0x00E4 */ Atlas::KeyCode::None,
    /* 0x00E5 */ Atlas::KeyCode::None,
    /* 0x00E6 */ Atlas::KeyCode::None,
    /* 0x00E7 */ Atlas::KeyCode::None,
    /* 0x00E8 */ Atlas::KeyCode::None,
    /* 0x00E9 */ Atlas::KeyCode::None,
    /* 0x00EA */ Atlas::KeyCode::None,
    /* 0x00EB */ Atlas::KeyCode::None,
    /* 0x00EC */ Atlas::KeyCode::None,
    /* 0x00ED */ Atlas::KeyCode::None,
    /* 0x00EE */ Atlas::KeyCode::None,
    /* 0x00EF */ Atlas::KeyCode::None,
    /* 0x00F0 */ Atlas::KeyCode::None,
    /* 0x00F1 */ Atlas::KeyCode::None,
    /* 0x00F2 */ Atlas::KeyCode::None,
    /* 0x00F3 */ Atlas::KeyCode::None,
    /* 0x00F4 */ Atlas::KeyCode::None,
    /* 0x00F5 */ Atlas::KeyCode::None,
    /* 0x00F6 */ Atlas::KeyCode::None,
    /* 0x00F7 */ Atlas::KeyCode::CrSel,
    /* 0x00F8 */ Atlas::KeyCode::ExSel,
    /* 0x00F9 */ Atlas::KeyCode::None,
    /* 0x00FA */ Atlas::KeyCode::None,
    /* 0x00FB */ Atlas::KeyCode::None,
    /* 0x00FC */ Atlas::KeyCode::None,
    /* 0x00FD */ Atlas::KeyCode::None,
    /* 0x00FE */ Atlas::KeyCode::None,
    /* 0x00FF */ Atlas::KeyCode::None,
};

const Atlas::ScanCode scan_code_table[] = {
    /* 0x0000 */ Atlas::ScanCode::None,
    /* 0x0001 */ Atlas::ScanCode::Escape,
    /* 0x0002 */ Atlas::ScanCode::Alpha1,
    /* 0x0003 */ Atlas::ScanCode::Alpha2,
    /* 0x0004 */ Atlas::ScanCode::Alpha3,
    /* 0x0005 */ Atlas::ScanCode::Alpha4,
    /* 0x0006 */ Atlas::ScanCode::Alpha5,
    /* 0x0007 */ Atlas::ScanCode::Alpha6,
    /* 0x0008 */ Atlas::ScanCode::Alpha7,
    /* 0x0009 */ Atlas::ScanCode::Alpha8,
    /* 0x000A */ Atlas::ScanCode::Alpha9,
    /* 0x000B */ Atlas::ScanCode::Alpha0,
    /* 0x000C */ Atlas::ScanCode::Minus,
    /* 0x000D */ Atlas::ScanCode::Equals,
    /* 0x000E */ Atlas::ScanCode::Backspace,
    /* 0x000F */ Atlas::ScanCode::Tab,
    /* 0x0010 */ Atlas::ScanCode::Q,
    /* 0x0011 */ Atlas::ScanCode::W,
    /* 0x0012 */ Atlas::ScanCode::E,
    /* 0x0013 */ Atlas::ScanCode::R,
    /* 0x0014 */ Atlas::ScanCode::T,
    /* 0x0015 */ Atlas::ScanCode::Y,
    /* 0x0016 */ Atlas::ScanCode::U,
    /* 0x0017 */ Atlas::ScanCode::I,
    /* 0x0018 */ Atlas::ScanCode::O,
    /* 0x0019 */ Atlas::ScanCode::P,
    /* 0x001A */ Atlas::ScanCode::LeftBracket,
    /* 0x001B */ Atlas::ScanCode::RightBracket,
    /* 0x001C */ Atlas::ScanCode::Return,
    /* 0x001D */ Atlas::ScanCode::LeftControl,
    /* 0x001E */ Atlas::ScanCode::A,
    /* 0x001F */ Atlas::ScanCode::S,
    /* 0x0020 */ Atlas::ScanCode::D,
    /* 0x0021 */ Atlas::ScanCode::F,
    /* 0x0022 */ Atlas::ScanCode::G,
    /* 0x0023 */ Atlas::ScanCode::H,
    /* 0x0024 */ Atlas::ScanCode::J,
    /* 0x0025 */ Atlas::ScanCode::K,
    /* 0x0026 */ Atlas::ScanCode::L,
    /* 0x0027 */ Atlas::ScanCode::SemiColon,
    /* 0x0028 */ Atlas::ScanCode::Apostrophe,
    /* 0x0029 */ Atlas::ScanCode::Grave,
    /* 0x002A */ Atlas::ScanCode::LeftShift,
    /* 0x002B */ Atlas::ScanCode::Backslash,
    /* 0x002C */ Atlas::ScanCode::Z,
    /* 0x002D */ Atlas::ScanCode::X,
    /* 0x002E */ Atlas::ScanCode::C,
    /* 0x002F */ Atlas::ScanCode::V,
    /* 0x0030 */ Atlas::ScanCode::B,
    /* 0x0031 */ Atlas::ScanCode::N,
    /* 0x0032 */ Atlas::ScanCode::M,
    /* 0x0033 */ Atlas::ScanCode::Comma,
    /* 0x0034 */ Atlas::ScanCode::Period,
    /* 0x0035 */ Atlas::ScanCode::Slash,
    /* 0x0036 */ Atlas::ScanCode::RightShift,
    /* 0x0037 */ Atlas::ScanCode::KeypadMultiply,
    /* 0x0038 */ Atlas::ScanCode::LeftAlt,
    /* 0x0039 */ Atlas::ScanCode::Space,
    /* 0x003A */ Atlas::ScanCode::CapsLock,
    /* 0x003B */ Atlas::ScanCode::F1,
    /* 0x003C */ Atlas::ScanCode::F2,
    /* 0x003D */ Atlas::ScanCode::F3,
    /* 0x003E */ Atlas::ScanCode::F4,
    /* 0x003F */ Atlas::ScanCode::F5,
    /* 0x0040 */ Atlas::ScanCode::F6,
    /* 0x0041 */ Atlas::ScanCode::F7,
    /* 0x0042 */ Atlas::ScanCode::F8,
    /* 0x0043 */ Atlas::ScanCode::F9,
    /* 0x0044 */ Atlas::ScanCode::F10,
    /* 0x0045 */ Atlas::ScanCode::PauseBreak,
    /* 0x0046 */ Atlas::ScanCode::ScrollLock,
    /* 0x0047 */ Atlas::ScanCode::Keypad7,
    /* 0x0048 */ Atlas::ScanCode::Keypad8,
    /* 0x0049 */ Atlas::ScanCode::Keypad9,
    /* 0x004A */ Atlas::ScanCode::KeypadMinus,
    /* 0x004B */ Atlas::ScanCode::Keypad4,
    /* 0x004C */ Atlas::ScanCode::Keypad5,
    /* 0x004D */ Atlas::ScanCode::Keypad6,
    /* 0x004E */ Atlas::ScanCode::KeypadPlus,
    /* 0x004F */ Atlas::ScanCode::Keypad1,
    /* 0x0050 */ Atlas::ScanCode::Keypad2,
    /* 0x0051 */ Atlas::ScanCode::Keypad3,
    /* 0x0052 */ Atlas::ScanCode::Keypad0,
    /* 0x0053 */ Atlas::ScanCode::KeypadPeriod,
    /* 0x0054 */ Atlas::ScanCode::None,
    /* 0x0055 */ Atlas::ScanCode::None,
    /* 0x0056 */ Atlas::ScanCode::NonUSBackslash,
    /* 0x0057 */ Atlas::ScanCode::F11,
    /* 0x0058 */ Atlas::ScanCode::F12,
    /* 0x0059 */ Atlas::ScanCode::KeypadEquals,
    /* 0x005A */ Atlas::ScanCode::None,
    /* 0x005B */ Atlas::ScanCode::None,
    /* 0x005C */ Atlas::ScanCode::International6,
    /* 0x005D */ Atlas::ScanCode::None,
    /* 0x005E */ Atlas::ScanCode::None,
    /* 0x005F */ Atlas::ScanCode::None,
    /* 0x0060 */ Atlas::ScanCode::None,
    /* 0x0061 */ Atlas::ScanCode::None,
    /* 0x0062 */ Atlas::ScanCode::None,
    /* 0x0063 */ Atlas::ScanCode::None,
    /* 0x0064 */ Atlas::ScanCode::F13,
    /* 0x0065 */ Atlas::ScanCode::F14,
    /* 0x0066 */ Atlas::ScanCode::F15,
    /* 0x0067 */ Atlas::ScanCode::F16,
    /* 0x0068 */ Atlas::ScanCode::F17,
    /* 0x0069 */ Atlas::ScanCode::F18,
    /* 0x006A */ Atlas::ScanCode::F19,
    /* 0x006B */ Atlas::ScanCode::F20,
    /* 0x006C */ Atlas::ScanCode::F21,
    /* 0x006D */ Atlas::ScanCode::F22,
    /* 0x006E */ Atlas::ScanCode::F23,
    /* 0x006F */ Atlas::ScanCode::None,
    /* 0x0070 */ Atlas::ScanCode::International2,
    /* 0x0071 */ Atlas::ScanCode::Lang2,
    /* 0x0072 */ Atlas::ScanCode::Lang1,
    /* 0x0073 */ Atlas::ScanCode::International1,
    /* 0x0074 */ Atlas::ScanCode::None,
    /* 0x0075 */ Atlas::ScanCode::None,
    /* 0x0076 */ Atlas::ScanCode::F24,
    /* 0x0077 */ Atlas::ScanCode::Lang4,
    /* 0x0078 */ Atlas::ScanCode::Lang3,
    /* 0x0079 */ Atlas::ScanCode::International4,
    /* 0x007A */ Atlas::ScanCode::None,
    /* 0x007B */ Atlas::ScanCode::International5,
    /* 0x007C */ Atlas::ScanCode::None,
    /* 0x007D */ Atlas::ScanCode::International3,
    /* 0x007E */ Atlas::ScanCode::KeypadComma,
    /* 0x007F */ Atlas::ScanCode::None,
    /* 0xE000 */ Atlas::ScanCode::None,
    /* 0xE001 */ Atlas::ScanCode::None,
    /* 0xE002 */ Atlas::ScanCode::None,
    /* 0xE003 */ Atlas::ScanCode::None,
    /* 0xE004 */ Atlas::ScanCode::None,
    /* 0xE005 */ Atlas::ScanCode::None,
    /* 0xE006 */ Atlas::ScanCode::None,
    /* 0xE007 */ Atlas::ScanCode::None,
    /* 0xE008 */ Atlas::ScanCode::None,
    /* 0xE009 */ Atlas::ScanCode::None,
    /* 0xE00A */ Atlas::ScanCode::None,
    /* 0xE00B */ Atlas::ScanCode::None,
    /* 0xE00C */ Atlas::ScanCode::None,
    /* 0xE00D */ Atlas::ScanCode::None,
    /* 0xE00E */ Atlas::ScanCode::None,
    /* 0xE00F */ Atlas::ScanCode::None,
    /* 0xE010 */ Atlas::ScanCode::MediaPrevious,
    /* 0xE011 */ Atlas::ScanCode::None,
    /* 0xE012 */ Atlas::ScanCode::None,
    /* 0xE013 */ Atlas::ScanCode::None,
    /* 0xE014 */ Atlas::ScanCode::None,
    /* 0xE015 */ Atlas::ScanCode::None,
    /* 0xE016 */ Atlas::ScanCode::None,
    /* 0xE017 */ Atlas::ScanCode::None,
    /* 0xE018 */ Atlas::ScanCode::None,
    /* 0xE019 */ Atlas::ScanCode::MediaNext,
    /* 0xE01A */ Atlas::ScanCode::None,
    /* 0xE01B */ Atlas::ScanCode::None,
    /* 0xE01C */ Atlas::ScanCode::KeypadEnter,
    /* 0xE01D */ Atlas::ScanCode::RightControl,
    /* 0xE01E */ Atlas::ScanCode::None,
    /* 0xE01F */ Atlas::ScanCode::None,
    /* 0xE020 */ Atlas::ScanCode::Mute,
    /* 0xE021 */ Atlas::ScanCode::Calculator,
    /* 0xE022 */ Atlas::ScanCode::MediaPlayPause,
    /* 0xE023 */ Atlas::ScanCode::None,
    /* 0xE024 */ Atlas::ScanCode::Stop,
    /* 0xE025 */ Atlas::ScanCode::None,
    /* 0xE026 */ Atlas::ScanCode::None,
    /* 0xE027 */ Atlas::ScanCode::None,
    /* 0xE028 */ Atlas::ScanCode::None,
    /* 0xE029 */ Atlas::ScanCode::None,
    /* 0xE02A */ Atlas::ScanCode::None,
    /* 0xE02B */ Atlas::ScanCode::None,
    /* 0xE02C */ Atlas::ScanCode::None,
    /* 0xE02D */ Atlas::ScanCode::None,
    /* 0xE02E */ Atlas::ScanCode::MediaVolumeDown,
    /* 0xE02F */ Atlas::ScanCode::None,
    /* 0xE030 */ Atlas::ScanCode::MediaVolumeUp,
    /* 0xE031 */ Atlas::ScanCode::None,
    /* 0xE032 */ Atlas::ScanCode::WebHome,
    /* 0xE033 */ Atlas::ScanCode::None,
    /* 0xE034 */ Atlas::ScanCode::None,
    /* 0xE035 */ Atlas::ScanCode::KeypadDivide,
    /* 0xE036 */ Atlas::ScanCode::None,
    /* 0xE037 */ Atlas::ScanCode::PrintScreen,
    /* 0xE038 */ Atlas::ScanCode::RightAlt,
    /* 0xE039 */ Atlas::ScanCode::None,
    /* 0xE03A */ Atlas::ScanCode::None,
    /* 0xE03B */ Atlas::ScanCode::None,
    /* 0xE03C */ Atlas::ScanCode::None,
    /* 0xE03D */ Atlas::ScanCode::None,
    /* 0xE03E */ Atlas::ScanCode::None,
    /* 0xE03F */ Atlas::ScanCode::None,
    /* 0xE040 */ Atlas::ScanCode::None,
    /* 0xE041 */ Atlas::ScanCode::None,
    /* 0xE042 */ Atlas::ScanCode::None,
    /* 0xE043 */ Atlas::ScanCode::None,
    /* 0xE044 */ Atlas::ScanCode::None,
    /* 0xE045 */ Atlas::ScanCode::NumLock,
    /* 0xE046 */ Atlas::ScanCode::PauseBreak,
    /* 0xE047 */ Atlas::ScanCode::Home,
    /* 0xE048 */ Atlas::ScanCode::UpArrow,
    /* 0xE049 */ Atlas::ScanCode::PageUp,
    /* 0xE04A */ Atlas::ScanCode::None,
    /* 0xE04B */ Atlas::ScanCode::LeftArrow,
    /* 0xE04C */ Atlas::ScanCode::None,
    /* 0xE04D */ Atlas::ScanCode::RightArrow,
    /* 0xE04E */ Atlas::ScanCode::None,
    /* 0xE04F */ Atlas::ScanCode::End,
    /* 0xE050 */ Atlas::ScanCode::DownArrow,
    /* 0xE051 */ Atlas::ScanCode::PageDown,
    /* 0xE052 */ Atlas::ScanCode::Insert,
    /* 0xE053 */ Atlas::ScanCode::Delete,
    /* 0xE054 */ Atlas::ScanCode::None,
    /* 0xE055 */ Atlas::ScanCode::None,
    /* 0xE056 */ Atlas::ScanCode::None,
    /* 0xE057 */ Atlas::ScanCode::None,
    /* 0xE058 */ Atlas::ScanCode::None,
    /* 0xE059 */ Atlas::ScanCode::None,
    /* 0xE05A */ Atlas::ScanCode::None,
    /* 0xE05B */ Atlas::ScanCode::LeftGUI,
    /* 0xE05C */ Atlas::ScanCode::RightGUI,
    /* 0xE05D */ Atlas::ScanCode::Application,
    /* 0xE05E */ Atlas::ScanCode::Power,
    /* 0xE05F */ Atlas::ScanCode::SystemSleep,
    /* 0xE060 */ Atlas::ScanCode::None,
    /* 0xE061 */ Atlas::ScanCode::None,
    /* 0xE062 */ Atlas::ScanCode::None,
    /* 0xE063 */ Atlas::ScanCode::SystemWake,
    /* 0xE064 */ Atlas::ScanCode::None,
    /* 0xE065 */ Atlas::ScanCode::WebSearch,
    /* 0xE066 */ Atlas::ScanCode::WebBookmarks,
    /* 0xE067 */ Atlas::ScanCode::WebRefresh,
    /* 0xE068 */ Atlas::ScanCode::WebStop,
    /* 0xE069 */ Atlas::ScanCode::WebForward,
    /* 0xE06A */ Atlas::ScanCode::WebBack,
    /* 0xE06B */ Atlas::ScanCode::Browser,
    /* 0xE06C */ Atlas::ScanCode::Mail,
    /* 0xE06D */ Atlas::ScanCode::MediaSelect,
    /* 0xE06E */ Atlas::ScanCode::None,
    /* 0xE06F */ Atlas::ScanCode::None,
    /* 0xE070 */ Atlas::ScanCode::None,
    /* 0xE071 */ Atlas::ScanCode::None,
    /* 0xE072 */ Atlas::ScanCode::None,
    /* 0xE073 */ Atlas::ScanCode::None,
    /* 0xE074 */ Atlas::ScanCode::None,
    /* 0xE075 */ Atlas::ScanCode::None,
    /* 0xE076 */ Atlas::ScanCode::None,
    /* 0xE077 */ Atlas::ScanCode::None,
    /* 0xE078 */ Atlas::ScanCode::None,
    /* 0xE079 */ Atlas::ScanCode::None,
    /* 0xE07A */ Atlas::ScanCode::None,
    /* 0xE07B */ Atlas::ScanCode::None,
    /* 0xE07C */ Atlas::ScanCode::None,
    /* 0xE07D */ Atlas::ScanCode::None,
    /* 0xE07E */ Atlas::ScanCode::None,
    /* 0xE07F */ Atlas::ScanCode::None,
};

KeyCode translate_key_code(USHORT key_code)
{
    Debug::assert(
        key_code <= 0x00FF, "Error translating key code, invalid key code");

    return key_code_table[static_cast<Nat8>(key_code)];
}

ScanCode translate_scan_code(USHORT scan_code)
{
    Debug::assert(
        scan_code <= 0x07F || scan_code >= 0xE000 && scan_code <= 0xE07F,
        "Error translating scan code, invalid scan code");

    // Offset scan codes 0xE000 and above to correctly index translation table
    if (scan_code > 0x7F) {
        scan_code = (scan_code & 0x0FFF) + 0x80;
    }
    return scan_code_table[static_cast<Nat8>(scan_code)];
}

MouseButton translate_mouse_button(USHORT mouse_button)
{
    switch (mouse_button) {
        case 0x0001:
        case 0x0002: return Atlas::MouseButton::Left;
        case 0x0004:
        case 0x0008: return Atlas::MouseButton::Right;
        case 0x0010:
        case 0x0020: return Atlas::MouseButton::Middle;
        case 0x0040:
        case 0x0080: return Atlas::MouseButton::X1;
        case 0x0100:
        case 0x0200: return Atlas::MouseButton::X2;
    }
    return Atlas::MouseButton::None;
}
}  // namespace Atlas::Win32
