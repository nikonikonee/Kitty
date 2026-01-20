#pragma once
#include "Includes.h"

namespace SDK::Pointers::Game {
	struct U_PlayerAvatar {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<bool> get_UsesFullBodyAvatar;

		void Setup();
	};
	extern U_PlayerAvatar PlayerAvatar;
}