#pragma once
#include "Includes.h"

namespace SDK::Pointers::Game {
	struct U_EquipmentInfo {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<void*> get_Config;

		void Setup();
	};

	extern U_EquipmentInfo EquipmentInfo;
}