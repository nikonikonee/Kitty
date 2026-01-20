#pragma once
#include "Includes.h"

namespace SDK::Pointers::Unity {
	struct U_LineRenderer {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<void> set_startWidth;
		IL2CPP::Backends::Method<void> set_endWidth;

		IL2CPP::Backends::Method<void> set_useWorldSpace;
		
		IL2CPP::Backends::Method<void> set_startColor;
		IL2CPP::Backends::Method<void> set_endColor;

		IL2CPP::Backends::Method<void> set_positionCount;

		IL2CPP::Backends::Method<void> SetPosition;

		void Setup();
	};
	extern U_LineRenderer LineRenderer;
}