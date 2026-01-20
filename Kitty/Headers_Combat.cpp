#include "Headers_Combat.h"

void Render::GUI::Headers::Combat::Render() {
	if (ImGui::CollapsingHeader("Combat")) {
		ImGui::Checkbox("Quest Invincibility", &Globals::Vars::Combat::questInvincibility);
		ImGui::Checkbox("PVP God Mode", &Globals::Vars::Combat::pvpGodMode);
		ImGui::Checkbox("Basic Rapid Fire", &Globals::Vars::Combat::basicRapidFire);
		ImGui::Checkbox("Infinite Ammo", &Globals::Vars::Combat::infiniteAmmo);
		ImGui::Checkbox("No Recoil", &Globals::Vars::Combat::noRecoil);
		ImGui::Checkbox("No Spread", &Globals::Vars::Combat::noSpread);

		ImGui::Separator();
		ImGui::Checkbox("Bullet Speed Modifier", &Globals::Vars::Combat::bulletSpeedModifier);
		if (Globals::Vars::Combat::bulletSpeedModifier) {
			ImGui::Spacing();
			ImGui::SameLine();
			ImGui::InputFloat("Speed ##bullet", &Globals::Vars::Combat::Var::bulletSpeed);
		}
		ImGui::Checkbox("Loop Fire", &Globals::Vars::Combat::loopFire);
		if (Globals::Vars::Combat::loopFire) {
			ImGui::Spacing();
			ImGui::SameLine();
			ImGui::Checkbox("Use Binding", &Globals::Vars::Combat::useBinding);
		}
		ImGui::Checkbox("Bullet Multiplier", &Globals::Vars::Combat::bulletMultiplier);
		if (Globals::Vars::Combat::bulletMultiplier) {
			ImGui::Spacing();
			ImGui::SameLine();
			ImGui::InputInt("Amount ##bullet", &Globals::Vars::Combat::Var::bulletAmount);
		}
	}
}