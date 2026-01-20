#include "RRNetworkBehavior.h"

namespace SDK::Pointers::GameServer {
	U_RRNetworkBehavior RRNetworkBehavior;

	void U_RRNetworkBehavior::Setup() {
		klass = IL2CPP::Backends::Class("RecRoom.Networking.RRNetworkLayer", "RecRoom.Networking", "RRNetworkBehavior");

		get_photonView = klass.GetMethod("get_photonView", 0);
		get_NetworkedView = klass.GetMethod("get_NetworkedView", 0);
	}
}