#pragma once
#include "Includes.h"

namespace SDK::Pointers::System {
	struct U_Type {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<void*> GetType;

		void Setup();
	};
	extern U_Type Type;
}