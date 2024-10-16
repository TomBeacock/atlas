#pragma once

#include "atlas/types.hpp"

#include <cstdint>
#include <format>
#include <ostream>

namespace Atlas {
enum class KeyCode : Nat16 {
    // Ascii keys
    None = '\0',
    Backspace = '\b',
    Tab = '\t',
    Return = '\r',
    Escape = '\033',
    Space = ' ',
    Exclaimation = '!',
    DoubleQuote = '\"',
    Hash = '#',
    Dollar = '$',
    Percent = '%',
    Ampersand = '&',
    Apostrophe = '\'',
    Asterisk = '*',
    Plus = '+',
    Comma = ',',
    Minus = '-',
    Period = '.',
    Slash = '/',
    Alpha0 = '0',
    Alpha1 = '1',
    Alpha2 = '2',
    Alpha3 = '3',
    Alpha4 = '4',
    Alpha5 = '5',
    Alpha6 = '6',
    Alpha7 = '7',
    Alpha8 = '8',
    Alpha9 = '9',
    Semicolon = ';',
    LessThan = '<',
    Equals = '=',
    GreaterThan = '>',
    Question = '?',
    At = '@',
    LeftBracket = '[',
    Backslash = '\\',
    RightBracket = ']',
    Caret = '^',
    Underscore = '_',
    Grave = '`',
    A = 'a',
    B = 'b',
    C = 'c',
    D = 'd',
    E = 'e',
    F = 'f',
    G = 'g',
    H = 'h',
    I = 'i',
    J = 'j',
    K = 'k',
    L = 'l',
    M = 'm',
    N = 'n',
    O = 'o',
    P = 'p',
    Q = 'q',
    R = 'r',
    S = 's',
    T = 't',
    U = 'u',
    V = 'v',
    W = 'w',
    X = 'x',
    Y = 'y',
    Z = 'z',
    Delete = '\177',
    // Non-ascii keys
    F1 = 0x703A,
    F2 = 0x703B,
    F3 = 0x703C,
    F4 = 0x703D,
    F5 = 0x703E,
    F6 = 0x703F,
    F7 = 0x7040,
    F8 = 0x7041,
    F9 = 0x7042,
    F10 = 0x7043,
    F11 = 0x7044,
    F12 = 0x7045,
    F13 = 0x7068,
    F14 = 0x7069,
    F15 = 0x706A,
    F16 = 0x706B,
    F17 = 0x706C,
    F18 = 0x706D,
    F19 = 0x706E,
    F20 = 0x706F,
    F21 = 0x7070,
    F22 = 0x7071,
    F23 = 0x7072,
    F24 = 0x7073,
    PrintScreen = 0x7046,
    ScrollLock = 0x7047,
    PauseBreak = 0x7048,
    CapsLock = 0x7039,
    Insert = 0x7049,
    Home = 0x704A,
    PageUp = 0x704B,
    End = 0x704D,
    PageDown = 0x704E,
    RightArrow = 0x704F,
    LeftArrow = 0x7050,
    DownArrow = 0x7051,
    UpArrow = 0x7052,
    NumLock = 0x7053,
    KeypadDivide = 0x7054,
    KeypadMultiply = 0x7055,
    KeypadMinus = 0x7056,
    KeypadPlus = 0x7057,
    KeypadEnter = 0x7058,
    Keypad1 = 0x7059,
    Keypad2 = 0x705A,
    Keypad3 = 0x705B,
    Keypad4 = 0x705C,
    Keypad5 = 0x705D,
    Keypad6 = 0x705E,
    Keypad7 = 0x705F,
    Keypad8 = 0x7060,
    Keypad9 = 0x7061,
    Keypad0 = 0x7062,
    KeypadPeriod = 0x7063,
    KeypadEquals = 0x7067,
    NonUSBackslash = 0x7064,
    Application = 0x7065,
    Execute = 0x7074,
    Help = 0x7075,
    Menu = 0x7076,
    Select = 0x7077,
    Stop = 0x7078,
    Again = 0x7079,
    Undo = 0x707A,
    Cut = 0x707B,
    Copy = 0x707C,
    Paste = 0x707D,
    Find = 0x707E,
    Mute = 0x707F,
    Power = 0x7066,
    Clear = 0x709C,
    CrSel = 0x70A3,
    ExSel = 0x70A4,
    Separator = 0x709F,
    LeftControl = 0x70E0,
    LeftShift = 0x70E1,
    LeftAlt = 0x70E2,
    LeftGUI = 0x70E3,
    RightControl = 0x70E4,
    RightShift = 0x70E5,
    RightAlt = 0x70E6,
    RightGUI = 0x70E7,

    SystemPower = 0x1081,
    SystemSleep = 0x1082,
    SystemWake = 0x1083,

    MediaNext = 0xC0B5,
    MediaPrevious = 0xC0B6,
    MediaStop = 0xC0B7,
    MediaPlayPause = 0xC0CD,
    MediaMute = 0xC0E2,
    MediaVolumeUp = 0xC0E9,
    MediaVolumeDown = 0xC0EA,
    MediaSelect = 0xC183,
    Mail = 0xC18A,
    Calculator = 0xC192,
    Browser = 0xC194,
    WebSearch = 0xC221,
    WebHome = 0xC223,
    WebBack = 0xC224,
    WebForward = 0xC225,
    WebStop = 0xC226,
    WebRefresh = 0xC227,
    WebBookmarks = 0xC22A,
};

enum class ScanCode : Nat16 {
    // Keyboard and keypad. HID page 0x0007
    None = 0x00,
    A = 0x04,
    B = 0x05,
    C = 0x06,
    D = 0x07,
    E = 0x08,
    F = 0x09,
    G = 0x0A,
    H = 0x0B,
    I = 0x0C,
    J = 0x0D,
    K = 0x0E,
    L = 0x0F,
    M = 0x10,
    N = 0x11,
    O = 0x12,
    P = 0x13,
    Q = 0x14,
    R = 0x15,
    S = 0x16,
    T = 0x17,
    U = 0x18,
    V = 0x19,
    W = 0x1A,
    X = 0x1B,
    Y = 0x1C,
    Z = 0x1D,
    Alpha1 = 0x1E,
    Alpha2 = 0x1F,
    Alpha3 = 0x20,
    Alpha4 = 0x21,
    Alpha5 = 0x22,
    Alpha6 = 0x23,
    Alpha7 = 0x24,
    Alpha8 = 0x25,
    Alpha9 = 0x26,
    Alpha0 = 0x27,
    Return = 0x28,
    Escape = 0x29,
    Backspace = 0x2A,
    Tab = 0x2B,
    Space = 0x2C,
    Minus = 0x2D,
    Equals = 0x2E,
    LeftBracket = 0x2F,
    RightBracket = 0x30,
    Backslash = 0x31,
    NonUSHash = 0x32,
    SemiColon = 0x33,
    Apostrophe = 0x34,
    Grave = 0x35,
    Comma = 0x36,
    Period = 0x37,
    Slash = 0x38,
    CapsLock = 0x39,
    F1 = 0x3A,
    F2 = 0x3B,
    F3 = 0x3C,
    F4 = 0x3D,
    F5 = 0x3E,
    F6 = 0x3F,
    F7 = 0x40,
    F8 = 0x41,
    F9 = 0x42,
    F10 = 0x43,
    F11 = 0x44,
    F12 = 0x45,
    PrintScreen = 0x46,
    ScrollLock = 0x47,
    PauseBreak = 0x48,
    Insert = 0x49,
    Home = 0x4A,
    PageUp = 0x4B,
    Delete = 0x4C,
    End = 0x4D,
    PageDown = 0x4E,
    RightArrow = 0x4F,
    LeftArrow = 0x50,
    DownArrow = 0x51,
    UpArrow = 0x52,
    NumLock = 0x53,
    KeypadDivide = 0x54,
    KeypadMultiply = 0x55,
    KeypadMinus = 0x56,
    KeypadPlus = 0x57,
    KeypadEnter = 0x58,
    Keypad1 = 0x59,
    Keypad2 = 0x5A,
    Keypad3 = 0x5B,
    Keypad4 = 0x5C,
    Keypad5 = 0x5D,
    Keypad6 = 0x5E,
    Keypad7 = 0x5F,
    Keypad8 = 0x60,
    Keypad9 = 0x61,
    Keypad0 = 0x62,
    KeypadPeriod = 0x63,
    NonUSBackslash = 0x64,
    Application = 0x65,
    Power = 0x66,
    KeypadEquals = 0x67,
    F13 = 0x68,
    F14 = 0x69,
    F15 = 0x6A,
    F16 = 0x6B,
    F17 = 0x6C,
    F18 = 0x6D,
    F19 = 0x6E,
    F20 = 0x6F,
    F21 = 0x70,
    F22 = 0x71,
    F23 = 0x72,
    F24 = 0x73,
    Execute = 0x74,
    Help = 0x75,
    Menu = 0x76,
    Select = 0x77,
    Stop = 0x78,
    Again = 0x79,
    Undo = 0x7A,
    Cut = 0x7B,
    Copy = 0x7C,
    Paste = 0x7D,
    Find = 0x7E,
    Mute = 0x7F,
    VolumeUp = 0x80,
    VolumeDown = 0x81,
    KeypadComma = 0x85,
    KeypadEqualsAS400 = 0x86,
    International1 = 0x87,
    International2 = 0x88,
    International3 = 0x89,
    International4 = 0x8A,
    International5 = 0x8B,
    International6 = 0x8C,
    International7 = 0x8D,
    International8 = 0x8E,
    International9 = 0x8F,
    Lang1 = 0x90,
    Lang2 = 0x91,
    Lang3 = 0x92,
    Lang4 = 0x93,
    Lang5 = 0x94,
    Lang6 = 0x95,
    Lang7 = 0x96,
    Lang8 = 0x97,
    Lang9 = 0x98,
    AltErase = 0x99,
    SysReq = 0x9A,
    Cancel = 0x9B,
    Clear = 0x9C,
    Prior = 0x9D,
    Return2 = 0x9E,
    Separator = 0x9F,
    Out = 0xA0,
    Oper = 0xA1,
    ClearAgain = 0xA2,
    CrSel = 0xA3,
    ExSel = 0xA4,
    LeftControl = 0xE0,
    LeftShift = 0xE1,
    LeftAlt = 0xE2,
    LeftGUI = 0xE3,
    RightControl = 0xE4,
    RightShift = 0xE5,
    RightAlt = 0xE6,
    RightGUI = 0xE7,
    // System. HID page 0x0001 (prefixed with 0x1000)
    SystemPower = 0x1081,
    SystemSleep = 0x1082,
    SystemWake = 0x1083,
    // Consumer. HID page 0x000C (prefixed with 0xC000)
    MediaNext = 0xC0B5,
    MediaPrevious = 0xC0B6,
    MediaStop = 0xC0B7,
    MediaPlayPause = 0xC0CD,
    MediaMute = 0xC0E2,
    MediaVolumeUp = 0xC0E9,
    MediaVolumeDown = 0xC0EA,
    MediaSelect = 0xC183,
    Mail = 0xC18A,
    Calculator = 0xC192,
    Browser = 0xC194,
    WebSearch = 0xC221,
    WebHome = 0xC223,
    WebBack = 0xC224,
    WebForward = 0xC225,
    WebStop = 0xC226,
    WebRefresh = 0xC227,
    WebBookmarks = 0xC22A,
};

inline std::string to_string(KeyCode key_code);
inline std::string to_string(ScanCode scan_code);

inline std::ostream &operator<<(std::ostream &os, KeyCode key_code);
inline std::ostream &operator<<(std::ostream &os, ScanCode scan_code);
}  // namespace Atlas

template<>
struct std::formatter<Atlas::KeyCode> {
    constexpr auto parse(std::format_parse_context &ctx) { return ctx.begin(); }

    auto format(const Atlas::KeyCode &key_code, std::format_context &ctx) const
    {
        auto val = std::to_underlying(key_code);
        if (val >= ' ' && val <= 'z') {
            return std::format_to(
                ctx.out(), "{} ('{}')", val, static_cast<char>(val));
        }
        return std::format_to(ctx.out(), "{}", val);
    }
};

template<>
struct std::formatter<Atlas::ScanCode> {
    constexpr auto parse(std::format_parse_context &ctx) { return ctx.begin(); }

    auto format(
        const Atlas::ScanCode &scan_code, std::format_context &ctx) const
    {
        auto val = std::to_underlying(scan_code);
        return std::format_to(ctx.out(), "{}", val);
    }
};

#include "key_codes.inl"
