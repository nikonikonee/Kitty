#pragma once
#include "Includes.h"

namespace SDK::Pointers::Unity {
	struct U_Object {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<void*> Instantiate;
		IL2CPP::Backends::Method<Structs::Mono::Array<void**>*> FindObjectsOfType;
		IL2CPP::Backends::Method<Structs::Mono::String*> get_name;
		IL2CPP::Backends::Method<void> Destroy;

		void Setup();
	};
	extern U_Object Object;
}