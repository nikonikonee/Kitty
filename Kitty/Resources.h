#pragma once
#include "Includes.h"

namespace SDK::Pointers::Unity {
	struct U_Resources {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<Structs::Mono::Array<void**>*> FindObjectsOfTypeAll;
	
		void Setup();
	};
	extern U_Resources Resources;
}