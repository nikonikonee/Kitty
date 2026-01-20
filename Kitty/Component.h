#pragma once
#include "Includes.h"

namespace SDK::Pointers::Unity {
	struct U_Component {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<void*> get_transform;
		IL2CPP::Backends::Method<void*> get_gameObject;
		IL2CPP::Backends::Method<void*> GetComponent;

		void Setup();
	};
	extern U_Component Component;
}