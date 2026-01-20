#include "Windows_Assets.h"

void Render::GUI::Windows::Assets::Render() {
	ImGui::Begin("Asset Spawn Config Window");

	ImGui::BeginChild("##AssetSpawnConfig", ImVec2(ImGui::GetContentRegionAvail().x * 0.5f, 0), false);

	if (ImGui::Checkbox("Food Override Spawn", &Globals::Vars::Spawnables::foodOverrideSpawn))
		if (Globals::Vars::Spawnables::foodsploit)
			Globals::Vars::Spawnables::foodsploit = false; //Obviously cannot have both enabled
	ImGui::Checkbox("Take Photo Spawn", &Globals::Vars::Spawnables::takePhotoSpawn);
	ImGui::Checkbox("Print Photo Spawn", &Globals::Vars::Spawnables::printPhotoSpawn);
	ImGui::Checkbox("Share Button Spawn", &Globals::Vars::Spawnables::shareButtonSpawn);

	ImGui::Separator();

	ImGui::Checkbox("Custom Position ##Asset", &Globals::Vars::Spawnables::customAssetPosition);
	if (Globals::Vars::Spawnables::customAssetPosition) {
		ImGui::Spacing();
		ImGui::SameLine();
		ImGui::PushItemWidth(80.0f);

		ImGui::InputFloat("##xAssetPosition", &Globals::Vars::Spawnables::Var::assetPosition.X, 0.0f, 999.0f);
		ImGui::SameLine();
		ImGui::InputFloat("##yAssetPosition", &Globals::Vars::Spawnables::Var::assetPosition.Y, 0.0f, 999.0f);
		ImGui::SameLine();
		ImGui::InputFloat("##zAssetPosition", &Globals::Vars::Spawnables::Var::assetPosition.Z, 0.0f, 999.0f);

		ImGui::PopItemWidth();
	}
	ImGui::Checkbox("Custom Rotation ##Asset", &Globals::Vars::Spawnables::customAssetRotation);
	if (Globals::Vars::Spawnables::customAssetRotation) {
		ImGui::Spacing();
		ImGui::SameLine();
		ImGui::PushItemWidth(80.0f);

		ImGui::InputFloat("##xAssetRotation", &Globals::Vars::Spawnables::Var::assetRotation.X, 0.0f, 999.0f);
		ImGui::SameLine();
		ImGui::InputFloat("##yAssetRotation", &Globals::Vars::Spawnables::Var::assetRotation.Y, 0.0f, 999.0f);
		ImGui::SameLine();
		ImGui::InputFloat("##zAssetRotation", &Globals::Vars::Spawnables::Var::assetRotation.Z, 0.0f, 999.0f);
		ImGui::SameLine();
		ImGui::InputFloat("##wAssetRotation", &Globals::Vars::Spawnables::Var::assetRotation.W, 0.0f, 999.0f);

		ImGui::PopItemWidth();
	}
	ImGui::Separator();
	ImGui::Checkbox("Custom Amount ##Asset", &Globals::Vars::Spawnables::customAssetAmount);
	if (Globals::Vars::Spawnables::customAssetAmount) {
		ImGui::Spacing();
		ImGui::SameLine();
		ImGui::InputInt("##assetAmount", &Globals::Vars::Spawnables::Var::assetAmount);
	}
	ImGui::Checkbox("Custom Scale ##Asset", &Globals::Vars::Spawnables::customAssetScale);
	if (Globals::Vars::Spawnables::customAssetScale) {
		ImGui::Spacing();
		ImGui::SameLine();
		ImGui::PushItemWidth(80.0f);
		ImGui::InputFloat("##xAssetScale", &Globals::Vars::Spawnables::Var::assetScale.X);
		ImGui::SameLine();
		ImGui::InputFloat("##yAssetScale", &Globals::Vars::Spawnables::Var::assetScale.Y);
		ImGui::SameLine();
		ImGui::InputFloat("##zAssetScale", &Globals::Vars::Spawnables::Var::assetScale.Z);
		ImGui::PopItemWidth();
	}

	ImGui::Checkbox("No Render", &Globals::Vars::Spawnables::noAssetRender);

	ImGui::EndChild();

	ImGui::SameLine();
	ImGui::SeparatorEx(ImGuiSeparatorFlags_Vertical);
	ImGui::SameLine();

	ImGui::BeginChild("##AssetSelector", ImVec2(0, 0), false);

	static ImGuiTextFilter filter;
	filter.Draw("##AssetInput");
	ImGui::SameLine();
	if (ImGui::Button("Clear ##AssetInput"))
		filter.Clear();

	ImGui::BeginChild("##AssetSelector");

	for (int i = 0; i < Globals::Lists::Prefabs::list.size(); ++i) {
		if (filter.PassFilter(Globals::Lists::Prefabs::list[i].c_str())) {
			if (ImGui::Selectable(Globals::Lists::Prefabs::list[i].c_str(), Globals::Lists::Prefabs::selectedPrefab == i))
				Globals::Lists::Prefabs::selectedPrefab = i;
		}
	}

	ImGui::EndChild();

	ImGui::EndChild();

	ImGui::End();
}