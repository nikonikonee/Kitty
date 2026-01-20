#include "AvatarItemWardrobeRuntimeConfig.h"

namespace SDK::Pointers::Game {
	U_AvatarItemWardrobeRuntimeConfig AvatarItemWardrobeRuntimeConfig;

	void U_AvatarItemWardrobeRuntimeConfig::Setup() {
		klass = IL2CPP::Backends::Class("", "RecRoom.Avatars.Data.Runtime", "AvatarItemWardrobeRuntimeConfig");

		get_Config = klass.GetMethod("get_Config", 0);

		caidToAvatarItemSelections = klass.GetField("caidToAvatarItemSelections");
	}
}