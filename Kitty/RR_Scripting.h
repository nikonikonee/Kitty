#pragma once
#include "RR_Includes.h"
#include "RR_Base.h"
#include "RR_GameServer.h"

namespace SDK::RR::Scripting {
	struct RRNetworkView : Base::MonoBehaviour {
		GameServer::NetworkedPlayer* get_Owner();

		void TransferOwnership(SDK::RR::GameServer::NetworkedPlayer* networkedPlayer);
		
		void RPC(const char* methodName, GameServer::NetworkedPlayer* networkedPlayer, Structs::IL2CPP::Il2CppArray* parameters);
		void RPC(const char* methodName, int photonTargets, Structs::IL2CPP::Il2CppArray* parameters);
	};

	struct RRNetworkBehavior : Base::MonoBehaviour {
		RRNetworkView* get_NetworkedView();
	};
}