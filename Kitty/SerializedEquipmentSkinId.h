#pragma once
#include "Includes.h"
#include "Helper.h"

namespace SDK::Pointers::Runtime::Game {
	struct U_SerializedEquipmentSkinId {
		IL2CPP::Backends::Method<Structs::Mono::String*> ToString;

		void Setup(void* object);
	};
	extern U_SerializedEquipmentSkinId SerializedEquipmentSkinId;
}