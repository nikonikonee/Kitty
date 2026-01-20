#pragma once
#include "Includes.h"

namespace SDK::Pointers::Game {
	struct U_ConsumableCollectionRuntimeConfig {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<Structs::Mono::Array<void**>*> get_List;

		void Setup();
	};
	extern U_ConsumableCollectionRuntimeConfig ConsumableCollectionRuntimeConfig;
}