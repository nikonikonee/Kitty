#include "Managers_Movement.h"
#include "Logger.h"

void Cheats::Managers::Movement::Run() {
	auto localPlayer = SDK::RR::Game::Player::get_LocalPlayer();
	auto playerGameRoleManager = SDK::RR::Game::PlayerGameRoleManager::get_Instance();

	if (localPlayer && playerGameRoleManager) {
		auto playerMovement = localPlayer->get_PlayerMovement();
		if (playerMovement) {
			if (Globals::Vars::Movement::staticFly && !playerMovement->get_IsFlyingEnabled())
				playerMovement->AddFlyEnabled(true, playerGameRoleManager);

			if (Globals::Vars::Movement::walkspeedChanger)
				playerMovement->AddMaxWalkSpeed(Globals::Vars::Movement::Var::walkspeedAmount, playerGameRoleManager);

			if (Globals::Vars::Movement::jumpHeightChanger)
				playerMovement->AddMaxJumpHeight(Globals::Vars::Movement::Var::jumpHeightAmount, playerGameRoleManager);
		}
	}
}
