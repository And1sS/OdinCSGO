#include "Utilities.h"

uintptr_t Utilities::clientBase = NULL;
uintptr_t Utilities::engineBase = NULL;

uintptr_t Utilities::getClientBase()
{
	if (clientBase == NULL)
	{
		clientBase = reinterpret_cast<uintptr_t>(GetModuleHandle(L"client_panorama.dll"));
	}
	
	return clientBase;
}

uintptr_t Utilities::getEngineBase()
{
	if (engineBase == NULL)
	{
		engineBase = reinterpret_cast<uintptr_t>(GetModuleHandle(L"engine.dll"));
	}

	return engineBase;
}

uintptr_t Utilities::findPattern(uintptr_t start, uintptr_t end, const char* pattern, const char* mask)
{
	uintptr_t offset;
	for (offset = 0; mask[offset] != '?'; offset++);

	for (uintptr_t pStart = start; pStart <= end - strlen(mask); pStart++)
	{
		uint8_t count = 0;
		for (uintptr_t pCurr = pStart; pCurr < pStart + strlen(mask); pCurr++)
		{
			if (*(PCHAR)pCurr != pattern[count] && mask[count] == 'x')
			{
				break;
			}

			if (++count == strlen(mask))
			{
				return pStart + offset;
			}
		}
	}

	return NULL;
}

uintptr_t Utilities::findPattern(const char* szModuleName, const char* pattern, const char* mask)
{
	HMODULE hModule = GetModuleHandleA(szModuleName);

	if (hModule == NULL)
		return NULL;

	MODULEINFO modInfo;
	HANDLE hProcess = GetCurrentProcess();

	if (!GetModuleInformation(hProcess, hModule, &modInfo, sizeof(modInfo)))
		return NULL;

	uintptr_t start = (uintptr_t)modInfo.lpBaseOfDll;
	uintptr_t end = (uintptr_t)modInfo.lpBaseOfDll + modInfo.SizeOfImage;

	return findPattern(start, end, pattern, mask);
}
