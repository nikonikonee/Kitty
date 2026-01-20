#pragma once
#include "Includes.h"

namespace SDK::Pointers::Game {
	struct U_PlayerHead {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<void*> get_HeadPlayerCollider;
	
		void Setup();
	};
	extern U_PlayerHead PlayerHead;
}