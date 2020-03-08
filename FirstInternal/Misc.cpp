#include "Misc.h"

Misc::Misc() {}

void Misc::printEntitiesInfo()
{
    auto indent = [] { std::cout << std::endl << std::endl; };

    if (!Engine::getLocalPlayer().isValid())
        return;

    auto entityList = Engine::getEntityList();

    system("cls");
    std::cout << "debug mode" << std::endl;
    std::cout << "************LOCAL PLAYER************" << std::endl;
    Engine::getLocalPlayer().printInfo();
    indent();
    std::cout << "********ENTITIES LIST********" << std::endl;
    for (auto i = 0; i < entityList.size(); i++)
    {
        std::cout << "entity #" << i << " ";

        entityList[i].printInfo();
        indent();
    }
}

void Misc::antiFlash()
{
    if (!antiflashEnabled || !Engine::getLocalPlayer().isValid())
        return;

    float& flashDuration = *reinterpret_cast<float*>(Engine::getLocalPlayer().getBase()
        + hazedumper::netvars::m_flFlashDuration);

    if (flashDuration > 0)
        flashDuration = 0;                            
}

void Misc::bunnyHop()
{
    if (!bunnyhopEnabled || !Engine::getLocalPlayer().isValid())
        return;

    BYTE& flag = *reinterpret_cast<BYTE*>(Engine::getLocalPlayer().getBase()
        + hazedumper::netvars::m_fFlags);

    if (GetAsyncKeyState(VK_SPACE) && (flag & FL_ONGROUND))
    {
        uint32_t* pState = reinterpret_cast<uint32_t*>(Utilities::getClientBase()
            + hazedumper::signatures::dwForceJump);

         if (pState != NULL)
             *pState =  6;                                                                       
    }
}

void Misc::triggerBot()
{
    if (!triggerBotEnabled || !Engine::getLocalPlayer().isValid()
        || Engine::getLocalPlayer().getHealth() == 0)
        return;

    uint32_t entityInCrosshairId = *reinterpret_cast<uint32_t*>(Engine::getLocalPlayer().getBase()
            + hazedumper::netvars::m_iCrosshairId) - 1;
    
    uintptr_t pEntityInCrosshair = *reinterpret_cast<uintptr_t*>(Utilities::getClientBase()
            + hazedumper::signatures::dwEntityList + entityInCrosshairId * 0x10);
   
    if (pEntityInCrosshair == NULL || entityInCrosshairId >= MAX_ENTITIES || entityInCrosshairId <= 0)
        return;

    CBaseEntity entityInCrosshair(pEntityInCrosshair, entityInCrosshairId);
    if (entityInCrosshair.getTeam() == Engine::getLocalPlayer().getTeam())
        return;

    uint32_t* pForceAttack = reinterpret_cast<uint32_t*>(Utilities::getClientBase()
        + hazedumper::signatures::dwForceAttack);
    if (pForceAttack == NULL)
        return;

    *pForceAttack = 5;
    Sleep(5);
    *pForceAttack = 4;
}

void Misc::setBunnyHop(bool enabled)
{
    bunnyhopEnabled = enabled;
}

void Misc::setAntiflash(bool enabled)
{
    antiflashEnabled = enabled;
}

void Misc::setTriggerBot(bool enabled)
{
    triggerBotEnabled = enabled;
}

