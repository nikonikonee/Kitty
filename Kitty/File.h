#pragma once
#include <iostream>
#include "Includes.h"

namespace SDK::Pointers::System {
	struct U_File {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<Structs::Mono::Array<uint8_t**>*> ReadAllBytes;

		void Setup();
	};
	extern U_File File;
}