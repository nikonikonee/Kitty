#pragma once
#include "Includes.h"

namespace SDK::Pointers::Game {
	struct U_PlayerHand {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<bool> TryPickupTool;

		void Setup();
	};
	extern U_PlayerHand PlayerHand;
}