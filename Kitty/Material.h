#pragma once
#include "Includes.h"

namespace SDK::Pointers::Unity {
	struct U_Material {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<void> ctor;
		IL2CPP::Backends::Method<void> SetInt;
		IL2CPP::Backends::Method<void> SetColor;

		void Setup();
	};
	extern U_Material Material;
}