#pragma once
#include "Includes.h"

namespace SDK::Pointers::GameServer {
	struct U_RRNetworkView {
		IL2CPP::Backends::Class klass;
		
		IL2CPP::Backends::Method<void*> get_View;
		IL2CPP::Backends::Method<void*> get_ViewId;
		IL2CPP::Backends::Method<void*> get_NetworkId;

		IL2CPP::Backends::Method<int> get_OwnerActorNr;
		IL2CPP::Backends::Method<void*> get_Owner;

		IL2CPP::Backends::Method<void> TransferOwnership;
		IL2CPP::Backends::Method<bool> RemoveNetworkView;

		IL2CPP::Backends::Method<void> RPC;
		IL2CPP::Backends::Method<void> RPC_Player;

		void Setup();
	};
	extern U_RRNetworkView RRNetworkView;
}