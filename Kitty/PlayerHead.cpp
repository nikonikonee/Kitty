#include "PlayerHead.h"

namespace SDK::Pointers::Game {
	U_PlayerHead PlayerHead;

	void U_PlayerHead::Setup() {
		klass = IL2CPP::Backends::Class("", "", "PlayerHead");

		get_HeadPlayerCollider = klass.GetMethod("get_HeadPlayerCollider", 0);
	}
}