#include "RR_Game.h"

namespace SDK::RR::Game {
	void* PlayerGameRoleManager::get_Instance() { return Pointers::Game::PlayerGameRoleManager.get_Instance.Invoke().Get(); }
}

namespace SDK::RR::Game {
	bool PlayerMovement::get_IsFlyingEnabled() { return Pointers::Game::PlayerMovement.get_IsFlyingEnabled[this].Invoke().Unbox(); }

	void PlayerMovement::AddFlyEnabled(bool isEnabled, void* roleManager, int priority) {
		void* args[3] = { &isEnabled, roleManager, &priority };
		Pointers::Game::PlayerMovement.AddFlyEnabled[this].Invoke(args);
	}

	void PlayerMovement::RemoveFlyEnabled(void* roleManager) {
		void* args[1] = { roleManager };
		Pointers::Game::PlayerMovement.RemoveFlyEnabled[this].Invoke(args);
	}

	void PlayerMovement::AddMaxWalkSpeed(float value, void* roleManager, int priority) {
		void* args[3] = { &value, roleManager, &priority };
		Pointers::Game::PlayerMovement.AddMaxWalkSpeed[this].Invoke(args);
	}

	void PlayerMovement::RemoveMaxWalkSpeed(void* roleManager) {
		void* args[1] = { roleManager };
		Pointers::Game::PlayerMovement.RemoveMaxWalkSpeed[this].Invoke(args);
	}

	void PlayerMovement::AddMaxJumpHeight(float value, void* roleManager, int priority) {
		void* args[3] = { &value, roleManager, &priority };
		Pointers::Game::PlayerMovement.AddMaxJumpHeight[this].Invoke(args);
	}

	void PlayerMovement::RemoveMaxJumpHeight(void* roleManager) {
		void* args[1] = { roleManager };
		Pointers::Game::PlayerMovement.RemoveMaxJumpHeight[this].Invoke(args);
	}
}

namespace SDK::RR::Game {
	bool PlayerAvatar::get_UsesFullBodyAvatar() { return Pointers::Game::PlayerAvatar.get_UsesFullBodyAvatar[this].Invoke().Unbox(); }
}

namespace SDK::RR::Game {
	Unity::Transform* PlayerNameTag::get_transform() { return (Unity::Transform*)Pointers::Game::PlayerNameTag.get_transform[this].Invoke().Get(); }
}

namespace SDK::RR::Game {
	Unity::SphereCollider* PlayerCollider::sphereColliderHolder() { return *(Unity::SphereCollider**)((uint64_t)this + 0x70); }
}

namespace SDK::RR::Game {
	PlayerCollider* PlayerHead::get_HeadPlayerCollider() { return (PlayerCollider*)Pointers::Game::PlayerHead.get_HeadPlayerCollider[this].Invoke().Get(); }
}


namespace SDK::RR::Game {
	bool PlayerHand::TryPickupTool(Tool* tool, bool one, bool two, bool three) {
		void* args[4] = { tool, &one, &two, &three };
		return Pointers::Game::PlayerHand.TryPickupTool[this].Invoke(args).Unbox();
	}
}


namespace SDK::RR::Game {
	Player* Player::get_LocalPlayer() { return (Player*)Pointers::Game::Player.get_LocalPlayer.Invoke().Get(); }
	GameServer::NetworkedPlayer* Player::get_NetworkedPlayer() { return (GameServer::NetworkedPlayer*)Pointers::Game::Player.get_NetworkedPlayer[this].Invoke().Get(); }

	PlayerChat* Player::get_PlayerChat() { return (PlayerChat*)Pointers::Game::Player.get_PlayerChat[this].Invoke().Get(); }
	PlayerMovement* Player::get_PlayerMovement() { return (PlayerMovement*)Pointers::Game::Player.get_PlayerMovement[this].Invoke().Get(); }
	PlayerAvatar* Player::get_PlayerAvatar() { return (PlayerAvatar*)Pointers::Game::Player.get_PlayerAvatar[this].Invoke().Get(); }
	PlayerNameTag* Player::get_PlayerNameTag() { return (PlayerNameTag*)Pointers::Game::Player.get_PlayerNameTag[this].Invoke().Get(); }
	PlayerModeration* Player::get_PlayerModeration() { return (PlayerModeration*)Pointers::Game::Player.get_PlayerModeration[this].Invoke().Get(); }
	PlayerProgression* Player::get_PlayerProgression() { return (PlayerProgression*)Pointers::Game::Player.get_PlayerProgression[this].Invoke().Get(); }

	PlayerHead* Player::get_Head() { return (PlayerHead*)Pointers::Game::Player.get_Head[this].Invoke().Get(); }
	PlayerBody* Player::get_Body() { return (PlayerBody*)Pointers::Game::Player.get_Body[this].Invoke().Get(); }
	PlayerHand* Player::get_LeftHand() { return (PlayerHand*)Pointers::Game::Player.get_LeftHand[this].Invoke().Get(); }
	PlayerHand* Player::get_RightHand() { return (PlayerHand*)Pointers::Game::Player.get_RightHand[this].Invoke().Get(); }

	int Player::get_PlayerIndex() { return Pointers::Game::Player.get_PlayerIndex[this].Invoke().Unbox(); }
	Structs::Mono::String* Player::get_PlayerName() { return Pointers::Game::Player.get_PlayerName[this].Invoke().Get(); }
	Structs::Mono::Array<Tool**>* Player::get_AllToolsHeld() { return (Structs::Mono::Array<Tool**>*)Pointers::Game::Player.get_AllToolsHeld[this].Invoke().Get(); }

	void Player::SetHeadScale(float scale) {
		void* args[1] = { &scale };
		Pointers::Game::Player.SetHeadScale[this].Invoke(args);
	}
}

namespace SDK::RR::Game {
	float RangedWeapon::bulletFireSpeed() { return *(float*)((uint64_t)this + 0x230); }
	Unity::Transform* RangedWeapon::barrelTransform() { return *(Unity::Transform**)((uint64_t)this + 0x280); }

	void RangedWeapon::Fire(float charge) {
		void* args[1] = { &charge };
		Pointers::Game::RangedWeapon.Fire[this].Invoke(args);
	}
}

namespace SDK::RR::Game {
	void DrawingSurface::LoadDrawing(Unity::Texture2D* tex) {
		void* args[1] = { tex };

		Pointers::Game::DrawingSurface.LoadDrawing[this].Invoke(args);
	}
}

namespace SDK::RR::Game {
	RecRoomSceneManager* RecRoomSceneManager::get_Instance() { return (RecRoomSceneManager*)Pointers::Game::RecRoomSceneManager.get_Instance.Invoke().Get(); }
}

namespace SDK::RR::Game {
	int GameCombatManager::GetPlayerHealth(GameServer::NetworkedPlayer* player) {
		void* args[1] = { player };
		return Pointers::Game::GameCombatManager.GetPlayerHealth[this].Invoke(args).Unbox();
	}

	bool GameCombatManager::PlayerIsAlive(GameServer::NetworkedPlayer* player) {
		void* args[1] = { player };
		return Pointers::Game::GameCombatManager.PlayerIsAlive[this].Invoke(args).Unbox();
	}

	bool GameCombatManager::IsPlayerDownButNotOut(GameServer::NetworkedPlayer* player) {
		void* args[1] = { player };
		return Pointers::Game::GameCombatManager.IsPlayerDownButNotOut[this].Invoke(args).Unbox();
	}

	void GameCombatManager::MasterSetPlayerHealth(GameServer::NetworkedPlayer* player, int health) {
		void* args[2] = { player, &health };
		Pointers::Game::GameCombatManager.MasterSetPlayerHealth[this].Invoke(args);
	}

	void GameCombatManager::MasterKillPlayer(GameServer::NetworkedPlayer* player) {
		void* args[1] = { player };
		Pointers::Game::GameCombatManager.MasterKillPlayer[this].Invoke(args);
	}

	void GameCombatManager::MasterRequestPlayerInvincibility(GameServer::NetworkedPlayer* player, float time) {
		void* args[2] = { player, &time };
		Pointers::Game::GameCombatManager.MasterRequestPlayerInvincibility[this].Invoke(args);
	}
}

namespace SDK::RR::Game {
	int GameTeamManager::GetPlayerTeam(GameServer::NetworkedPlayer* player) {
		void* args[1] = { player };
		return Pointers::Game::GameTeamManager.GetPlayerTeam[this].Invoke(args).Unbox();
	}
}


namespace SDK::RR::Game {
	Structs::Mono::String* SerializedEquipmentSkinId::ToString() { return Pointers::Runtime::Game::SerializedEquipmentSkinId.ToString[this].Invoke().Get(); }
}

namespace SDK::RR::Game {
	Structs::Mono::String* EquipmentData::prefabName() { return *(Structs::Mono::String**)((uint64_t)this + 0x10); }
	Structs::Mono::String* EquipmentData::giftboxPrefabName() { return *(Structs::Mono::String**)((uint64_t)this + 0x18); }
}

namespace SDK::RR::Game {
	Structs::Mono::String* SkinData::skinAssetName() { return *(Structs::Mono::String**)((uint64_t)this + 0x10); }
	SerializedEquipmentSkinId* SkinData::equipmentSkinId() { return *(SerializedEquipmentSkinId**)((uint64_t)this + 0x18); }
}

namespace SDK::RR::Game {
	EquipmentData* EquipmentSkinMappingData::equipment() { return *(EquipmentData**)((uint64_t)this + 0x10); }
	Structs::Mono::List<SkinData**>* EquipmentSkinMappingData::skins() { return *(Structs::Mono::List<SkinData**>**)((uint64_t)this + 0x18); }
}

namespace SDK::RR::Game {
	Structs::Mono::List<EquipmentSkinMappingData**>* EquipmentWardrobeRuntimeConfig::toolSkinMaps() { return *(Structs::Mono::List<EquipmentSkinMappingData**>**)((uint64_t)this + 0x28); }
}

namespace SDK::RR::Game {
	EquipmentWardrobeRuntimeConfig* EquipmentInfo::get_Config() { return (EquipmentWardrobeRuntimeConfig*)Pointers::Game::EquipmentInfo.get_Config.Invoke().Get(); }
}