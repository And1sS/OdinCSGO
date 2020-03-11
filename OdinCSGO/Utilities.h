#pragma once

#include <Windows.h>
#include <cstdint>
#include <Psapi.h>
#include <string>

class Utilities
{
public:
	static uintptr_t clientBase;
	static uintptr_t engineBase;

	static uintptr_t getClientBase();
	static uintptr_t getEngineBase();

	static uintptr_t findPattern(uintptr_t start, uintptr_t end, const char* pattern, const char* mask);
	static uintptr_t findPattern(const char* szModuleName, const char* pattern, const char* mask);

	template <class T>
	static T getVMetod(void* base, uint16_t index)
	{
		return (*reinterpret_cast<T**>(base))[index];
	}
};