#pragma once
#include <vector>
#include <limits>

#include "Engine.h"

class Aim
{
public:
	CBaseEntity   getClosestFOVEnemy(std::vector<CBaseEntity> entities, int FOV);

	void         aimAt(CBaseEntity entity);
	void         run();
};

