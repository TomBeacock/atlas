#include "atlas/debug/log.hpp"

#ifdef ATLAS_CONFIG_DEBUG

  #include "atlas/types.hpp"

  #include <filesystem>
  #include <format>
  #include <iostream>

namespace Atlas::Debug {
static void log(const std::string_view message,
    const std::source_location location, Int color_code)
{
    std::string filename
        = std::filesystem::path(location.file_name()).filename().string();
    std::clog << std::format("\x1B[{}m{} ({}:{}): {}\x1B[39m\n", color_code,
        filename, location.line(), location.column(), message);
}

void log_info(
    const std::string_view message, const std::source_location location)
{
    log(message, location, 39);
}

void log_warning(
    const std::string_view message, const std::source_location location)
{
    log(message, location, 93);
}

void log_error(
    const std::string_view message, const std::source_location location)
{
    log(message, location, 91);
}

void log_success(
    const std::string_view message, const std::source_location location)
{
    log(message, location, 92);
}
}  // namespace Atlas::Debug

#endif
