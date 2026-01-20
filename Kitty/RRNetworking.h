#pragma once
#include "Includes.h"

namespace SDK::Pointers::GameServer {
	struct U_RRNetworking {
		IL2CPP::Backends::Class klass;

		void* (*Instantiate)(SDK::Structs::Mono::String* prefabName, SDK::Structs::Unity::Vector3 position, SDK::Structs::Unity::Quaternion rotation, SDK::Structs::Unity::Vector3 scale, void* viewId, void* null, bool destroyOnLeave);
		IL2CPP::Backends::Method<bool> SetMasterClient;
		IL2CPP::Backends::Method<void> RPC;
		IL2CPP::Backends::Method<void> RPC_Player;

		void Setup();
	};
	extern U_RRNetworking RRNetworking;
}