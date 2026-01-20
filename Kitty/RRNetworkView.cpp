#include "RRNetworkView.h"

namespace SDK::Pointers::GameServer {
	U_RRNetworkView RRNetworkView;

	void U_RRNetworkView::Setup() {
		klass = IL2CPP::Backends::Class("RecRoom.Networking.RRNetworkLayer", "RecRoom.Networking", "RRNetworkView");
	
		get_View = klass.GetMethod("get_View", 0);
		get_ViewId = klass.GetMethod("get_ViewId", 0);
		get_NetworkId = klass.GetMethod("get_NetworkId", 0);

		get_OwnerActorNr = klass.GetMethod("get_OwnerActorNr", 0);
		get_Owner = klass.GetMethod("get_Owner", 0);

		TransferOwnership = klass.GetSpecificMethod("TransferOwnership", 1, "NELIJLIGAOD");
		RemoveNetworkView = klass.GetMethod("RemoveNetworkView", 1);

		RPC = klass.GetMethod("RPC", 3);
		RPC_Player = klass.GetSpecificMethod("RPC", 3, "NELIJLIGAOD");
	}
}