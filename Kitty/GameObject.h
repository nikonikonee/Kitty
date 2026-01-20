#pragma once
#include "Includes.h"

namespace SDK::Pointers::Unity {
	struct U_GameObject {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<void*> GetComponent;
		IL2CPP::Backends::Method<void*> GetComponentInChildren;

		IL2CPP::Backends::Method<Structs::Mono::Array<void**>*> GetComponentsInChildren;
		IL2CPP::Backends::Method<Structs::Mono::Array<void**>*> GetComponents;

		IL2CPP::Backends::Method<void*> AddComponent;
		IL2CPP::Backends::Method<void*> get_transform;

		IL2CPP::Backends::Method<void> ctor;

		void Setup();
	};
	extern U_GameObject GameObject;
}