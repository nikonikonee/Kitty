#include "RR_Scripting.h"

namespace SDK::RR::Scripting {
	GameServer::NetworkedPlayer* RRNetworkView::get_Owner() { return (GameServer::NetworkedPlayer*)Pointers::GameServer::RRNetworkView.get_Owner[this].Invoke().Get(); }

	void RRNetworkView::TransferOwnership(SDK::RR::GameServer::NetworkedPlayer* networkedPlayer) {
		void* args[1] = { networkedPlayer };
		Pointers::GameServer::RRNetworkView.TransferOwnership[this].Invoke(args);
	}

	void RRNetworkView::RPC(const char* methodName, GameServer::NetworkedPlayer* networkedPlayer, Structs::IL2CPP::Il2CppArray* parameters) {
		auto methodNameString = IL2CPP::Utils::il2cpp_string_new(methodName);
		void* args[3] = { methodNameString, networkedPlayer, parameters };

		Pointers::GameServer::RRNetworkView.RPC_Player[this].Invoke(args);
	}

	void RRNetworkView::RPC(const char* methodName, int photonTargets, Structs::IL2CPP::Il2CppArray* parameters) {
		auto methodNameString = IL2CPP::Utils::il2cpp_string_new(methodName);
		void* args[3] = { methodNameString, &photonTargets, parameters };

		Pointers::GameServer::RRNetworkView.RPC[this].Invoke(args);
	}
}


namespace SDK::RR::Scripting {
	RRNetworkView* RRNetworkBehavior::get_NetworkedView() { return (RRNetworkView*)Pointers::GameServer::RRNetworkBehavior.get_NetworkedView[this].Invoke().Get(); }
}