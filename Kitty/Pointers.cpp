#include "Pointers.h"
#include "PointerIncludes.h"
#include "Logger.h"

void SDK::Pointers::Setup() {
	//Game
	Game::Player.Setup();
	Game::PlayerAvatar.Setup();
	Game::PlayerNameTag.Setup();
	Game::PlayerMovement.Setup();
	Game::PlayerHead.Setup();
	Game::PlayerHand.Setup();
	Game::PlayerGameRoleManager.Setup();
	Game::RangedWeapon.Setup();
	Game::ConsumableInfo.Setup();
	Game::EquipmentInfo.Setup();
	Game::ConsumableCollectionRuntimeConfig.Setup();
	Game::AvatarItemWardrobeRuntimeConfig.Setup();
	Game::Tool.Setup();
	Game::DrawingSurface.Setup();
	Game::RecRoomSceneManager.Setup();
	Game::LocalPlayerController.Setup();
	Game::ScreenPlayerController.Setup();
	Game::GameCombatManager.Setup();
	Game::GameTeamManager.Setup();
	Sleep(50);
	//GameServer
	GameServer::RRNetworkBehavior.Setup();
	GameServer::RRNetworkView.Setup();
	GameServer::RRNetworking.Setup();
	GameServer::Hashtable.Setup();
	Sleep(50);
	//Unity
	Unity::Object.Setup();
	Unity::GameObject.Setup();
	Unity::Component.Setup();
	Unity::Transform.Setup();
	Unity::Time.Setup();
	Unity::Camera.Setup();
	Unity::Resources.Setup();
	Unity::SphereCollider.Setup();
	Unity::Shader.Setup();
	Unity::Material.Setup();
	Unity::Renderer.Setup();
	Unity::LineRenderer.Setup();
	Unity::AssetBundle.Setup();
	Unity::Texture2D.Setup();
	Unity::ImageConversion.Setup();
	Sleep(50);
	//System
	System::Type.Setup();
	System::Uri.Setup();
	System::Object.Setup();
	System::ValueType.Setup();
	System::Dictionary.Setup();
	System::File.Setup();
	Logger::Log(clr::magenta, "[+] Finished Pointers");
	Sleep(50);
}