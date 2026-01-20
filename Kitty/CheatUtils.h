#pragma once
#include <iostream>
#include <Windows.h>
#include <MinHook.h>

namespace Utils {
	//RVA stuff
	extern void* getAbsoluteAddress(uint64_t offset);
	extern void* getAbsoluteAddressReferee(uint64_t offset);

	//Hooking
	extern inline void Hook(void* target, void* detour, void** orig);

	namespace ASM {
		//Patching
		extern bool Ret(void* target);
	}
}