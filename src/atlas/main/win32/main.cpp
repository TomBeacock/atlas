#include "atlas/system/win32/win32.hpp"
#include "atlas/window/win32/window.hpp"

#include <stdlib.h>

extern int main(int argc, char **argv);

int WINAPI wWinMain(_In_ HINSTANCE instanceHandle,
    _In_opt_ HINSTANCE prevInstanceHandle, _In_ PWSTR cmdLine, _In_ int showCmd)
{
    main(__argc, __argv);
}
