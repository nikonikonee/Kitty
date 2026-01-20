#pragma once
#include "PointerUtils.h"
#include "RetSpoofer/RetSpoofer.hpp"


namespace SDK::RR::Base {
	//Base (Inheritence)
	struct Object;
	struct Component;
	struct Behaviour;
	struct MonoBehaviour;
}

namespace SDK::RR::Unity {
	struct Transform;
	struct GameObject;
	struct SphereCollider;
	
	struct Shader;
	struct Material;
	
	struct Renderer;
	struct LineRenderer;
	struct SkinnedMeshRenderer;

	struct AssetBundle;

	struct Camera;
	struct Time;

	struct Texture2D;
	struct ImageConversion;
}

namespace SDK::RR::System {
	struct Type;
	struct Uri;
	struct File;
}

namespace SDK::RR::Scripting {
	struct RRNetworkView;
	struct RRNetworkBehavior;
}

namespace SDK::RR::GameServer {
	struct NetworkedPlayer;
	struct RRNetworking;
	struct Hashtable;
}

namespace SDK::RR::Game {
	struct PlayerGameRoleManager;
	struct PlayerChat;
	struct PlayerMovement;
	struct PlayerAvatar;
	struct PlayerNameTag;
	struct PlayerProgression;
	struct PlayerCollider;
	struct PlayerHead;
	struct PlayerBody;
	struct PlayerHand;
	struct Player;

	struct GameCombatManager;
	struct GameTeamManager;

	struct Weapon;
	struct RangedWeapon;
	struct Tool;

	struct DrawingSurface;
	struct RecRoomSceneManager;

	struct CreationObject;
	struct NetworkTransform;

	struct SerializedEquipmentSkinId;
	struct EquipmentData;
	struct SkinData;
	struct EquipmentSkinMappingData;
	struct EquipmentWardrobeRuntimeConfig;
	struct EquipmentInfo;
}