#include "PlayerGameRoleManager.h"

namespace SDK::Pointers::Game {
	U_PlayerGameRoleManager PlayerGameRoleManager;

	void U_PlayerGameRoleManager::Setup() {
		klass = IL2CPP::Backends::Class("", "RecRoom.Systems.PlayerRoles", "PlayerGameRoleManager");

		get_Instance = klass.GetMethod("get_Instance", 0);
	}
}