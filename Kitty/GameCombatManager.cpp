#include "GameCombatManager.h"

namespace SDK::Pointers::Game {
	U_GameCombatManager GameCombatManager;

	void U_GameCombatManager::Setup() {
		klass = IL2CPP::Backends::Class("", "", "GameCombatManager");

		GetPlayerHealth = klass.GetMethod("GetPlayerHealth", 1);
		
		PlayerIsAlive = klass.GetMethod("PlayerIsAlive", 1);
		IsPlayerDownButNotOut = klass.GetMethod("IsPlayerDownButNotOut", 1);

		MasterKillPlayer = klass.GetMethod("MasterKillPlayer", 1);
		MasterSetPlayerHealth = klass.GetMethod("MasterSetPlayerHealth", 2);
		MasterRequestPlayerInvincibility = klass.GetMethod("MasterRequestPlayerInvincibility", 2);
	}
}