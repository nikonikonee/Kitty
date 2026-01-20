#include "PlayerAvatar.h"

namespace SDK::Pointers::Game {
	U_PlayerAvatar PlayerAvatar;

	void U_PlayerAvatar::Setup() {
		klass = IL2CPP::Backends::Class("", "", "PlayerAvatar");

		get_UsesFullBodyAvatar = klass.GetMethod("get_UsesFullBodyAvatar", 0);
	}
}