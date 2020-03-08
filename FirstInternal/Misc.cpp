#include "Misc.h"

Misc::Misc() {}

uintptr_t Misc::getGlowObjectManager()
{
    return *reinterpret_cast<uintptr_t*>(Utilities::getClientBase()
            + hazedumper::signatures::dwGlowObjectManager);
}

void Misc::loadEntityList()
{
    entityList = Engine::getEntityList();
}

void Misc::printEntitiesInfo()
{
    if (!Engine::getLocalPlayer().isValid())
        return;

    system("cls");
    std::cout << "debug mode" << std::endl;
    std::cout << "************LOCAL PLAYER************" << std::endl;

    Engine::getLocalPlayer().printInfo();

    std::cout << std::endl << std::endl;

    std::cout << "********ENTITIES LIST********" << std::endl;
    for (auto i = 0; i < entityList.size(); i++)
    {
        std::cout << "entity #" << i << " ";

        entityList[i].printInfo();

        std::cout << std::endl << std::endl;
    }
}

void Misc::glowESP()
{
    if (!glowEspEnabled || !Engine::getLocalPlayer().isValid())
        return;

    uintptr_t pGlowObjectManager = getGlowObjectManager();
    if (pGlowObjectManager == NULL)
        return;

    for (CBaseEntity entity : entityList)
    {
        if (!entity.isValid() || !entity.isAlive() || entity.isDormant())
            continue;

        if (entity.getBase() != Engine::getLocalPlayer().getBase())
        {
            Color entityGlowColor;
            if (entity.getTeam() == Engine::getLocalPlayer().getTeam())
            {
                if (!glowTeamMates)
                    continue;
                entityGlowColor = teammateColors;
            }
            else
            {
                if (!glowEnemies)
                    continue;
                entityGlowColor = enemyColors;
            }
            
            uintptr_t pGlowObject = pGlowObjectManager + (entity.getGlowIndex() * 0x38);

            *reinterpret_cast<Color*>(pGlowObject + 0x04)    = entityGlowColor;
            *reinterpret_cast<bool*>(pGlowObject + 0x24)     = true;                         // Enabling glow (bool m_bRenderWhenOccluded)
            *reinterpret_cast<bool*>(pGlowObject + 0x25)     = false;                        // Disabling glow (bool m_bRenderWhenUnoccluded;)
        }
    }
}

void Misc::antiFlash()
{
    if (!antiflashEnabled || !Engine::getLocalPlayer().isValid())
        return;

    float* pFlashDuration = reinterpret_cast<float*>(Engine::getLocalPlayer().getBase()
        + hazedumper::netvars::m_flFlashDuration);

    if (pFlashDuration && *pFlashDuration > 0)
        *pFlashDuration = 0;                            
}

void Misc::bunnyHop()
{
    if (!bunnyhopEnabled || !Engine::getLocalPlayer().isValid())
        return;

    BYTE* pFlag = reinterpret_cast<BYTE*>(Engine::getLocalPlayer().getBase()
        + hazedumper::netvars::m_fFlags);
    if (pFlag == NULL)
        return;

    if (GetAsyncKeyState(VK_SPACE) && (*pFlag & FL_ONGROUND))
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

void Misc::aimBot()
{
    Aim::run();
}

void Misc::setGlowEsp(bool enabled)
{
    glowEspEnabled = enabled;
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

void Misc::setTeamMatesGlowing(bool enabled)
{
    glowTeamMates = enabled;
}

void Misc::setEnemiesGlowing(bool enabled)
{
    glowEnemies = enabled;
}

void Misc::setTeamMateGlowingColor(Color colors)
{
    teammateColors = colors;
}

void Misc::setEnemyGlowingColor(Color colors)
{
    enemyColors = colors;
}

