#include "Visuals.h"

void Visuals::run()
{
	glowEsp();
}

void Visuals::glowEsp()
{
    if (Interfaces::g_pGlowManager == nullptr || !glowEnabled || !Engine::getLocalPlayer().isValid())
        return;

    auto entityList = Engine::getEntityList();

    for (CBaseEntity entity : entityList)
    {
        if (!entity.isValid() || !entity.isAlive() || entity.isDormant()
            || entity.getBase() == Engine::getLocalPlayer().getBase()
            || entity.getTeam() == Engine::getLocalPlayer().getTeam())
            continue;

        Color entityGlowColor = { 1 - entity.getHealth() / 100.0f, entity.getHealth() / 200.0f, 0, 1 };
                   
        GlowObjectDefinition_t& glowObject = Interfaces::g_pGlowManager->m_GlowObjectDefinitions[entity.getGlowIndex()];

        glowObject.m_vGlowColor = entityGlowColor;
        glowObject.m_bRenderWhenOccluded = true;
        glowObject.m_bRenderWhenUnoccluded = false;
    }
}

void Visuals::enableGlowEsp()
{
    glowEnabled = true;
}

void Visuals::disableGlowEsp()
{
    glowEnabled = false;
}
