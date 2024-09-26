#pragma once

#include <source_location>
#include <string_view>

namespace Atlas::Debug {
#ifdef ATLAS_CONFIG_DEBUG
/**
 * @brief Assert condition is true.
 * @param condition The condition.
 * @param message The message to print if condition failed.
 * @param location The source location of the caller.
 */
void assert(bool condition, const std::string_view message,
    const std::source_location location = std::source_location::current());
#else
void assert(
    const std::source_location location = std::source_location::current())
{
}
#endif
}  // namespace Atlas::Debug
