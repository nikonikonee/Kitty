#include "AimbotUtils.h"

SDK::RR::Game::RangedWeapon* Cheats::Combat::Aimbot::Utils::GetLocalPlayerWeapon() {
	auto localPlayer = SDK::RR::Game::Player::get_LocalPlayer();
	if (localPlayer) {
		auto toolsHeld = localPlayer->get_AllToolsHeld();
		for (int i = 0; i < toolsHeld->getLength(); ++i) {
			auto tool = toolsHeld->getPointer()[i];
			if (tool) {
				auto rangedWeapon = tool->GetComponent<SDK::RR::Game::RangedWeapon*>(SDK::RR::System::Type::GetType("RecRoom.Core.Combat.RangedWeapon, Assembly-CSharp"));
				if (rangedWeapon) {
					return rangedWeapon;
				}
			}
		}
	}
	return nullptr;
}

SDK::RR::Game::RangedWeapon* Cheats::Combat::Aimbot::Utils::GetWeaponFromPlayer(SDK::RR::Game::Player* player) {
	if (player) {
		auto toolsHeld = player->get_AllToolsHeld();
		for (int i = 0; i < toolsHeld->getLength(); ++i) {
			auto tool = toolsHeld->getPointer()[i];
			if (tool) {
				auto rangedWeapon = tool->GetComponent<SDK::RR::Game::RangedWeapon*>(SDK::RR::System::Type::GetType("RecRoom.Core.Combat.RangedWeapon, Assembly-CSharp"));
				if (rangedWeapon) {
					return rangedWeapon;
				}
			}
		}
	}
	return nullptr;
}

SDK::RR::Game::Player* Cheats::Combat::Aimbot::Utils::GetClosestPlayer() {
	SDK::RR::Game::Player* bestPlayer = nullptr;
	float bestDot = -1.0f;
	
	if (players.empty())
		return nullptr;

	auto weapon = GetLocalPlayerWeapon();
	if (!weapon) return nullptr;

	auto localPlayer = SDK::RR::Game::Player::get_LocalPlayer();
	if (!localPlayer) return nullptr;

	auto networkedPlayer = localPlayer->get_NetworkedPlayer();
	if (!networkedPlayer)
		return nullptr;

	for (auto& plr : players) {
		if (plr.instance) {
			if (plr.head && plr.headTransform) {
				auto weaponTransform = weapon->get_transform();
				if (weaponTransform && Globals::Vars::Runtime::Instance::GameTeamManager) {
					bool isAlive{}, isDownButNotOut{};
					//temp vars to store everything :p
					int localPlayerTeam{}, playerTeam{};

					if (Globals::Vars::Runtime::Instance::GameCombatManager) {
						auto instance = (SDK::RR::Game::GameCombatManager*)Globals::Vars::Runtime::Instance::GameCombatManager;
						isAlive = instance->PlayerIsAlive(plr.networkedPlayer);
						isDownButNotOut = instance->IsPlayerDownButNotOut(plr.networkedPlayer);
					}

					if (Globals::Vars::Runtime::Instance::GameTeamManager) {
						auto instance = (SDK::RR::Game::GameTeamManager*)Globals::Vars::Runtime::Instance::GameTeamManager;
						localPlayerTeam = instance->GetPlayerTeam(networkedPlayer);
						playerTeam = instance->GetPlayerTeam(plr.networkedPlayer);
					}

					if ((!isAlive || isDownButNotOut) && Globals::Vars::Aimbot::healthCheck)
						continue;

					if (playerTeam == localPlayerTeam && Globals::Vars::Aimbot::teamCheck)
						continue;

					auto weaponForward = weaponTransform->get_forward();
					auto weaponPosition = weaponTransform->get_position();
					
					auto playerHeadPosition = plr.headTransform->get_position();

					auto directionToTarget = SDK::Structs::Unity::Vector3::Normalized(playerHeadPosition - weaponPosition);
					auto calculatedDotProduct = SDK::Structs::Unity::Vector3::Dot(weaponForward, directionToTarget);

					auto aimStrictness = Globals::Vars::Aimbot::overrideSilentAimStrictness 
						? Globals::Vars::Aimbot::Var::silentAimRangeStrictness 
						: 0.7f;

					if (calculatedDotProduct > aimStrictness && calculatedDotProduct > bestDot) {
						bestPlayer = plr.instance;
						bestDot = calculatedDotProduct;
					}
				}
			}
		}
	}

	return bestPlayer;
}

SDK::RR::Game::Player* Cheats::Combat::Aimbot::Utils::GetClosestPlayerFromWeapon(void* weapon) {
	return nullptr;
}

SDK::RR::Game::Player* Cheats::Combat::Aimbot::Utils::GetClosestPlayerWithinFOV() {
	ImVec2 center = ImVec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2);
	auto unityCenter = SDK::Structs::Unity::Vector2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2);

	SDK::RR::Game::Player* bestPlayer = nullptr;
	float bestFov = Globals::Vars::Aimbot::Var::circleSize;

	if (players.empty())
		return nullptr;


	auto camera = SDK::RR::Unity::Camera::getCamera(0);
	if (!camera) return nullptr;

	auto localPlayer = SDK::RR::Game::Player::get_LocalPlayer();
	if (!localPlayer) return nullptr;


	auto networkedPlayer = localPlayer->get_NetworkedPlayer();
	if (!networkedPlayer)
		return nullptr;

	for (auto& plr : players) {
		if (plr.instance && plr.instance != localPlayer) {
			if (plr.head && plr.headTransform) {
				bool isAlive{}, isDownButNotOut{};
				//temp vars to store everything :p
				int localPlayerTeam{}, playerTeam{};

				if (Globals::Vars::Runtime::Instance::GameCombatManager) {
					auto instance = (SDK::RR::Game::GameCombatManager*)Globals::Vars::Runtime::Instance::GameCombatManager;
					
					isAlive = instance->PlayerIsAlive(plr.networkedPlayer);
					isDownButNotOut = instance->IsPlayerDownButNotOut(plr.networkedPlayer);
				}

				if (Globals::Vars::Runtime::Instance::GameTeamManager) {
					auto instance = (SDK::RR::Game::GameTeamManager*)Globals::Vars::Runtime::Instance::GameTeamManager;
					
					localPlayerTeam = instance->GetPlayerTeam(networkedPlayer);
					playerTeam = instance->GetPlayerTeam(plr.networkedPlayer);
				}

				if ((!isAlive || isDownButNotOut) && Globals::Vars::Aimbot::healthCheck)
					continue;

				if (playerTeam == localPlayerTeam && Globals::Vars::Aimbot::teamCheck)
					continue;

				auto playerHeadPosition = plr.headTransform->get_position();
				auto playerHeadScreenPosition = camera->WorldToScreenPoint(playerHeadPosition);

				if (playerHeadScreenPosition.Z > 1.f)
				{
					auto distanceFromCenter = SDK::Structs::Unity::Vector2::Distance(unityCenter, { playerHeadScreenPosition.X, playerHeadScreenPosition.Y });

					if (distanceFromCenter < bestFov)
						bestFov = distanceFromCenter;

					if (distanceFromCenter == bestFov)
						bestPlayer = plr.instance;
				}
			}
		}
	}

	return bestPlayer;
}


SDK::RR::Game::Player* Cheats::Combat::Aimbot::Utils::GetClosestPlayerWithinStaticFOV(float fov) {
	ImVec2 center = ImVec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2);
	auto unityCenter = SDK::Structs::Unity::Vector2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2);

	SDK::RR::Game::Player* bestPlayer = nullptr;
	float bestFov = fov;

	if (players.empty())
		return nullptr;


	auto camera = SDK::RR::Unity::Camera::getCamera(0);
	if (!camera) return nullptr;

	auto localPlayer = SDK::RR::Game::Player::get_LocalPlayer();
	if (!localPlayer) return nullptr;


	for (auto& plr : players) {
		if (plr.instance && plr.instance != localPlayer) {
			if (plr.head && plr.headTransform) {

				auto playerHeadPosition = plr.headTransform->get_position();
				auto playerHeadScreenPosition = camera->WorldToScreenPoint(playerHeadPosition);

				if (playerHeadScreenPosition.Z > 1.f)
				{
					auto distanceFromCenter = SDK::Structs::Unity::Vector2::Distance(unityCenter, { playerHeadScreenPosition.X, playerHeadScreenPosition.Y });

					if (distanceFromCenter < bestFov)
						bestFov = distanceFromCenter;

					if (distanceFromCenter == bestFov)
						bestPlayer = plr.instance;
				}
			}
		}
	}

	return bestPlayer;
}