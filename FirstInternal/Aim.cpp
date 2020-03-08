#include "Aim.h"

#define HEAD_BONE_INDEX 8

CBaseEntity Aim::getClosestFOVEnemy(std::vector<CBaseEntity> entities)
{
	CBaseEntity localPlayer   = Engine::getLocalPlayer();
	CBaseEntity closest       = CBaseEntity(NULL, NULL);

	float minFovDist         = std::numeric_limits<float>::infinity();

	for (CBaseEntity entity : entities)
	{
		if (entity.getTeam() == localPlayer.getTeam() 
			|| entity == localPlayer
			|| entity.isDormant() 
			|| !entity.isAlive())
		{
			continue;
		}

		Vector relativeAngle   = Vector::getRelativeAnglesDeg(localPlayer.getBoneOrigin(HEAD_BONE_INDEX),
			entity.getBoneOrigin(HEAD_BONE_INDEX), Engine::getViewAngles());

		float fovDist        = std::hypotf(relativeAngle.getX(), relativeAngle.getY());

		if (fovDist < minFovDist)
		{
			closest = entity;
			minFovDist = fovDist;
		}
	}

	return closest;
}



void Aim::aimAt(CBaseEntity enemy)
{
	if (!Engine::getLocalPlayer().isValid() || !enemy.isValid())
		return;

	CBaseEntity localPlayer = Engine::getLocalPlayer();

	Vector myHeadOrigin      = localPlayer.getBoneOrigin(HEAD_BONE_INDEX);
	Vector enemyHeadOrigin   = enemy.getBoneOrigin(HEAD_BONE_INDEX);

	Vector deltaAngles       = Vector::getRelativeAnglesDeg(myHeadOrigin, enemyHeadOrigin, Engine::getViewAngles());
	Vector newAngles         = Engine::getViewAngles() + deltaAngles;

	newAngles              = newAngles - Engine::getLocalPlayer().getViewPunchAngle() * 2.0f;

	if (GetAsyncKeyState(VK_XBUTTON1) || GetAsyncKeyState(VK_XBUTTON2))
		Engine::setViewAngles(newAngles);
}

void Aim::run()
{
	if (!Engine::getLocalPlayer().isValid())
		return;

	CBaseEntity closestEnemy = getClosestFOVEnemy(Engine::getEntityList());
	if (!closestEnemy.isValid())
		return;

	aimAt(closestEnemy);
}
