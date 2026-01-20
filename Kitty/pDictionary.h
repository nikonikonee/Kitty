#pragma once
#include "Includes.h"

namespace SDK::Pointers::System {
	struct U_Dictionary {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<int> get_Count;
		IL2CPP::Backends::Method<Structs::Mono::Array<void**>*> get_Keys;
		IL2CPP::Backends::Method<Structs::Mono::Array<void**>*> get_Values;
	
		void Setup();
	};
	extern U_Dictionary Dictionary;
}