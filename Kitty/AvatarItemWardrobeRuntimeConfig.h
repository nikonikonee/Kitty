#pragma once
#include "Includes.h"

namespace SDK::Pointers::Game {
	struct U_AvatarItemWardrobeRuntimeConfig {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<void*> get_Config;

		IL2CPP::Backends::Field<void*> caidToAvatarItemSelections;

		void Setup();
	};
	extern U_AvatarItemWardrobeRuntimeConfig AvatarItemWardrobeRuntimeConfig;
}