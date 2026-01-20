#pragma once
#include "Includes.h"

namespace SDK::Pointers::Game {
	struct U_RangedWeapon {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<void> Fire;

		void Setup();
	};
	extern U_RangedWeapon RangedWeapon;
}