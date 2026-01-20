#pragma once
#include "Includes.h"

namespace SDK::Pointers::Game {
	struct U_Player {
		IL2CPP::Backends::Class klass;

		//Basic Ptrs
		IL2CPP::Backends::Method<void*> get_LocalPlayer;
		IL2CPP::Backends::Method<void*> get_NetworkedPlayer;
		IL2CPP::Backends::Method<void*> get_PlayerChat;
		IL2CPP::Backends::Method<void*> get_PlayerMovement;
		IL2CPP::Backends::Method<void*> get_PlayerAvatar;
		IL2CPP::Backends::Method<void*> get_PlayerNameTag;
		IL2CPP::Backends::Method<void*> get_PlayerModeration;
		IL2CPP::Backends::Method<void*> get_PlayerProgression;
		//Body
		IL2CPP::Backends::Method<void*> get_Head;
		IL2CPP::Backends::Method<void*> get_Body;
		IL2CPP::Backends::Method<void*> get_LeftHand;
		IL2CPP::Backends::Method<void*> get_RightHand;
		//Retrieving Information On Player
		IL2CPP::Backends::Method<int> get_PlayerIndex;
		IL2CPP::Backends::Method<Structs::Mono::String*> get_PlayerName;
		IL2CPP::Backends::Method<Structs::Mono::Array<void**>*> get_AllToolsHeld;
		//Functions
		IL2CPP::Backends::Method<void> SetHeadScale;
		IL2CPP::Backends::Method<void> RpcAuthorityCV2SetPosition;
		IL2CPP::Backends::Method<void> RpcAuthorityCV2SetRotation;

		void Setup();
	};
	extern U_Player Player;
}