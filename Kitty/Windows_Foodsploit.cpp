#include "Windows_Foodsploit.h"

void Render::GUI::Windows::Foodsploit::Render() {
	ImGui::Begin("Foodsploit Config Window");

	ImGui::BeginChild("##FoodConfig", ImVec2(ImGui::GetContentRegionAvail().x * 0.5f, 0), false);

	ImGui::Checkbox("New Food Bypass Toggle", &Globals::Vars::Spawnables::newFoodBypassToggle);
	ImGui::Separator();
	ImGui::Checkbox("Custom Position ##Food", &Globals::Vars::Spawnables::customFoodPosition);
	if (Globals::Vars::Spawnables::customFoodPosition) {
		ImGui::Spacing();
		ImGui::SameLine();
		ImGui::PushItemWidth(80.0f);

		ImGui::InputFloat("##xFoodPosition", &Globals::Vars::Spawnables::Var::foodPosition.X);
		ImGui::SameLine();
		ImGui::InputFloat("##yFoodPosition", &Globals::Vars::Spawnables::Var::foodPosition.Y);
		ImGui::SameLine();
		ImGui::InputFloat("##zFoodPosition", &Globals::Vars::Spawnables::Var::foodPosition.Z);

		ImGui::PopItemWidth();
	}
	ImGui::Checkbox("Custom Rotation ##Food", &Globals::Vars::Spawnables::customFoodRotation);
	if (Globals::Vars::Spawnables::customFoodRotation) {
		ImGui::Spacing();
		ImGui::SameLine();
		ImGui::PushItemWidth(80.0f);

		ImGui::InputFloat("##xFoodRotation", &Globals::Vars::Spawnables::Var::foodRotation.X);
		ImGui::SameLine();
		ImGui::InputFloat("##yFoodRotation", &Globals::Vars::Spawnables::Var::foodRotation.Y);
		ImGui::SameLine();
		ImGui::InputFloat("##zFoodRotation", &Globals::Vars::Spawnables::Var::foodRotation.Z);
		ImGui::SameLine();
		ImGui::InputFloat("##wFoodRotation", &Globals::Vars::Spawnables::Var::foodRotation.W);

		ImGui::PopItemWidth();
	}
	ImGui::Separator();
	ImGui::Checkbox("Custom Amount ##Food", &Globals::Vars::Spawnables::customFoodAmount);
	if (Globals::Vars::Spawnables::customFoodAmount) {
		ImGui::SameLine();
		ImGui::Spacing();
		ImGui::InputInt("##foodAmount", &Globals::Vars::Spawnables::Var::foodAmount);
	}
	ImGui::Checkbox("Custom Scale ##Food", &Globals::Vars::Spawnables::customFoodScale);
	if (Globals::Vars::Spawnables::customFoodScale) {
		ImGui::SameLine();
		ImGui::Spacing();
		ImGui::InputFloat("##foodScale", &Globals::Vars::Spawnables::Var::foodScale);
	}
	ImGui::Checkbox("Custom Food", &Globals::Vars::Spawnables::customFoodGuid);

	ImGui::EndChild();

	ImGui::SameLine();
	ImGui::SeparatorEx(ImGuiSeparatorFlags_Vertical, 3.0f);
	ImGui::SameLine();

	ImGui::BeginChild("##FoodSelector", ImVec2(0, 0), false);

	static ImGuiTextFilter filter;
	filter.Draw("##FoodInput");
	ImGui::SameLine();
	if (ImGui::Button("Clear ##FoodInput"))
		filter.Clear();

	ImGui::BeginChild("##FoodSelector");

	for (int i = 0; i < Globals::Vars::Runtime::List::foods.size(); ++i) {
		if (filter.PassFilter(Globals::Vars::Runtime::List::foods[i].first.c_str())) {
			if (ImGui::Selectable(Globals::Vars::Runtime::List::foods[i].first.c_str(), Globals::Vars::Runtime::List::Selected::food == i))
				Globals::Vars::Runtime::List::Selected::food = i;
		}
	}

	ImGui::EndChild();

	ImGui::EndChild();

	ImGui::End();
}