#pragma once
#include "Players.h"
#include "Prefabs.h"

namespace Cheats::Managers::Lobby::Mods {
	extern void DeleteMap();

	extern void KillAll();
	extern void RestoreHealthAll();

	extern void SpawnAssetAll();
	extern void ForceHoldAll();

	extern void BringAll();
	extern void BringAllToPlayer(SDK::RR::Game::Player* target);

	extern void VoidAll();
}