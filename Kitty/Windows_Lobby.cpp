#include "Windows_Lobby.h"

void Render::GUI::Windows::Lobby::Render() {
	ImGui::Begin("Lobby Panel (Beta)");
	if (ImGui::Button("Delete Map", ImVec2(ImGui::GetContentRegionAvail().x * 1.0f, 0.f)))
		Globals::Vars::Lobby::deleteMap = true;

	ImGui::Separator();

	if (ImGui::Button("Kill All", ImVec2(ImGui::GetContentRegionAvail().x * 1.0f, 0.f)))
		Globals::Vars::Lobby::killAll = true;

	if (ImGui::Button("Restore Health All", ImVec2(ImGui::GetContentRegionAvail().x * 1.0f, 0.f)))
		Globals::Vars::Lobby::restoreHealthAll = true;

	ImGui::Separator();

	if (ImGui::Button("Spawn Asset All", ImVec2(ImGui::GetContentRegionAvail().x * 1.0f, 0)))
		Globals::Vars::Lobby::spawnAssetAll = true;

	if (ImGui::Button("Force Hold All", ImVec2(ImGui::GetContentRegionAvail().x * 1.0f, 0)))
		Globals::Vars::Lobby::forceHoldAll = true;

	ImGui::Separator();

	if (ImGui::Button("Bring All", ImVec2(ImGui::GetContentRegionAvail().x * 1.0f, 0)))
		Globals::Vars::Lobby::bringAll = true;

	if (ImGui::Button("Bring All To Player", ImVec2(ImGui::GetContentRegionAvail().x * 1.0f, 0))) {
		Globals::Vars::Runtime::Var::needsToSelectPlayer = true;
		Globals::Vars::Lobby::bringAllToPlayer = true;
	}

	if (ImGui::Button("Void All", ImVec2(ImGui::GetContentRegionAvail().x * 0.5f, 0)))
		Globals::Vars::Lobby::voidAll = true;

	ImGui::SameLine();

	ImGui::Checkbox("Infinity Toggle", &Globals::Vars::PlayerList::infinityToggle);

	ImGui::End();
}