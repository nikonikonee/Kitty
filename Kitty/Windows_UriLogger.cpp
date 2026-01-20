#include "Windows_UriLogger.h"

void Render::GUI::Windows::UriLogger::Render() {
	ImGui::SetNextWindowBgAlpha(0.7f);
	ImGui::Begin("URI Logger (Kitty Exclusive)");

	static ImGuiTextFilter filter;

	filter.Draw("##UriLink");
	ImGui::SameLine();
	if (ImGui::Button("Clear ##UriLogs"))
		filter.Clear();
	if (ImGui::Button("Clear Logs ##UriLogs"))
		Globals::Vars::Loggers::uriLogs.clear();

	ImGui::Separator();

	ImGui::SetNextWindowBgAlpha(0.7f);
	ImGui::BeginChild("##UriLogs");
	for (int i = 0; i < Globals::Vars::Loggers::uriLogs.size(); ++i) {
		auto uriLog = Globals::Vars::Loggers::uriLogs[i];
		if (!filter.PassFilter(uriLog.c_str()))
			continue;
		ImGui::Text("%s", uriLog.c_str());
		ImGui::SetScrollHereY(1.0f);
	}
	ImGui::EndChild();

	ImGui::End();
}