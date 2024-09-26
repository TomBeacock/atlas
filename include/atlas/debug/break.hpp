#pragma once

namespace Atlas::Debug {
#ifdef ATLAS_CONFIG_DEBUG
/**
 * @brief Debug break.
 */
void debug_break();
#else
void debug_break() {}
#endif
}  // namespace Atlas::Debug
