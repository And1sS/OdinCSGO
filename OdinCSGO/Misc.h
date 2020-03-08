#pragma once

#include <vector>
#include <iostream>

#include "Aim.h"
#include "CGlowObjectManager.h"

#define MAX_ENTITIES 64

class Misc
{
private:
    std::vector<CBaseEntity> entityList;
    
    bool   triggerBotEnabled  = false;
    bool   bunnyhopEnabled    = false;
    bool   antiflashEnabled   = false;

public:
	Misc();

	void printEntitiesInfo();

	void antiFlash();
	void bunnyHop();
	void triggerBot();

    void setAntiflash(bool enabled);
    void setBunnyHop(bool enabled);
    void setTriggerBot(bool enabled);
};

