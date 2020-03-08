#pragma once

#include "CBaseEntity.h"
#include <vector>

#define MAX_ENTITIES 64

class Engine
{
public:
	static CBaseEntity                   getLocalPlayer();
	static std::vector<CBaseEntity>      getEntityList();

	static Vec3                          getViewAngles();
	static void                          setViewAngles(Vec3 angles);
};