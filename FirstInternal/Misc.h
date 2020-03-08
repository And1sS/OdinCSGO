#pragma once

#include <vector>
#include <iostream>

#include "Aim.h"

#define MAX_ENTITIES 64

struct Color
{
    float r, g, b, a;
};

class Misc
{
private:
    std::vector<CBaseEntity> entityList;
    
    bool   glowTeamMates      = false;
    bool   glowEnemies        = false;
    bool   glowEspEnabled     = false;
    bool   triggerBotEnabled  = false;
    bool   bunnyhopEnabled    = false;
    bool   antiflashEnabled   = false;

    Color  enemyColors        = { 1, 0, 0, 1 };              // Green colour
    Color  teammateColors     = { 0, 1, 0, 1 };              // Red colour

    uintptr_t getGlowObjectManager();

public:
	Misc();

	void loadEntityList();

	void printEntitiesInfo();

	void glowESP();
	void antiFlash();
	void bunnyHop();
	void triggerBot();
    void aimBot();

    void setGlowEsp(bool enabled);
    void setAntiflash(bool enabled);
    void setBunnyHop(bool enabled);
    void setTriggerBot(bool enabled);
    void setEnemiesGlowing(bool enabled);
    void setTeamMatesGlowing(bool enabled);

    void setEnemyGlowingColor(Color color);
    void setTeamMateGlowingColor(Color color);
};

