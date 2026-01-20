#pragma once
#include "Includes.h"

namespace SDK::Pointers::Game {
	struct U_ScreenPlayerController {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<void*> get_CameraSystem;

		void Setup();
	};
	extern U_ScreenPlayerController ScreenPlayerController;
}