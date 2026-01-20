#include "Managers_Global.h"

void (*old_PlayerUpdate)(void* instance);
void PlayerUpdate(void* instance) {
	if (instance != nullptr)
		Cheat::Managers::Players.AddPlayer(instance);
	return old_PlayerUpdate(instance);
}

void (*old_PlayerOnDestroy)(void* instance);
void PlayerOnDestroy(void* instance) {
	if (instance != nullptr)
		Cheat::Managers::Players.RemovePlayer(instance);
	return old_PlayerOnDestroy(instance);
}

void Cheats::Managers::Setup() {
	Cheat::Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("Assembly-CSharp", "", "Player", "Update", 0), &PlayerUpdate, (void**)&old_PlayerUpdate);
	Cheat::Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("Assembly-CSharp", "", "Player", "OnDestroy", 0), &PlayerOnDestroy, (void**)&old_PlayerOnDestroy);
}