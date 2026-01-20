#include "Hashtable.h"

namespace SDK::Pointers::GameServer {
	U_Hashtable Hashtable;

	void U_Hashtable::Setup() {
		klass = IL2CPP::Backends::Class("Photon3Unity3D", "ExitGames.Client.Photon", "Hashtable");

		set_Item = klass.GetSpecificMethod("set_Item", 2, "System.Byte");
		ToString = klass.GetMethod("ToString", 0);
	}
}