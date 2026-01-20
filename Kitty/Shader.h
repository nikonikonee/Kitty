#pragma once
#include "Includes.h"

namespace SDK::Pointers::Unity {
	struct U_Shader {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<void*> Find;
		IL2CPP::Backends::Method<Structs::Mono::String*> GetPropertyName;
		IL2CPP::Backends::Method<int> GetPropertyCount;

		void Setup();
	};
	extern U_Shader Shader;
}