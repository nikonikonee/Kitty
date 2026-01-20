#include "ESP.h"

#undef min
#undef max

void Cheats::Visuals::ESP::Run() {
	ImVec2 center = ImVec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2);
	ImVec2 top = ImVec2(ImGui::GetIO().DisplaySize.x / 2, 0.0f);

	if (players.empty())
		return;

	auto camera = SDK::RR::Unity::Camera::getCamera(0);
	if (!camera)
		return;

	auto localPlayer = SDK::RR::Game::Player::get_LocalPlayer();
	if (!localPlayer)
		return;

	auto localHead = localPlayer->get_Head();
	if (!localHead)
		return;

	auto localHeadTransform = localHead->get_transform();
	if (!localHeadTransform)
		return;

	auto networkedPlayer = localPlayer->get_NetworkedPlayer();
	if (!networkedPlayer)
		return;

	ImVec4 lineColor = (Globals::Vars::Visuals::customLineColor && !Globals::Vars::Visuals::teamCheck) ? Globals::Vars::Visuals::Var::lineColor : ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
	ImVec4 nameColor = (Globals::Vars::Visuals::customNameColor && !Globals::Vars::Visuals::teamCheck) ? Globals::Vars::Visuals::Var::nameColor : ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
	ImVec4 skeletonColor = (Globals::Vars::Visuals::customSkeletonColor && !Globals::Vars::Visuals::teamCheck) ? Globals::Vars::Visuals::Var::skeletonColor : ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
	ImVec4 boxColor = (Globals::Vars::Visuals::customBoxColor && !Globals::Vars::Visuals::teamCheck) ? Globals::Vars::Visuals::Var::boxColor : ImVec4(1.0f, 1.0f, 1.0f, 1.0f);

	for (auto plr : players) {
		if (plr.instance && plr.instance != localPlayer && plr.head && plr.body && plr.leftHand && plr.rightHand && plr.instance->get_PlayerNameTag()) {
			if (plr.headTransform && plr.bodyTransform && plr.leftHandTransfrom && plr.rightHandTransform && plr.instance->get_PlayerNameTag()->get_transform()) {
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

				if ((!isAlive || isDownButNotOut) && Globals::Vars::Visuals::healthCheck)
					continue;

				if (Globals::Vars::Visuals::rainbowColors && !Globals::Vars::Visuals::teamCheck)
					lineColor = Globals::Vars::Visuals::Var::rainbowColor, nameColor = Globals::Vars::Visuals::Var::rainbowColor, skeletonColor = Globals::Vars::Visuals::Var::rainbowColor, boxColor = Globals::Vars::Visuals::Var::rainbowColor;

				if (Globals::Vars::Visuals::teamCheck) {

					if (playerTeam == localPlayerTeam && !Globals::Vars::Visuals::renderTeammates)
						continue;

					lineColor = (playerTeam != localPlayerTeam) ? ImVec4(1, 0, 0, 1) : ImVec4(0, 0, 1, 1);
					nameColor = (playerTeam != localPlayerTeam) ? ImVec4(1, 0, 0, 1) : ImVec4(0, 0, 1, 1);
					skeletonColor = (playerTeam != localPlayerTeam) ? ImVec4(1, 0, 0, 1) : ImVec4(0, 0, 1, 1);
					boxColor = (playerTeam != localPlayerTeam) ? ImVec4(1, 0, 0, 1) : ImVec4(0, 0, 1, 1);
				}

				auto headPosition = plr.headTransform->get_position();
				auto headScreenPosition = camera->WorldToScreenPoint(headPosition);
				
				auto headBoxPosition = headPosition + SDK::Structs::Unity::Vector3(0, 0.3, 0);
				auto headScreenPositionBox = camera->WorldToScreenPoint(headBoxPosition);

				auto nameTagPosition = plr.instance->get_PlayerNameTag()->get_transform()->get_position() + SDK::Structs::Unity::Vector3(0, 0.4, 0);
				auto nameTagScreenPosition = camera->WorldToScreenPoint(nameTagPosition);

				auto bodyPosition = plr.bodyTransform->get_position();
				auto bodyScreenPosition = camera->WorldToScreenPoint(bodyPosition);

				SDK::Structs::Unity::Vector3 headTextPosition = (plr.usesFullBodyAvatar) 
					? headPosition - SDK::Structs::Unity::Vector3(0.1, 1.3, 0.1)
					: headPosition - SDK::Structs::Unity::Vector3(0, 0.480, 0);

				SDK::Structs::Unity::Vector3 bodyBoxPosition = (plr.usesFullBodyAvatar)
					? bodyPosition - SDK::Structs::Unity::Vector3(0, 0.88, 0)
					: bodyBoxPosition = bodyPosition - SDK::Structs::Unity::Vector3(0.1, 0.430, 0);

				auto headScreenPositionText = camera->WorldToScreenPoint(headTextPosition);
				auto bodyScreenPositionBox = camera->WorldToScreenPoint(bodyBoxPosition);

				auto leftHandPosition = plr.leftHandTransfrom->get_position();
				auto leftHandScreenPosition = camera->WorldToScreenPoint(leftHandPosition);

				auto rightHandPosition = plr.rightHandTransform->get_position();
				auto rightHandScreenPosition = camera->WorldToScreenPoint(rightHandPosition);

				auto headDistance = SDK::Structs::Unity::Vector3::Distance(headPosition, localHeadTransform->get_position());

				if (Globals::Vars::Visuals::lines && headScreenPosition.Z > 1.f && headDistance > 15.0f) {
					auto desiredScreenPosition = (Globals::Vars::Visuals::useBody) ? bodyScreenPosition : headScreenPosition;

					(Globals::Vars::Visuals::topScreen)
						? Draw::DrawLine(top, ImVec2(desiredScreenPosition.X, desiredScreenPosition.Y), lineColor)
						: Draw::DrawLine(center, ImVec2(desiredScreenPosition.X, desiredScreenPosition.Y), lineColor);
				}

				if (plr.playerName && Globals::Vars::Visuals::names && nameTagScreenPosition.Z > 1.f) {
					ImVec2 textSize = ImGui::CalcTextSize(plr.playerName->getString().c_str());
					ImVec2 centeredPos = ImVec2(nameTagScreenPosition.X - (textSize.x / 2), nameTagScreenPosition.Y);
					Draw::DrawTxt(centeredPos, plr.playerName->getString().c_str(), nameColor);
				}

				if (Globals::Vars::Visuals::skeletons && headScreenPosition.Z > 1.f && bodyScreenPosition.Z > 1.f && leftHandScreenPosition.Z > 1.f && rightHandScreenPosition.Z > 1.f) {
					Draw::DrawLine(ImVec2(headScreenPosition.X, headScreenPosition.Y), ImVec2(bodyScreenPosition.X, bodyScreenPosition.Y), skeletonColor);
					Draw::DrawLine(ImVec2(bodyScreenPosition.X, bodyScreenPosition.Y), ImVec2(leftHandScreenPosition.X, leftHandScreenPosition.Y), skeletonColor);
					Draw::DrawLine(ImVec2(bodyScreenPosition.X, bodyScreenPosition.Y), ImVec2(rightHandScreenPosition.X, rightHandScreenPosition.Y), skeletonColor);
				}
				if (Globals::Vars::Visuals::boxes && headScreenPositionBox.Z > 1.f && bodyScreenPositionBox.Z > 1.f) {

					float height = abs(headScreenPositionBox.Y - bodyScreenPositionBox.Y);
					float width = (plr.usesFullBodyAvatar) ? height * 0.32f : height * 0.52f;

					SDK::Structs::Unity::Vector2 box = { headScreenPositionBox.X - (width / 2), headScreenPositionBox.Y };

					if (Globals::Vars::Visuals::outlines)
						Draw::DrawBoxOutlined(box.X, box.Y, width, height, boxColor, Globals::Vars::Visuals::Var::outlineThickness);
					else if (Globals::Vars::Visuals::filledBoxes)
						Draw::DrawBoxFilled(box.X, box.Y, width, height, boxColor);
					else if (Globals::Vars::Visuals::cornerBoxes)
						Draw::DrawBoxCornered(box.X, box.Y, width, height, 1.0f, boxColor);
					else
						Draw::DrawBox(box.X, box.Y, width, height, boxColor);
				}
			}
		}
	}
}