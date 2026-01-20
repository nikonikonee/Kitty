#pragma once
#include "Includes.h"

namespace SDK::Pointers::Game {
	struct U_PlayerMovement {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<void> AddFlyEnabled;
		IL2CPP::Backends::Method<void> RemoveFlyEnabled;

		IL2CPP::Backends::Method<void> AddMaxWalkSpeed;
		IL2CPP::Backends::Method<void> RemoveMaxWalkSpeed;
		
		IL2CPP::Backends::Method<void> AddMaxJumpHeight;
		IL2CPP::Backends::Method<void> RemoveMaxJumpHeight;

		IL2CPP::Backends::Method<bool> get_IsFlyingEnabled;

		void Setup();
	};
	extern U_PlayerMovement PlayerMovement;
}