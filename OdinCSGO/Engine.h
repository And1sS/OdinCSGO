#pragma once

#include "Interfaces.h"
#include "CBaseEntity.h"
#include <vector>

#define MAX_ENTITIES 64

class Engine
{
public:
	static CBaseEntity                   getLocalPlayer();
	static std::vector<CBaseEntity>      getEntityList();

	static Vector                          getViewAngles();
	static void                          setViewAngles(Vector angles);
};