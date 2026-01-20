#pragma once
#include "Players.h"
#include "Runtime.h"

namespace Cheats::Combat::Aimbot::Utils {
	extern SDK::RR::Game::RangedWeapon* GetLocalPlayerWeapon();
	extern SDK::RR::Game::RangedWeapon* GetWeaponFromPlayer(SDK::RR::Game::Player* player);

	extern SDK::RR::Game::Player* GetClosestPlayer();
	extern SDK::RR::Game::Player* GetClosestPlayerFromWeapon(void* weapon);
	
	extern SDK::RR::Game::Player* GetClosestPlayerWithinFOV();
	extern SDK::RR::Game::Player* GetClosestPlayerWithinStaticFOV(float fov);
}