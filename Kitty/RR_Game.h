#pragma once
#include "RR_Includes.h"
#include "RR_Scripting.h"
#include "RR_Base.h"

namespace SDK::RR::Game {
	struct PlayerGameRoleManager {
		static void* get_Instance();
	};

	struct PlayerChat : Scripting::RRNetworkBehavior {};
}

namespace SDK::RR::Game {
	struct PlayerMovement : Scripting::RRNetworkBehavior {
		bool get_IsFlyingEnabled();

		void AddFlyEnabled(bool isEnabled, void* roleManager, int priority = 0x0);
		void RemoveFlyEnabled(void* roleManager);

		void AddMaxWalkSpeed(float value, void* roleManager, int priority = 0x0);
		void RemoveMaxWalkSpeed(void* roleManager);

		void AddMaxJumpHeight(float value, void* roleManager, int priority = 0x0);
		void RemoveMaxJumpHeight(void* roleManager);
	};

	struct PlayerNameTag : Base::MonoBehaviour {
		Unity::Transform* get_transform();
	};

	struct PlayerModeration : Scripting::RRNetworkBehavior {};

	struct PlayerAvatar : Scripting::RRNetworkBehavior {
		bool get_UsesFullBodyAvatar();
	};


	struct PlayerProgression : Scripting::RRNetworkBehavior {};
}

namespace SDK::RR::Game {
	struct PlayerCollider {
		Unity::SphereCollider* sphereColliderHolder();
	};
}

namespace SDK::RR::Game {
	struct PlayerHead : Scripting::RRNetworkBehavior {
		PlayerCollider* get_HeadPlayerCollider();
	};

	struct PlayerBody : Base::MonoBehaviour {};

	struct PlayerHand : Scripting::RRNetworkBehavior {
		bool TryPickupTool(Tool* tool, bool one = false, bool two = false, bool three = false);
	};
}

namespace SDK::RR::Game {
	struct Player : Scripting::RRNetworkBehavior {
		static Player* get_LocalPlayer();
		GameServer::NetworkedPlayer* get_NetworkedPlayer();

		PlayerChat* get_PlayerChat();
		PlayerMovement* get_PlayerMovement();
		PlayerAvatar* get_PlayerAvatar();
		PlayerNameTag* get_PlayerNameTag();
		PlayerModeration* get_PlayerModeration();
		PlayerProgression* get_PlayerProgression();

		PlayerHead* get_Head();
		PlayerBody* get_Body();
		PlayerHand* get_LeftHand();
		PlayerHand* get_RightHand();

		int get_PlayerIndex();
		Structs::Mono::String* get_PlayerName();
		Structs::Mono::Array<Tool**>* get_AllToolsHeld();

		void SetHeadScale(float scale);
	};
}

namespace SDK::RR::Game {
	struct Weapon : Scripting::RRNetworkBehavior {};

	struct RangedWeapon : Weapon {
		float bulletFireSpeed();
		Unity::Transform* barrelTransform();

		void Fire(float charge = 1.0f);
	};
}

namespace SDK::RR::Game {
	struct Tool : Scripting::RRNetworkBehavior {};

	struct DrawingSurface : Scripting::RRNetworkBehavior {
		void LoadDrawing(Unity::Texture2D* tex);
	};

	struct RecRoomSceneManager : Scripting::RRNetworkBehavior {
		static RecRoomSceneManager* get_Instance();
	};
}

namespace SDK::RR::Game {
	struct GameCombatManager : Scripting::RRNetworkBehavior {
		int GetPlayerHealth(GameServer::NetworkedPlayer* player);
		
		bool PlayerIsAlive(GameServer::NetworkedPlayer* player);
		bool IsPlayerDownButNotOut(GameServer::NetworkedPlayer* player);

		void MasterSetPlayerHealth(GameServer::NetworkedPlayer* player, int health);
		void MasterKillPlayer(GameServer::NetworkedPlayer* player);
		void MasterRequestPlayerInvincibility(GameServer::NetworkedPlayer* player, float time);
	};

	struct GameTeamManager : Scripting::RRNetworkBehavior {
		int GetPlayerTeam(GameServer::NetworkedPlayer* player);
	};
}

namespace SDK::RR::Game {
	struct CreationObject : Scripting::RRNetworkBehavior {};
	struct NetworkTransform : Scripting::RRNetworkBehavior {};

	struct SerializedEquipmentSkinId {
		Structs::Mono::String* ToString();
	};

	struct EquipmentData {
		Structs::Mono::String* prefabName();
		Structs::Mono::String* giftboxPrefabName();
	};

	struct SkinData {
		Structs::Mono::String* skinAssetName();
		SerializedEquipmentSkinId* equipmentSkinId();
	};

	struct EquipmentSkinMappingData {
		EquipmentData* equipment();
		Structs::Mono::List<SkinData**>* skins();
	};

	struct EquipmentWardrobeRuntimeConfig {
		Structs::Mono::List<EquipmentSkinMappingData**>* toolSkinMaps();
	};

	struct EquipmentInfo {
		static EquipmentWardrobeRuntimeConfig* get_Config();
	};
}