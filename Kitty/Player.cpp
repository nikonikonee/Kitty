#include "Player.h"

namespace SDK::Pointers::Game {
	U_Player Player;

	void U_Player::Setup() {
		klass = IL2CPP::Backends::Class("", "", "Player");

		get_LocalPlayer = klass.GetMethod("get_LocalPlayer", 0);
		get_NetworkedPlayer = klass.GetMethod("get_NetworkedPlayer", 0);
		get_PlayerChat = klass.GetMethod("get_PlayerChat", 0);
		get_PlayerMovement = klass.GetMethod("get_PlayerMovement", 0);
		get_PlayerAvatar = klass.GetMethod("get_PlayerAvatar", 0);
		get_PlayerNameTag = klass.GetMethod("get_PlayerNameTag", 0);
		get_PlayerModeration = klass.GetMethod("get_PlayerModeration", 0);
		get_PlayerProgression = klass.GetMethod("get_PlayerProgression", 0);

		get_Head = klass.GetMethod("get_Head", 0);
		get_Body = klass.GetMethod("get_Body", 0);
		get_LeftHand = klass.GetMethod("get_LeftHand", 0);
		get_RightHand = klass.GetMethod("get_RightHand", 0);

		get_PlayerIndex = klass.GetMethod("get_PlayerIndex", 0);
		get_PlayerName = klass.GetMethod("get_PlayerName", 0);
		get_AllToolsHeld = klass.GetMethod("get_AllToolsHeld", 0);

		SetHeadScale = klass.GetMethod("SetHeadScale", 1);
		RpcAuthorityCV2SetPosition = klass.GetMethod("RpcAuthorityCV2SetPosition", 1);
		RpcAuthorityCV2SetRotation = klass.GetMethod("RpcAuthorityCV2SetRotation", 1);
	}
}