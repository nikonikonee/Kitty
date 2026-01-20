#pragma once
#include "Includes.h"

namespace SDK::Pointers::Game {
	struct U_PlayerNameTag {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<void*> get_transform;

		void Setup();
	};
	extern U_PlayerNameTag PlayerNameTag;
}