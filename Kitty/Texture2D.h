#pragma once
#include "Includes.h"

namespace SDK::Pointers::Unity {
	struct U_Texture2D {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<void> ctor;

		void Setup();
	};
	extern U_Texture2D Texture2D;
}