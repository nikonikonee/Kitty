#include "CheatUtils.h"
#include "Logger.h"

void* Utils::getAbsoluteAddress(uint64_t offset) {
	HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
	if (gameAssembly)
		return (void**)((uint64_t)gameAssembly + offset);
	return nullptr;
}

void* Utils::getAbsoluteAddressReferee(uint64_t offset) {
	HMODULE referee = GetModuleHandleA("Referee.dll");
	if (referee)
		return (void**)((uint64_t)referee + offset);
	return nullptr;
}


inline void Utils::Hook(void* target, void* detour, void** orig) {
	MH_STATUS createHook = MH_CreateHook(target, detour, orig);
	MH_STATUS enableHook = MH_EnableHook(target);
	if (createHook != MH_OK)
		printf("[MH_CreateHook] Failed: [%p][%s]\n", target, MH_StatusToString(createHook));
	if (enableHook != MH_OK)
		printf("[MH_EnableHook] Failed: [%p][%s]\n", target, MH_StatusToString(enableHook));
	//Add a slight delay since we're mass hooking
	Sleep(50);
}

bool Utils::ASM::Ret(void* target) {
	DWORD oldProtect;
	if (!VirtualProtect(target, 1, PAGE_EXECUTE_READWRITE, &oldProtect))
		return false;

	*(BYTE*)target = 0xC3; // `ret` opcode

	DWORD temp;
	if (VirtualProtect(target, 1, oldProtect, &temp))
		Logger::Log(clr::green, "[Ret] Wrote: %p", target);
	return true;
}