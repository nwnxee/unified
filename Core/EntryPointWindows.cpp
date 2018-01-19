#include "NWNXCore.hpp"
#include <memory>
#include <windows.h>

std::unique_ptr<Core::NWNXCore> g_hook;

DWORD WINAPI ThreadMain(LPVOID lpParam)
{
    // This is thread unsafe. It happens on the non-main thread.
    // We could hook while something is using that same function.
    g_hook = std::make_unique<Core::NWNXCore>();
    return true;
}

BOOL WINAPI DllMain(HINSTANCE inst, DWORD fdwReason, LPVOID)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // We make a new thread here to construct the hook because otherwise we'll deadlock when starting the Tasks async worker thread.
            DisableThreadLibraryCalls(inst);
            CreateThread(NULL, 0, ThreadMain, NULL, 0, NULL);
            break;

        case DLL_PROCESS_DETACH:
            g_hook.reset();
            break;
    }

    return true;
}
