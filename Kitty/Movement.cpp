#include "Movement.h"
#include "Logger.h"

bool (*old_IsFlyingEnabled)(void* instance);
bool IsFlyingEnabled(void* instance) {
	if (instance && Globals::Vars::Movement::dynamicFly)
		return true;
	return old_IsFlyingEnabled(instance);
}

bool (*old_CanChangeMovementMode)(void* instance);
bool CanChangeMovementMode(void* instance) {
	if (instance && Globals::Vars::Movement::hybridMovement)
		return true;
	return old_CanChangeMovementMode(instance);
}

void Cheats::Movement::Setup() {
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "RecRoom.Core.Locomotion", "PlayerMovement", "get_IsFlyingEnabled", 0), &IsFlyingEnabled, (void**)&old_IsFlyingEnabled);
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "", "SettingsModel", "get_CanChangeMovementMode", 0), &CanChangeMovementMode, (void**)&old_CanChangeMovementMode);
	Logger::Log(clr::magenta, "[Cheat] Setup: [Movement]");
}