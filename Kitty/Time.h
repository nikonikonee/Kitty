#pragma once
#include "Includes.h"

namespace SDK::Pointers::Unity {
	struct U_Time {
		IL2CPP::Backends::Class klass;

		float (*get_time)();
		IL2CPP::Backends::Method<float> get_deltaTime;
		IL2CPP::Backends::Method<void> set_timeScale;

		void Setup();
	};
	extern U_Time Time;
}