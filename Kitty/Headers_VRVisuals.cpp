#include "Headers_VRVisuals.h"

void Render::GUI::Headers::VRVisuals::Render() {
	if (ImGui::CollapsingHeader("VR Visuals (Exclusive)")) {
		if (ImGui::Checkbox("Simple Lines (Unstable) (Use At Crash Risk)", &Globals::Vars::VisualsVR::simpleLines)) {
			Globals::Vars::VisualsVR::lineStateChanged = true;
		}
		ImGui::SeparatorText("Color Config");
		if (ImGui::Checkbox("Rainbow Color ##simpleLineColor", &Globals::Vars::VisualsVR::rainbowColors)) {
			if (Globals::Vars::VisualsVR::customLineColor)
				Globals::Vars::VisualsVR::customLineColor = false;
		}
		if (ImGui::Checkbox("Custom Line Color ##simpleLines", &Globals::Vars::VisualsVR::customLineColor)) {
			if (Globals::Vars::VisualsVR::rainbowColors)
				Globals::Vars::VisualsVR::rainbowColors = false;
		}
		if (Globals::Vars::VisualsVR::customLineColor) {
			ImGui::SameLine();
			ImGui::ColorEdit4("##simpleLineColor", (float*)&Globals::Vars::VisualsVR::Var::lineColor, ImGuiColorEditFlags_NoInputs);
		}
	}
}