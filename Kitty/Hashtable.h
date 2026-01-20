#pragma once
#include "Includes.h"

namespace SDK::Pointers::GameServer {
	struct U_Hashtable {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<void> set_Item;
		IL2CPP::Backends::Method<Structs::Mono::String*> ToString;

		void Setup();
	};
	extern U_Hashtable Hashtable;
}