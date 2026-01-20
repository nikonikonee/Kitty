#include "Headers_Aimbot.h"

void Render::GUI::Headers::Aimbot::Render() {
	if (ImGui::CollapsingHeader("Aimbot")) {
		ImGui::Spacing();
		ImGui::Checkbox("Enable Aimbot", &Globals::Vars::Aimbot::enableAimbot);
		if (Globals::Vars::Aimbot::enableAimbot) {
			ImGui::Spacing();
			ImGui::SameLine();
			ImGui::Checkbox("Override Aim Strength", &Globals::Vars::Aimbot::overrideAimStrength);
			if (Globals::Vars::Aimbot::overrideAimStrength) {
				ImGui::Spacing();
				ImGui::SameLine();
				ImGui::Spacing();
				ImGui::SameLine();
				ImGui::SliderFloat("Strength ##aim", &Globals::Vars::Aimbot::Var::aimStrength, 0.0f, 100.0f);
			}
		}
		ImGui::Separator();
		ImGui::Checkbox("Enable Silent Aimbot", &Globals::Vars::Aimbot::enableSilentAimbot);
		if (Globals::Vars::Aimbot::enableSilentAimbot) {
			ImGui::Spacing();
			ImGui::SameLine();
			if (ImGui::Checkbox("Use FOV Circle (Screen)", &Globals::Vars::Aimbot::useFovCircle))
				if (Globals::Vars::Aimbot::overrideSilentAimStrictness)
					Globals::Vars::Aimbot::overrideSilentAimStrictness = false;
			ImGui::Spacing();
			ImGui::SameLine();
			if (ImGui::Checkbox("Override Silent Aim Strictness", &Globals::Vars::Aimbot::overrideSilentAimStrictness))
				if (Globals::Vars::Aimbot::useFovCircle)
					Globals::Vars::Aimbot::useFovCircle = false;

			if (Globals::Vars::Aimbot::overrideSilentAimStrictness) {
				ImGui::Spacing();
				ImGui::SameLine();
				ImGui::Spacing();
				ImGui::SameLine();
				ImGui::SliderFloat("Strictness ##silentAim", &Globals::Vars::Aimbot::Var::silentAimRangeStrictness, 0.0f, 1.0f);
			}
		}
		ImGui::SeparatorText("Aim Config");
		ImGui::Checkbox("Render FOV Circle", &Globals::Vars::Aimbot::renderFovCircle);
		ImGui::SliderFloat("FOV Size ##fovCircle", &Globals::Vars::Aimbot::Var::circleSize, 0.0f, 250.0f);
		if (ImGui::Checkbox("Head Lock", &Globals::Vars::Aimbot::headLock))
			if (Globals::Vars::Aimbot::bodyLock)
				Globals::Vars::Aimbot::bodyLock = false;
		if (ImGui::Checkbox("Body Lock", &Globals::Vars::Aimbot::bodyLock))
			if (Globals::Vars::Aimbot::headLock)
				Globals::Vars::Aimbot::headLock = false;
		ImGui::Separator();
		ImGui::Checkbox("Team Check", &Globals::Vars::Aimbot::teamCheck);
		ImGui::Checkbox("Health Check", &Globals::Vars::Aimbot::healthCheck);
		ImGui::SeparatorText("Hitbox Extender");
		if (ImGui::Button("Update Hitboxes")) {
			for (auto plr : players) {
				if (plr.instance && plr.instance != SDK::RR::Game::Player::get_LocalPlayer())
					plr.instance->SetHeadScale(Globals::Vars::Aimbot::Var::hitboxSize);
			}
		}
		ImGui::SameLine();
		ImGui::PushItemWidth(95.0f);
		ImGui::InputFloat("Size ##hitboxes", &Globals::Vars::Aimbot::Var::hitboxSize);
		ImGui::PopItemWidth();

		ImGui::SeparatorText("HvH");
		ImGui::Checkbox("BHOP (WIP)", &Globals::Vars::Aimbot::bhop);
		ImGui::Checkbox("Spinbot (WIP)", &Globals::Vars::Aimbot::spinbot);
	}
}