#include "Headers_Visuals.h"

void Render::GUI::Headers::Visuals::Render() {
	if (ImGui::CollapsingHeader("Visuals")) {
		ImGui::Checkbox("Enable ESP", &Globals::Vars::Visuals::enableEsp);
		if (Globals::Vars::Visuals::enableEsp) {
			ImGui::Spacing();
			ImGui::SameLine();
			ImGui::Checkbox("Lines", &Globals::Vars::Visuals::lines);
			if (Globals::Vars::Visuals::lines) {
				ImGui::Spacing();
				ImGui::SameLine();
				ImGui::Spacing();
				ImGui::SameLine();
				ImGui::Checkbox("Use Body", &Globals::Vars::Visuals::useBody);

				ImGui::Spacing();
				ImGui::SameLine();
				ImGui::Spacing();
				ImGui::SameLine();
				ImGui::Checkbox("Top Screen", &Globals::Vars::Visuals::topScreen);
			}
			ImGui::Spacing();
			ImGui::SameLine();
			ImGui::Checkbox("Names", &Globals::Vars::Visuals::names);
			ImGui::Spacing();
			ImGui::SameLine();
			ImGui::Checkbox("Skeletons", &Globals::Vars::Visuals::skeletons);
			ImGui::Spacing();
			ImGui::SameLine();
			ImGui::Checkbox("Boxes", &Globals::Vars::Visuals::boxes);
			if (Globals::Vars::Visuals::boxes) {
				ImGui::Spacing();
				ImGui::SameLine();
				ImGui::Spacing();
				ImGui::SameLine();
				if (ImGui::Checkbox("Outline ##boxes", &Globals::Vars::Visuals::outlines)) {
					if (Globals::Vars::Visuals::cornerBoxes)
						Globals::Vars::Visuals::cornerBoxes = false;
					if (Globals::Vars::Visuals::filledBoxes)
						Globals::Vars::Visuals::filledBoxes = false;
				}
				if (Globals::Vars::Visuals::outlines) {
					ImGui::Spacing();
					ImGui::SameLine();
					ImGui::Spacing();
					ImGui::SameLine();
					ImGui::Spacing();
					ImGui::SameLine();
					ImGui::SliderFloat("Thickness ##outlines", &Globals::Vars::Visuals::Var::outlineThickness, 1.0f, 1.5f);
				}
				ImGui::Spacing();
				ImGui::SameLine();
				ImGui::Spacing();
				ImGui::SameLine();
				if (ImGui::Checkbox("Filled ##boxes", &Globals::Vars::Visuals::filledBoxes)) {
					if (Globals::Vars::Visuals::outlines)
						Globals::Vars::Visuals::outlines = false;
					if (Globals::Vars::Visuals::cornerBoxes)
						Globals::Vars::Visuals::cornerBoxes = false;
				}
				ImGui::Spacing();
				ImGui::SameLine();
				ImGui::Spacing();
				ImGui::SameLine();
				if (ImGui::Checkbox("Cornered ##boxes", &Globals::Vars::Visuals::cornerBoxes)) {
					if (Globals::Vars::Visuals::outlines)
						Globals::Vars::Visuals::outlines = false;
					if (Globals::Vars::Visuals::filledBoxes)
						Globals::Vars::Visuals::filledBoxes = false;
				}
			}
			ImGui::Separator();
			ImGui::Checkbox("Health Check ##esp", &Globals::Vars::Visuals::healthCheck);
			ImGui::Checkbox("Team Check ##esp", &Globals::Vars::Visuals::teamCheck);
			if (Globals::Vars::Visuals::teamCheck) {
				ImGui::Spacing();
				ImGui::SameLine();
				ImGui::Checkbox("Render Teammates", &Globals::Vars::Visuals::renderTeammates);
			}

			ImGui::SeparatorText("Color Config");

			if (ImGui::Checkbox("Rainbow Color", &Globals::Vars::Visuals::rainbowColors)) {
				if (Globals::Vars::Visuals::customLineColor)
					Globals::Vars::Visuals::customLineColor = false;

				if (Globals::Vars::Visuals::customNameColor)
					Globals::Vars::Visuals::customNameColor = false;

				if (Globals::Vars::Visuals::customSkeletonColor)
					Globals::Vars::Visuals::customSkeletonColor = false;

				if (Globals::Vars::Visuals::customBoxColor)
					Globals::Vars::Visuals::customBoxColor = false;
			}

			if (ImGui::Checkbox("Custom Line Color", &Globals::Vars::Visuals::customLineColor)) {
				if (Globals::Vars::Visuals::rainbowColors)
					Globals::Vars::Visuals::rainbowColors = false;
			}

			if (Globals::Vars::Visuals::customLineColor) {
				ImGui::SameLine();
				ImGui::ColorEdit4("##lineColor", (float*)&Globals::Vars::Visuals::Var::lineColor, ImGuiColorEditFlags_NoInputs);
			}

			if (ImGui::Checkbox("Custom Name Color", &Globals::Vars::Visuals::customNameColor)) {
				if (Globals::Vars::Visuals::rainbowColors)
					Globals::Vars::Visuals::rainbowColors = false;
			}

			if (Globals::Vars::Visuals::customNameColor) {
				ImGui::SameLine();
				ImGui::ColorEdit4("##nameColor", (float*)&Globals::Vars::Visuals::Var::nameColor, ImGuiColorEditFlags_NoInputs);
			}

			if (ImGui::Checkbox("Custom Skeleton Color", &Globals::Vars::Visuals::customSkeletonColor)) {
				if (Globals::Vars::Visuals::rainbowColors)
					Globals::Vars::Visuals::rainbowColors = false;
			}

			if (Globals::Vars::Visuals::customSkeletonColor) {
				ImGui::SameLine();
				ImGui::ColorEdit4("##skeletonColor", (float*)&Globals::Vars::Visuals::Var::skeletonColor, ImGuiColorEditFlags_NoInputs);
			}

			if (ImGui::Checkbox("Custom Box Color", &Globals::Vars::Visuals::customBoxColor)) {
				if (Globals::Vars::Visuals::rainbowColors)
					Globals::Vars::Visuals::rainbowColors = false;
			}

			if (Globals::Vars::Visuals::customBoxColor) {
				ImGui::SameLine();
				ImGui::ColorEdit4("##boxColor", (float*)&Globals::Vars::Visuals::Var::boxColor, ImGuiColorEditFlags_NoInputs);
			}
		}
	}
}