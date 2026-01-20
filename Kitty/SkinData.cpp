#include "SkinData.h"

namespace SDK::Pointers::Game {
	U_SkinData SkinData;

	void  U_SkinData::Setup() {
		get_EquipmentSkinId = IL2CPP::Utils::GetMethod("", "RecRoom.Core.Equipment", "SkinData", "get_EquipmentSkinId", 0);
	}
}