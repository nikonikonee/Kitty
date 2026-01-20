#include "PlayerNameTag.h"

namespace SDK::Pointers::Game {
	U_PlayerNameTag PlayerNameTag;

	void U_PlayerNameTag::Setup() {
		klass = IL2CPP::Backends::Class("", "", "PlayerNameTag");

		get_transform = klass.GetMethod("get_transform", 0);
	}
}