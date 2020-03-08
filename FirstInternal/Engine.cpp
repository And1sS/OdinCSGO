#include "Engine.h"

CBaseEntity Engine::getLocalPlayer()
{
	uintptr_t base          = *reinterpret_cast<uintptr_t*>(Utilities::getClientBase() + hazedumper::signatures::dwLocalPlayer);
	if (base == NULL)
		return CBaseEntity(NULL, NULL);

	uintptr_t pEntityList   = Utilities::getClientBase() + hazedumper::signatures::dwEntityList;
	uint32_t id             = (base - pEntityList) / 0x10;

	return CBaseEntity(base, id);
}

std::vector<CBaseEntity> Engine::getEntityList()
{
	std::vector<CBaseEntity> entityList;

	if (!getLocalPlayer().isValid())
		return entityList;

	uintptr_t pEntityList = Utilities::getClientBase() + hazedumper::signatures::dwEntityList;

	for (auto i = 0; i < MAX_ENTITIES; i++)
	{
		uintptr_t pEntity = *reinterpret_cast<uintptr_t*>(pEntityList + i * 0x10);

		if (pEntity != NULL)
			entityList.push_back(CBaseEntity(pEntity, i));
	}

	return entityList;
}

Vec3 Engine::getViewAngles()
{
	uintptr_t clientState = *reinterpret_cast<uintptr_t*>(Utilities::getEngineBase()
		+ hazedumper::signatures::dwClientState);

	return *reinterpret_cast<Vec3*>(clientState +
		hazedumper::signatures::dwClientState_ViewAngles);
}

void Engine::setViewAngles(Vec3 angles)
{
	uintptr_t clientState = *reinterpret_cast<uintptr_t*>(Utilities::getEngineBase()
		+ hazedumper::signatures::dwClientState);

	Vec3* pAngles = reinterpret_cast<Vec3*>(clientState 
		+ hazedumper::signatures::dwClientState_ViewAngles);
	*pAngles = angles;
}