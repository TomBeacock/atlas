#include "atlas/debug/break.hpp"

#ifdef ATLAS_CONFIG_DEBUG
  #ifdef ATLAS_PLATFORM_UNIX
    #include <signal.h>
  #endif

namespace Atlas::Debug {
void debug_break()
{
  #ifdef ATLAS_PLATFORM_WIN32
    __debugbreak();
  #elifdef ATLAS_PLATFORM_UNIX
    raise(SIGTRAP)
  #endif
}
}  // namespace Atlas::Debug

#endif
