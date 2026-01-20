#include "PlayerMovement.h"

namespace SDK::Pointers::Game {
	U_PlayerMovement PlayerMovement;

	void U_PlayerMovement::Setup() {
		klass = IL2CPP::Backends::Class("", "RecRoom.Core.Locomotion", "PlayerMovement");

		AddFlyEnabled = klass.GetMethod("AddFlyEnabled", 3);
		RemoveFlyEnabled = klass.GetMethod("RemoveFlyEnabled", 1);

		AddMaxWalkSpeed = klass.GetMethod("AddMaxWalkSpeed", 3);
		RemoveMaxWalkSpeed = klass.GetMethod("RemoveMaxWalkSpeed", 1);

		AddMaxJumpHeight = klass.GetMethod("AddMaxJumpHeight", 3);
		RemoveMaxJumpHeight = klass.GetMethod("RemoveMaxJumpHeight", 1);

		get_IsFlyingEnabled = klass.GetMethod("get_IsFlyingEnabled", 0);
	}
}