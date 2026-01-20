#pragma once
#include "Includes.h"

namespace SDK::Pointers::GameServer {
	struct U_RRNetworkBehavior {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<void*> get_photonView;
		IL2CPP::Backends::Method<void*> get_NetworkedView;

		void Setup();
	};
	extern U_RRNetworkBehavior RRNetworkBehavior;
}