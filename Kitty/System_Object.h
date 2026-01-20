#pragma once
#include "Includes.h"

namespace SDK::Pointers::System {
	struct U_Object {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<Structs::Mono::String*> ToString;

		void Setup();
	};
	extern U_Object Object;
}