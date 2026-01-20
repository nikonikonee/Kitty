#include "RR_GameServer.h"

namespace SDK::RR::GameServer {
	bool NetworkedPlayer::SetMasterClient() {
		void* args[1] = { this };
		return Pointers::GameServer::RRNetworking.SetMasterClient.Invoke(args).Unbox();
	}
}

namespace SDK::RR::GameServer {
	Unity::GameObject* RRNetworking::Instantiate(const char* prefabName, SDK::Structs::Unity::Vector3 position, SDK::Structs::Unity::Quaternion rotation, SDK::Structs::Unity::Vector3 scale, bool destroyOnLeave) {
		void* null = nullptr;
		return (Unity::GameObject*)spoof_call(Globals::Vars::Main::spoof, Pointers::GameServer::RRNetworking.Instantiate, SDK::IL2CPP::Utils::il2cpp_string_new(prefabName), position, rotation, scale, null, null, destroyOnLeave);
	}
}

namespace SDK::RR::GameServer {
	void Hashtable::set_Item(uint8_t key, void* value) {
		void* args[2] = { &key, value };
		Pointers::GameServer::Hashtable.set_Item[this].Invoke(args);
	}
}