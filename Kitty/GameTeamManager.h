#pragma once
#include "Includes.h"

namespace SDK::Pointers::Game {
	struct U_GameTeamManager {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<int> GetPlayerTeam;

		void Setup();
	};
	extern U_GameTeamManager GameTeamManager;
}