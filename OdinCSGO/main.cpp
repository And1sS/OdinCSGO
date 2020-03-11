#include <windows.h>
#include <cstdio>
#include <iostream>

#include "Interfaces.h"
#include "Misc.h"
#include "Visuals.h"

uintptr_t WINAPI cheatEntry(HMODULE hModule)
{
    AllocConsole();
    FILE* f;

    freopen_s(&f, "CONOUT$", "w", stdout);
    std::cout << "Injection succeded!" << std::endl;
    
    Interfaces::initialize();

    Visuals  visuals;
    Aim      aim;
    Misc     misc;

    misc.setAntiflash(true);
    misc.setBunnyHop(true);
    misc.setTriggerBot(false);

    while (true) 
    {
        misc.bunnyHop();
        misc.antiFlash();
        visuals.run();
        aim.run();

        if (GetAsyncKeyState(VK_INSERT))
        {
            std::cout << "Uninjected" << std::endl;
            break;
        }
    }

    FreeConsole();
    FreeLibraryAndExitThread(hModule, 1);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       uintptr_t  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
        {
            auto handle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)cheatEntry, &hModule, 0, NULL);

            if (handle != NULL)
                CloseHandle(handle);

            break;
        }
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}

