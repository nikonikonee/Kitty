#include "Headers_Spawnables.h"

void Render::GUI::Headers::Spawnables::Render() {
	if (ImGui::CollapsingHeader("Spawnables")) {
		if (ImGui::Checkbox("Foodsploit Toggle", &Globals::Vars::Spawnables::foodsploit))
			if (Globals::Vars::Spawnables::foodOverrideSpawn)
				Globals::Vars::Spawnables::foodOverrideSpawn = false; //Can't have both enabled!
		if (Globals::Vars::Spawnables::foodsploit) {
			ImGui::Spacing();
			ImGui::SameLine();
			ImGui::Checkbox("Foodsploit Config Window", &Globals::Vars::GUI::Windows::foodsploitWindow);
		}
		ImGui::Checkbox("Asset Spawn Config Window", &Globals::Vars::GUI::Windows::assetSpawnWindow);
	}
}