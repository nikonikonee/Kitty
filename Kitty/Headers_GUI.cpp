#include "Headers_GUI.h"

void Render::GUI::Headers::GUI::Render() {
	if (ImGui::CollapsingHeader("GUI Config")) {
		ImGui::Spacing();
		ImGui::Checkbox("Midnight Themes", &Globals::Vars::GUI::Themes::midnight);
		ImGui::SeparatorText("Watermark Config");
		ImGui::Checkbox("Watermark Toggle", &Globals::Vars::GUI::Watermark::renderWatermark);
		if (Globals::Vars::GUI::Watermark::renderWatermark) {
			ImGui::Spacing();
			ImGui::SameLine();
			ImGui::Checkbox("Render FPS", &Globals::Vars::GUI::Watermark::renderFPS);
		}
	}
}