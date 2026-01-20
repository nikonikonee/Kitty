#pragma once
#include "Includes.h"

namespace SDK::Pointers::System {
	struct U_Uri {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<void> ctor;
		IL2CPP::Backends::Method<SDK::Structs::Mono::String*> ToString;

		void Setup();
	};
	extern U_Uri Uri;
}