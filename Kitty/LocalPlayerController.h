#pragma once
#include "Includes.h"

namespace SDK::Pointers::Game {
	struct U_LocalPlayerController {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<void*> get_ScreenPlayerControllerInstance;

		void Setup();
	};
	extern U_LocalPlayerController LocalPlayerController;
}