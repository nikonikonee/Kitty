#pragma once
#include "Includes.h"


namespace SDK::Pointers::Game {
	struct U_DrawingSurface {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<void> LoadDrawing;

		void Setup();
	};
	extern U_DrawingSurface DrawingSurface;
}