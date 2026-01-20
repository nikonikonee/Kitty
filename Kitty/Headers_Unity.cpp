#include "Headers_Unity.h"

void Render::GUI::Headers::Unity::Render() {
	if (ImGui::CollapsingHeader("Unity")) {
		ImGui::Checkbox("FOV Slider", &Globals::Vars::Unity::fovSlider);
		if (Globals::Vars::Unity::fovSlider) {
			ImGui::Spacing();
			ImGui::SameLine();
			ImGui::SliderFloat("FOV Amount", &Globals::Vars::Unity::Var::fovAmount, 68.0f, 125.0f);
		}

		ImGui::Separator();

		if (ImGui::Checkbox("Timescale Slider", &Globals::Vars::Unity::timescaleSlider)) {
			if (!Globals::Vars::Unity::timescaleSlider)
				SDK::RR::Unity::Time::set_timeScale(1.0f);
			else
				SDK::RR::Unity::Time::set_timeScale(Globals::Vars::Unity::Var::timescaleAmount);
		}
		if (Globals::Vars::Unity::timescaleSlider) {
			ImGui::Spacing();
			ImGui::SameLine();
			if (ImGui::SliderFloat("Timescale Amount", &Globals::Vars::Unity::Var::timescaleAmount, 1.0f, 5.0f))
				SDK::RR::Unity::Time::set_timeScale(Globals::Vars::Unity::Var::timescaleAmount);
		}
	}
}