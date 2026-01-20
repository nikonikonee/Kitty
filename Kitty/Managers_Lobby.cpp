#include "Managers_Lobby.h"
#include "RetSpoofer/RetSpoofer.hpp"



void Cheats::Managers::Lobby::LobbyCrash() {

}

void Cheats::Managers::Lobby::Run() {
	auto localPlayer = SDK::RR::Game::Player::get_LocalPlayer();
	auto& selectedPlayer = (SDK::RR::Game::Player*&)Globals::Vars::Runtime::Instance::targetSelectedPlayer;

	if (localPlayer) {
		auto localNetworkedPlayer = localPlayer->get_NetworkedPlayer();

		if (localNetworkedPlayer) {

			if (Globals::Vars::Lobby::deleteMap) {
				localNetworkedPlayer->SetMasterClient();
				Mods::DeleteMap();
				Globals::Vars::Lobby::deleteMap = false;
			}

			if (Globals::Vars::Lobby::killAll) {
				localNetworkedPlayer->SetMasterClient();
				Mods::KillAll();
				Globals::Vars::Lobby::killAll = false;
			}

			if (Globals::Vars::Lobby::restoreHealthAll) {
				localNetworkedPlayer->SetMasterClient();
				Mods::RestoreHealthAll();
				Globals::Vars::Lobby::restoreHealthAll = false;
			}

			if (Globals::Vars::Lobby::spawnAssetAll) {
				Mods::SpawnAssetAll();
				Globals::Vars::Lobby::spawnAssetAll = false;
			}

			if (Globals::Vars::Lobby::forceHoldAll) {
				Mods::ForceHoldAll();
				Globals::Vars::Lobby::forceHoldAll = false;
			}

			if (Globals::Vars::Lobby::bringAll) {
				localNetworkedPlayer->SetMasterClient();
				Mods::BringAll();
				Globals::Vars::Lobby::bringAll = false;
			}

			if (selectedPlayer && Globals::Vars::Lobby::bringAllToPlayer) {
				localNetworkedPlayer->SetMasterClient();
				Mods::BringAllToPlayer(selectedPlayer);
				selectedPlayer = nullptr;
				Globals::Vars::Lobby::bringAllToPlayer = false;
			}

			if (Globals::Vars::Lobby::voidAll) {
				Mods::VoidAll();
				Globals::Vars::Lobby::voidAll = false;
			}
		}
	}
}