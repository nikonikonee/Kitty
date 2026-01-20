#include "EquipmentInfo.h"

namespace SDK::Pointers::Game {
	U_EquipmentInfo EquipmentInfo;

	void U_EquipmentInfo::Setup() { //NOT USED!
		klass = IL2CPP::Backends::Class("", "", "");

		get_Config = klass.GetMethod("", 0);
	}
}