#include "Headers_Player.h"

void Render::GUI::Headers::Player::Render() {
	if (ImGui::CollapsingHeader("Player & Movement")) {
		ImGui::Checkbox("Force MP Scale", &Globals::Vars::Player::forceMpScale);

		ImGui::SeparatorText("Head Config");

		ImGui::PushItemWidth(105.0f);
		ImGui::InputFloat("##headScale", &Globals::Vars::Player::Var::headScale);
		ImGui::PopItemWidth();

		ImGui::SameLine();

		if (ImGui::Button("Change Head Size")) {
			auto localPlayer = SDK::RR::Game::Player::get_LocalPlayer();
			if (localPlayer)
				localPlayer->SetHeadScale(Globals::Vars::Player::Var::headScale);
		}

		if (ImGui::Button("Headless ##headScale")) {
			auto localPlayer = SDK::RR::Game::Player::get_LocalPlayer();
			if (localPlayer)
				localPlayer->SetHeadScale(0.01f);
		}

		ImGui::SameLine();

		if (ImGui::Button("Reset ##headScale")) {
			auto localPlayer = SDK::RR::Game::Player::get_LocalPlayer();
			if (localPlayer)
				localPlayer->SetHeadScale(1.0f);
		}

		ImGui::Separator();

		ImGui::Checkbox("Dynamic Fly", &Globals::Vars::Movement::dynamicFly);
		ImGui::Checkbox("Hybrid Movement", &Globals::Vars::Movement::hybridMovement);
		ImGui::Separator();
		if (ImGui::Button("Enable Static Fly")) {
			auto localPlayer = SDK::RR::Game::Player::get_LocalPlayer();
			auto roleManager = SDK::RR::Game::PlayerGameRoleManager::get_Instance();

			if (localPlayer && roleManager && localPlayer->get_PlayerMovement()) {
				localPlayer->get_PlayerMovement()->AddFlyEnabled(true, roleManager);
			}
		}
		ImGui::SameLine();
		if (ImGui::Button("Disable Static Fly")) {
			auto localPlayer = SDK::RR::Game::Player::get_LocalPlayer();
			auto roleManager = SDK::RR::Game::PlayerGameRoleManager::get_Instance();

			if (localPlayer && roleManager && localPlayer->get_PlayerMovement())
				localPlayer->get_PlayerMovement()->RemoveFlyEnabled(roleManager);
		}
		ImGui::Separator();
		ImGui::Checkbox("Static Fly Toggle", &Globals::Vars::Movement::staticFly);
		if (ImGui::Checkbox("Walkspeed Changer", &Globals::Vars::Movement::walkspeedChanger)) {
			if (!Globals::Vars::Movement::walkspeedChanger) {
				auto localPlayer = SDK::RR::Game::Player::get_LocalPlayer();
				auto roleManager = SDK::RR::Game::PlayerGameRoleManager::get_Instance();

				if (localPlayer && roleManager && localPlayer->get_PlayerMovement())
					localPlayer->get_PlayerMovement()->RemoveMaxWalkSpeed(roleManager);
			}
		}
		if (Globals::Vars::Movement::walkspeedChanger) {
			ImGui::Spacing();
			ImGui::SameLine();
			ImGui::SliderFloat("Walkspeed", &Globals::Vars::Movement::Var::walkspeedAmount, 0.0f, 200.0f);
		}
		if (ImGui::Checkbox("Jumpheight Changer", &Globals::Vars::Movement::jumpHeightChanger)) {
			if (!Globals::Vars::Movement::jumpHeightChanger) {
				auto localPlayer = SDK::RR::Game::Player::get_LocalPlayer();
				auto roleManager = SDK::RR::Game::PlayerGameRoleManager::get_Instance();

				if (localPlayer && roleManager && localPlayer->get_PlayerMovement())
					localPlayer->get_PlayerMovement()->RemoveMaxJumpHeight(roleManager);
			}
		}
		if (Globals::Vars::Movement::jumpHeightChanger) {
			ImGui::Spacing();
			ImGui::SameLine();
			ImGui::SliderFloat("Jumpheight", &Globals::Vars::Movement::Var::jumpHeightAmount, 0.0f, 200.0f);
		}
	}
}