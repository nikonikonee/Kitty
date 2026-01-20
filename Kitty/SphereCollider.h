#pragma once
#include "Includes.h"

namespace SDK::Pointers::Unity {
	struct U_SphereCollider {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<void> set_radius;

		void Setup();
	};
	extern U_SphereCollider SphereCollider;
}