#pragma once
#include "Includes.h"

namespace SDK::Pointers::Unity {
	struct U_ImageConversion {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<bool> LoadImageTex;

		void Setup();
	};
	extern U_ImageConversion ImageConversion;
}