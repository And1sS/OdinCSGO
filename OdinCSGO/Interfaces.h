#pragma once

#include <iostream>

#include "Utilities.h"
#include "CGlowObjectManager.h"

#define GlOW_OBJECT_MANAGER_PATTERN "\x0F\x11\x05\x00\x00\x00\x00\x83\xC8\x01\xC7\x05\x00\x00\x00\x00\x00\x00\x00\x00"
#define GLOW_OBJECT_MANAGER_MASK    "xxx????xxxxx????xxxx"

#define ENTITY_LIST_PATTERN         "\xC1\xE0\x04\x05\x00\x00\x00\x00\xC1\xE9\x10\x39\x48\x04"
#define ENTITY_LIST_MASK            "xxxx????xxxxxx"

namespace Interfaces
{

	extern CGlowObjectManager* g_pGlowManager;
	extern uintptr_t pEntityList;

	void initialize();
}