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

		Vec3 relativeAngle   = Vec3::getRelativeAnglesDeg(localPlayer.getBoneOrigin(HEAD_BONE_INDEX),
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

	Vec3 myHeadOrigin      = localPlayer.getBoneOrigin(HEAD_BONE_INDEX);
	Vec3 enemyHeadOrigin   = enemy.getBoneOrigin(HEAD_BONE_INDEX);

	Vec3 deltaAngles       = Vec3::getRelativeAnglesDeg(myHeadOrigin, enemyHeadOrigin, Engine::getViewAngles());
	Vec3 newAngles         = Engine::getViewAngles() + deltaAngles;

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
