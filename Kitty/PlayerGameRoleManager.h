#pragma once
#include "Includes.h"

namespace SDK::Pointers::Game {
	struct U_PlayerGameRoleManager {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<void*> get_Instance;

		void Setup();
	};
	extern U_PlayerGameRoleManager PlayerGameRoleManager;
}