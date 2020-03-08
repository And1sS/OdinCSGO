#pragma once

#include <Windows.h>
#include <cstdint>
#include <Psapi.h>

class Utilities
{
public:
	static uintptr_t clientBase;
	static uintptr_t engineBase;

	static uintptr_t getClientBase();
	static uintptr_t getEngineBase();

	static uintptr_t findPattern(uintptr_t start, uintptr_t end, const char* pattern, const char* mask);
	static uintptr_t findPattern(const char* szModuleName, const char* pattern, const char* mask);

	template <typename T>
	static uintptr_t findPattern(const char* szModuleName, const char* pattern, const char* mask, T& result)
	{
		uintptr_t firstMatch = findPattern(szModuleName, pattern, mask);

		if (firstMatch == NULL)
			return NULL;

		result = *reinterpret_cast<T*>(firstMatch);
		return firstMatch;
	}
};