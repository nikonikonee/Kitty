#include "Windows_Blacklist.h"

void Render::GUI::Windows::Blacklist::Render() {
	static char playerNameBuffer[256];

	ImGui::Begin("Player Blacklist Window");
	ImGui::Checkbox("Auto Ram Crash Blacklisted", &Globals::Vars::PlayerBlacklisted::autoRamCrashBlacklisted);
	if (Globals::Vars::PlayerBlacklisted::autoRamCrashBlacklisted) {
		ImGui::Indent();
		if (ImGui::Checkbox("Cheer Crash", &Globals::Vars::PlayerBlacklisted::cheerCrash))
			if (Globals::Vars::PlayerBlacklisted::bulletCrash)
				Globals::Vars::PlayerBlacklisted::bulletCrash = false;

		if (ImGui::Checkbox("Bullet Crash", &Globals::Vars::PlayerBlacklisted::bulletCrash))
			if (Globals::Vars::PlayerBlacklisted::cheerCrash)
				Globals::Vars::PlayerBlacklisted::cheerCrash = false;

		ImGui::Unindent();
	}
	ImGui::SeparatorText("Configure Runtime List");

	if (ImGui::Button("Add Name")) {
		if (strlen(playerNameBuffer) > 0)
			blacklistedNames.push_back(std::string(playerNameBuffer));
	}

	ImGui::SameLine();

	ImGui::InputTextWithHint("##inputtedPlayerName", "Input Name Here", playerNameBuffer, sizeof(playerNameBuffer));

	ImGui::Separator();

	for (int i = 0; i < blacklistedNames.size(); ++i) {
		auto blacklistedName = blacklistedNames[i];

		ImGui::Text("%s", blacklistedName.c_str());
		ImGui::SameLine();

		std::string tag = "Remove ##" + std::to_string(i);

		if (ImGui::Button(tag.c_str())) {
			blacklistedNames.erase(blacklistedNames.begin() + i);
		}
	}

	ImGui::End();
}