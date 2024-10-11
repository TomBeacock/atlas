#pragma once

#include <string>

namespace Atlas::Win32 {
/**
 * Converts a utf8 string to wide string
 *
 * @param str Utf8 string
 *
 * @return Wide string
 */
std::wstring utf8_to_wstring(const std::string &str);

/**
 * Converts a wide string to utf8 string
 *
 * @param str Wide string
 *
 * @return Utf8 string
 */
std::string wstring_to_utf8(const std::wstring &str);
}  // namespace Atlas::Win32
