#pragma once
#include "Includes.h"

namespace SDK::Pointers::Unity {
	struct U_Camera {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<Structs::Unity::Vector3> WorldToScreenPoint;
		IL2CPP::Backends::Method<Structs::Mono::Array<void**>*> get_allCameras;

		void Setup();
	};
	extern U_Camera Camera;
}