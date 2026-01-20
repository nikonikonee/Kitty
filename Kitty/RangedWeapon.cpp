#include "RangedWeapon.h"

namespace SDK::Pointers::Game {
	U_RangedWeapon RangedWeapon;

	void U_RangedWeapon::Setup() {
		klass = IL2CPP::Backends::Class("", "RecRoom.Core.Combat", "RangedWeapon");

		Fire = klass.GetMethod("Fire", 1);
	}
}