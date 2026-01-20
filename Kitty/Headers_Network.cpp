#include "Headers_Network.h"

void Render::GUI::Headers::Network::Render() {
	if (ImGui::CollapsingHeader("Network")) {
		ImGui::Checkbox("Player List Window", &Globals::Vars::GUI::Windows::playerListWindow);
		ImGui::Checkbox("Player Blacklist Window", &Globals::Vars::GUI::Windows::playerBlacklistWindow);
		ImGui::Checkbox("Player Selector (F1)", &Globals::Vars::Network::playerSelector);
		ImGui::Checkbox("Lobby Panel Window", &Globals::Vars::GUI::Windows::lobbyPanelWindow);
		ImGui::Separator();
		ImGui::Checkbox("Loop Grant Master", &Globals::Vars::Network::loopGrantMaster);
		ImGui::Checkbox("Player Vanish", &Globals::Vars::Network::playerVanish);
		ImGui::Checkbox("NS Killer (AntiKick/Toggle In Instance)", &Globals::Vars::Network::nsKiller);
	}
}