#include <windows.h>
#include <cstdio>
#include <iostream>

#include "Misc.h"

uintptr_t WINAPI cheatEntry(HMODULE hModule)
{
    AllocConsole();
    FILE* f;

    freopen_s(&f, "CONOUT$", "w", stdout);

    std::cout << "Injection succeded!" << std::endl;
    
    Misc cheats;
    cheats.setAntiflash(true);
    cheats.setBunnyHop(true);
    cheats.setGlowEsp(true);
    cheats.setTriggerBot(false);
    cheats.setEnemiesGlowing(true);
    cheats.setTeamMatesGlowing(true);

    while (true) 
    {
        cheats.loadEntityList();
        
        ////////////////////
        //cheats.triggerBot();
        cheats.bunnyHop();
        cheats.glowESP();
        cheats.antiFlash();
        cheats.aimBot();

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
            CloseHandle(CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)cheatEntry, &hModule, 0, NULL));
            break;
        }
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}

