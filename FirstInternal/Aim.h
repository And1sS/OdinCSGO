#pragma once
#include <vector>
#include <limits>

#include "Engine.h"

class Aim
{
public:
	static CBaseEntity   getClosestFOVEnemy(std::vector<CBaseEntity> entities);

	static void         aimAt(CBaseEntity entity);
	static void         run();
};

