#include "Interfaces.h"

namespace Interfaces
{
	CGlowObjectManager* g_pGlowManager;
	uintptr_t pEntityList;

	void initialize()
	{
	    g_pGlowManager = reinterpret_cast<CGlowObjectManager*>(*(uintptr_t*)(Utilities::findPattern("client_panorama.dll",
			GlOW_OBJECT_MANAGER_PATTERN, GLOW_OBJECT_MANAGER_MASK) + 3));

		while (!pEntityList)
		{
			pEntityList = Utilities::findPattern("client_panorama.dll", ENTITY_LIST_PATTERN, ENTITY_LIST_MASK);
			std::cout << "stuck at finding entity list pointer" << std::endl;
			Sleep(100);
		}
	}
}
