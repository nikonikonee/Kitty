#include "PlayerHand.h"

namespace SDK::Pointers::Game {
	U_PlayerHand PlayerHand;

	void U_PlayerHand::Setup() {
		klass = IL2CPP::Backends::Class("", "", "PlayerHand");

		TryPickupTool = klass.GetMethod("TryPickupTool", 4);
	}
}