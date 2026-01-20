#pragma once
#include "Includes.h"

namespace SDK::Pointers::Unity {
	struct U_Transform {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<Structs::Unity::Vector3> get_position;
		IL2CPP::Backends::Method<Structs::Unity::Vector3> get_forward;
		IL2CPP::Backends::Method<Structs::Unity::Vector3> get_rotation;

		IL2CPP::Backends::Method<void> set_position;
		IL2CPP::Backends::Method<void> set_localPosition;

		IL2CPP::Backends::Method<void> set_rotation;
		IL2CPP::Backends::Method<void> set_localScale;

		IL2CPP::Backends::Method<void> set_parent;

		IL2CPP::Backends::Method<void*> GetChild;
		IL2CPP::Backends::Method<int> GetChildCount;

		void Setup();
	};
	extern U_Transform Transform;
}