#include "GameTeamManager.h"

namespace SDK::Pointers::Game {
	U_GameTeamManager GameTeamManager;

	void U_GameTeamManager::Setup() {
		klass = IL2CPP::Backends::Class("", "", "GameTeamManager");

		GetPlayerTeam = klass.GetMethod("GetPlayerTeam", 1);
	}
}