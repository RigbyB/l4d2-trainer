#include <exception>
#include <Windows.h>

#include "interfaces.h"

DWORD WINAPI init_thread(LPVOID lpParam)
{
    try
    {
        interfaces::populate_interfaces();
    }
    catch (const std::exception& exception)
    {
        MessageBoxA(nullptr, exception.what(), "An initialization error has occured", MB_ICONERROR);
        // TODO: Unhook here
        FreeLibraryAndExitThread(static_cast<HMODULE>(lpParam), 0);
    }

    return 0;
}

BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,
    DWORD fdwReason,
    LPVOID)
{
    if (fdwReason == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hinstDLL);
        CreateThread(nullptr, 0, init_thread, hinstDLL, 0, nullptr);
    }

    return TRUE;
}
