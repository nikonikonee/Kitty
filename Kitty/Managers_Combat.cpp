#include "Managers_Combat.h"
#include "RetSpoofer/RetSpoofer.hpp"

void Cheats::Managers::Combat::Run() {
	auto localPlayer = SDK::RR::Game::Player::get_LocalPlayer();
	if (localPlayer && Globals::Vars::Combat::loopFire) {
		auto toolsHeld = localPlayer->get_AllToolsHeld();
		for (int i = 0; i < toolsHeld->getLength(); ++i) {
			auto tool = toolsHeld->getPointer()[i];
			if (tool) {
				auto rangedWeapon = tool->GetComponent<SDK::RR::Game::RangedWeapon*>(SDK::RR::System::Type::GetType("RecRoom.Core.Combat.RangedWeapon, Assembly-CSharp"));
				if (rangedWeapon) {
					if (Globals::Vars::Combat::useBinding) {
						if (GetAsyncKeyState(VK_XBUTTON2) & 0x8000)
							rangedWeapon->Fire();
					}
					else {
						rangedWeapon->Fire();
					}
				}
			}
		}
	}
}

void (*old_GameCombatManagerUpdate)(void* instance);
void GameCombatManagerUpdate(void* instance) {
	if (instance)
		Globals::Vars::Runtime::Instance::GameCombatManager = instance;
	return spoof_call(Globals::Vars::Main::spoof, old_GameCombatManagerUpdate, instance);
}

void (*old_GameCombatManagerOnDestroy)(void* instance);
void GameCombatManagerOnDestroy(void* instance) {
	if (instance)
		Globals::Vars::Runtime::Instance::GameCombatManager = nullptr;
	return spoof_call(Globals::Vars::Main::spoof, old_GameCombatManagerOnDestroy, instance);
}

void (*old_GameTeamManagerUpdate)(void* instance);
void GameTeamManagerUpdate(void* instance) {
	if (instance)
		Globals::Vars::Runtime::Instance::GameTeamManager = instance;
	return spoof_call(Globals::Vars::Main::spoof, old_GameTeamManagerUpdate, instance);
}

void (*old_GameTeamManagerOnDestroy)(void* instance);
void GameTeamManagerOnDestroy(void* instance) {
	if (instance)
		Globals::Vars::Runtime::Instance::GameTeamManager = nullptr;
	return spoof_call(Globals::Vars::Main::spoof, old_GameTeamManagerOnDestroy, instance);
}

void Cheats::Managers::Combat::Setup() {
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "", "GameCombatManager", "Update", 0), &GameCombatManagerUpdate, (void**)&old_GameCombatManagerUpdate);
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "", "GameCombatManager", "OnDestroy", 0), &GameCombatManagerOnDestroy, (void**)&old_GameCombatManagerOnDestroy);

	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "", "GameTeamManager", "Update", 0), &GameTeamManagerUpdate, (void**)&old_GameTeamManagerUpdate);
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "", "GameTeamManager", "OnDestroy", 0), &GameTeamManagerOnDestroy, (void**)&old_GameTeamManagerOnDestroy);
}