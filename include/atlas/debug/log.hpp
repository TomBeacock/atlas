#pragma once

#include <source_location>
#include <string>

namespace Atlas::Debug {
#ifdef ATLAS_CONFIG_DEBUG
/**
 * @brief Log an information message to the console.
 * @param message The message.
 * @param location The source location of the caller.
 */
void log_info(const std::string_view message,
    const std::source_location location = std::source_location::current());

/**
 * @brief Log a warning message to the console.
 * @param message The message.
 * @param location The source location of the caller.
 */
void log_warning(const std::string_view message,
    const std::source_location location = std::source_location::current());

/**
 * @brief Log an error message to the console.
 * @param message The message.
 * @param location The source location of the caller.
 */
void log_error(const std::string_view message,
    const std::source_location location = std::source_location::current());

/**
 * @brief Log a success message to the console.
 * @param message The message.
 * @param location The source location of the caller.
 */
void log_success(const std::string_view message,
    const std::source_location location = std::source_location::current());
#else
void log_info(const std::string_view message,
    const std::source_location location = std::source_location::current())
{
}

void log_warning(const std::string_view message,
    const std::source_location location = std::source_location::current())
{
}

void log_error(const std::string_view message,
    const std::source_location location = std::source_location::current())
{
}

void log_success(const std::string_view message,
    const std::source_location location = std::source_location::current())
{
}
#endif
}  // namespace Atlas::Debug
