#include "Managers_Players.h"
#include "Logger.h"

void (*old_PlayerUpdate)(SDK::RR::Game::Player* instance);
void PlayerUpdate(SDK::RR::Game::Player* instance) {
	if (instance) {
		Managers::Players.AddPlayer(instance);
		Managers::Players.Update();
	}
	if (instance) {
		Cheats::Managers::Movement::Run();
		Cheats::Managers::Lobby::LobbyCrash(); //Run in playerupdate for good reason
	}
	return old_PlayerUpdate(instance);
}

void (*old_PlayerOnDestroy)(SDK::RR::Game::Player* instance);
void PlayerOnDestroy(SDK::RR::Game::Player* instance) {
	if (instance)
		Managers::Players.RemovePlayer(instance);
	return old_PlayerOnDestroy(instance);
}

void Cheats::Managers::Players::Setup() {
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "", "Player", "Update", 0), &PlayerUpdate, (void**)&old_PlayerUpdate);
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "", "Player", "OnDestroy", 0), &PlayerOnDestroy, (void**)&old_PlayerOnDestroy);
	Logger::Log(clr::magenta, "[Cheat] Setup: [Managers_Player]");
}