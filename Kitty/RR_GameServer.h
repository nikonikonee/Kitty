#pragma once
#include "RR_Includes.h"
#include "RR_Unity.h"

namespace SDK::RR::GameServer {
	struct NetworkedPlayer {
		bool SetMasterClient();
	};

	struct RRNetworking {
		static Unity::GameObject* Instantiate(const char* prefabName, SDK::Structs::Unity::Vector3 position, SDK::Structs::Unity::Quaternion rotation, SDK::Structs::Unity::Vector3 scale, bool destroyOnLeave);
	};

	struct Hashtable {
		void set_Item(uint8_t key, void* value);
	};
}

