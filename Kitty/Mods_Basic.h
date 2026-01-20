#pragma once
#include "RR.h"
#include "Prefabs.h"

namespace Cheats::Managers::PlayerList::Mods::Basic {
	extern void StealPv(SDK::RR::Game::Player* target);
	extern void RestorePv(SDK::RR::Game::Player* target);

	extern void SpawnAsset(SDK::RR::Game::Player* target);
}