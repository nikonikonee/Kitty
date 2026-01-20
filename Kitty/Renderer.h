#pragma once
#include "Includes.h"

namespace SDK::Pointers::Unity {
	struct U_Renderer {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<void*> get_material;
		IL2CPP::Backends::Method<void> set_material;

		void Setup();
	};
	extern U_Renderer Renderer;
}