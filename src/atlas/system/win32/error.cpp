#include "atlas/system/win32/error.hpp"

#include "atlas/system/win32/string.hpp"
#include "atlas/system/win32/win32.hpp"

#include <format>

namespace Atlas::Win32 {
std::string get_last_error_message()
{
    WCHAR *msg_buffer = nullptr;
    DWORD error_code = GetLastError();

    FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM
                      | FORMAT_MESSAGE_IGNORE_INSERTS,
        nullptr, error_code, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        reinterpret_cast<LPWSTR>(&msg_buffer), 0, nullptr);

    return wstring_to_utf8(
        std::format(L"Win32 error {}: {}", error_code, msg_buffer));
}
}  // namespace Atlas::Win32
