#include "Windows.h"


void Render::GUI::Windows::Render() {
	if (Base::Opened) {
		if (Globals::Vars::Spawnables::foodsploit && Globals::Vars::GUI::Windows::foodsploitWindow)
			Foodsploit::Render();
		if (Globals::Vars::GUI::Windows::assetSpawnWindow)
			Assets::Render();
		if (Globals::Vars::GUI::Windows::playerListWindow)
			PlayerList::Render();
		if (Globals::Vars::GUI::Windows::playerBlacklistWindow)
			Blacklist::Render();
		if (Globals::Vars::GUI::Windows::lobbyPanelWindow)
			Lobby::Render();
	}

	if (Globals::Vars::API::uriLogger)
		UriLogger::Render();

}