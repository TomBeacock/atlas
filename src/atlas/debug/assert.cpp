#include "atlas/debug/assert.hpp"

#ifdef ATLAS_CONFIG_DEBUG

  #include "atlas/debug/break.hpp"
  #include "atlas/debug/log.hpp"

  #include <format>

namespace Atlas::Debug {

void assert(bool condition, const std::string_view message,
    const std::source_location location)
{
    if (!condition) {
        log_error(std::format("Assertion failed: {}", message), location);
        debug_break();
    }
}
}  // namespace Atlas::Debug

#endif
