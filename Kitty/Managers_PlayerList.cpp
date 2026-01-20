#include "Managers_PlayerList.h"

void Cheats::Managers::PlayerList::Run() {
	auto localPlayer = SDK::RR::Game::Player::get_LocalPlayer();

	if (Globals::Vars::Runtime::Instance::target && localPlayer) {

		auto localNetworkedPlayer = localPlayer->get_NetworkedPlayer();

		auto target = (SDK::RR::Game::Player*)Globals::Vars::Runtime::Instance::target;
		auto& selectedPlayer = (SDK::RR::Game::Player*&)Globals::Vars::Runtime::Instance::targetSelectedPlayer;

		if (localNetworkedPlayer) {

			if (Globals::Vars::PlayerList::loopFire)
				Mods::Game::LoopFire(target);

			if (Globals::Vars::Runtime::Instance::GameCombatManager) {
				auto instance = (SDK::RR::Game::GameCombatManager*)Globals::Vars::Runtime::Instance::GameCombatManager;

				if (Globals::Vars::PlayerList::kill) {
					localNetworkedPlayer->SetMasterClient();
					Mods::Game::Kill(instance, target);
					Globals::Vars::PlayerList::kill = false;
				}

				if (Globals::Vars::PlayerList::restoreHealth) {
					localNetworkedPlayer->SetMasterClient();
					Mods::Game::RestoreHealth(instance, target, 100);
					Globals::Vars::PlayerList::restoreHealth = false;
				}

				if (Globals::Vars::PlayerList::invincibility) {
					localNetworkedPlayer->SetMasterClient();
					Mods::Game::Invincibility(instance, target, Globals::Vars::PlayerList::Var::invincibilityDuration);
					Globals::Vars::PlayerList::invincibility = false;
				}
			}

			if (Globals::Vars::PlayerList::stealPv) {
				Mods::Basic::StealPv(target);
				Globals::Vars::PlayerList::stealPv = false;
			}

			if (Globals::Vars::PlayerList::restorePv) {
				Mods::Basic::RestorePv(target);
				Globals::Vars::PlayerList::restorePv = false;
			}

			if (Globals::Vars::PlayerList::spawnAsset) {
				Mods::Basic::SpawnAsset(target);
				Globals::Vars::PlayerList::spawnAsset = false;
			}

			if (Globals::Vars::PlayerList::ramCrash) {
				Mods::RPC::RamCrash(target);
				Globals::Vars::PlayerList::ramCrash = false;
			}

			if (Globals::Vars::PlayerList::bulletRamCrash) {
				Mods::RPC::BulletRamCrash(target);
				Globals::Vars::PlayerList::bulletRamCrash = false;
			}

			if (Globals::Vars::PlayerList::spawnRamCrash) {
				Mods::RPC::SpawnRamCrash(target);
				Globals::Vars::PlayerList::spawnRamCrash = false;
			}

			if (Globals::Vars::PlayerList::broadcastFakeVotekick) {
				Mods::RPC::BroadcastVoteKick(target);
				Globals::Vars::PlayerList::broadcastFakeVotekick = false;
			}

			if (Globals::Vars::PlayerList::bring) {
				localNetworkedPlayer->SetMasterClient();
				Mods::RPC::Bring(target);
				Globals::Vars::PlayerList::bring = false;
			}

			if (selectedPlayer && Globals::Vars::PlayerList::bringToPlayer) {
				localNetworkedPlayer->SetMasterClient();
				Mods::RPC::BringToPlayer(target, selectedPlayer);
				selectedPlayer = nullptr;
				Globals::Vars::PlayerList::bringToPlayer = false;
			}

			if (Globals::Vars::PlayerList::bringAllToPlayer) {
				localNetworkedPlayer->SetMasterClient();
				Mods::RPC::BringAllToPlayer(target);
				Globals::Vars::PlayerList::bringAllToPlayer = false;
			}

			if (Globals::Vars::PlayerList::voidPlayer) {
				localNetworkedPlayer->SetMasterClient();
				Mods::RPC::Void(target);
				Globals::Vars::PlayerList::voidPlayer = false;
			}

			if (Globals::Vars::PlayerList::spawn) {
				Mods::RPC::Spawn(target);
				Globals::Vars::PlayerList::spawn = false;
			}

			if (Globals::Vars::PlayerList::despawn) {
				Mods::RPC::Despawn(target);
				Globals::Vars::PlayerList::despawn = false;
			}

			//Loop :3

			if (Globals::Vars::PlayerList::spin)
				Mods::RPC::Spin(target);
		}

	}
}