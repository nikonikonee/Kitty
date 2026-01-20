#include "ConsumableInfo.h"

namespace SDK::Pointers::Game {
	U_ConsumableInfo ConsumableInfo;

	void U_ConsumableInfo::Setup() { //NOT USED!
		klass = IL2CPP::Backends::Class("", "", "");

		get_Config = klass.GetMethod("", 0);
	}
}