#pragma once

#include "Engine.h"
#include "CGlowObjectManager.h"
#include "Interfaces.h"

class Visuals
{
private: 
	bool glowEnabled = true;

public:
	Visuals() = default;

	void run();

	void glowEsp();

	void enableGlowEsp();
	void disableGlowEsp();
};

