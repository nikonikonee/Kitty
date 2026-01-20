#include "SerializedEquipmentSkinId.h"

namespace SDK::Pointers::Runtime::Game {
	U_SerializedEquipmentSkinId SerializedEquipmentSkinId;

	void U_SerializedEquipmentSkinId::Setup(void* object) {
		IL2CPP::Backends::Helper::AssignSpecificType(object, "ToString", 0, ToString);
	}
}