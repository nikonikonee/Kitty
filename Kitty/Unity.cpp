#include "Unity.h"
#include "Logger.h"

void (*old_setFieldOfView)(void* instance, float value);
void setFieldOfView(void* instance, float value) {
	if (instance && Globals::Vars::Unity::fovSlider)
		value = Globals::Vars::Unity::Var::fovAmount;
	if (instance) {
		Cheats::Managers::Combat::Run();

		if (Globals::Vars::Aimbot::enableSilentAimbot) Cheats::Combat::SilentAimbot::Run();

		Cheats::Combat::Aimbot::HvH::Run();
	}
	return old_setFieldOfView(instance, value);
}

void (*old_OnUpdate)(void* instance);
void OnUpdate(void* instance) {
	if (instance) {
		Cheats::Managers::PlayerList::Run();
		Cheats::Managers::Lobby::Run();
		Cheats::Managers::Network::Run();
	}
	return old_OnUpdate(instance);
}

void Cheats::Unity::Setup() {
	/*---- FOV Slider ----*/
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("UnityEngine.CoreModule", "UnityEngine", "Camera", "set_fieldOfView", 1), &setFieldOfView, (void**)&old_setFieldOfView);
	/*---- Global Network Manager ----*/
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "RecRoom.Systems", "InputManager", "OnUpdate", 0), &OnUpdate, (void**)&old_OnUpdate);
	Logger::Log(clr::magenta, "[Cheat] Setup: [Unity]");
}