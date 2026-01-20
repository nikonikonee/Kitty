#pragma once
#include "RR.h"

namespace Cheats::Managers::PlayerList::Mods::Game {
	extern void LoopFire(SDK::RR::Game::Player* target);
	extern void Kill(SDK::RR::Game::GameCombatManager* instance, SDK::RR::Game::Player* target);
	extern void RestoreHealth(SDK::RR::Game::GameCombatManager* instance, SDK::RR::Game::Player* target, int health);
	extern void Invincibility(SDK::RR::Game::GameCombatManager* instance, SDK::RR::Game::Player* target, float duration);
}