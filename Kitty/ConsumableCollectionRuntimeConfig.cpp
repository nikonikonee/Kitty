#include "ConsumableCollectionRuntimeConfig.h"

namespace SDK::Pointers::Game {
	U_ConsumableCollectionRuntimeConfig ConsumableCollectionRuntimeConfig;

	void U_ConsumableCollectionRuntimeConfig::Setup() {
		klass = IL2CPP::Backends::Class("", "RecRoom.Consumable", "ConsumableCollectionRuntimeConfig");

		get_List = klass.GetMethod("PJGNANOAFAH", 0);
	}
}