#include "Visuals.h"

void Visuals::run()
{
	glowEsp();
}

void Visuals::glowEsp()
{
    uintptr_t pGlowObjectManager = *reinterpret_cast<uintptr_t*>(Utilities::getClientBase()
        + hazedumper::signatures::dwGlowObjectManager);

	if (!glowEnabled || !pGlowObjectManager || !Engine::getLocalPlayer().isValid())
		return;

    for (CBaseEntity entity : Engine::getEntityList())
    {
        if (!entity.isValid() || !entity.isAlive() || entity.isDormant()
            || entity.getBase() == Engine::getLocalPlayer().getBase()
            || entity.getTeam() == Engine::getLocalPlayer().getTeam())
            continue;

        Color entityGlowColor = { 1, 0, 0, 1 };
            
        GlowObjectDefinition_t* glowObject = reinterpret_cast<GlowObjectDefinition_t*>(pGlowObjectManager
            + (entity.getGlowIndex() * sizeof(GlowObjectDefinition_t)));

        glowObject->m_vGlowColor = entityGlowColor;
        glowObject->m_bRenderWhenOccluded = true;
        glowObject->m_bRenderWhenUnoccluded = false;
    }
}
