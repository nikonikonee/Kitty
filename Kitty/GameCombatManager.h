#pragma once
#include "Includes.h"

namespace SDK::Pointers::Game {
	struct U_GameCombatManager {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<int> GetPlayerHealth;
		
		IL2CPP::Backends::Method<bool> PlayerIsAlive;
		IL2CPP::Backends::Method<bool> IsPlayerDownButNotOut;

		IL2CPP::Backends::Method<void> MasterKillPlayer;
		IL2CPP::Backends::Method<void> MasterSetPlayerHealth;
		IL2CPP::Backends::Method<void> MasterRequestPlayerInvincibility;

		void Setup();
	};
	extern U_GameCombatManager GameCombatManager;
}