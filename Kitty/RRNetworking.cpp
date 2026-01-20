#include "RRNetworking.h"

namespace SDK::Pointers::GameServer {
	U_RRNetworking RRNetworking;

	void U_RRNetworking::Setup() {
		klass = IL2CPP::Backends::Class("RecRoom.Networking.Instantiation.Runtime", "", "OOPPDCCAKEA");

		Instantiate = (void* (*)(SDK::Structs::Mono::String*, SDK::Structs::Unity::Vector3, SDK::Structs::Unity::Quaternion, SDK::Structs::Unity::Vector3, void*, void*, bool)) Utils::getAbsoluteAddress(0x83A2EE0);

		SetMasterClient = klass.GetMethod("IOADPADKGHM", 1);
		RPC = klass.GetMethod("KDHAGGMBMAP", 5);
		RPC_Player = klass.GetSpecificMethod("KDHAGGMBMAP", 5, "NELIJLIGAOD");
	}
}