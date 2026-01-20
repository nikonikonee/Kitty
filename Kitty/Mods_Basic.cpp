#include "Mods_Basic.h"

void Cheats::Managers::PlayerList::Mods::Basic::StealPv(SDK::RR::Game::Player* target) {
	auto localPlayer = SDK::RR::Game::Player::get_LocalPlayer();
	if (!target || !localPlayer)
		return;

	if (target->get_NetworkedView() && localPlayer->get_NetworkedPlayer())
		target->get_NetworkedView()->TransferOwnership(localPlayer->get_NetworkedPlayer());
}

void Cheats::Managers::PlayerList::Mods::Basic::RestorePv(SDK::RR::Game::Player* target) {
	if (!target)
		return;

	if (target->get_NetworkedView() && target->get_NetworkedPlayer()) {
		auto networkedView = target->get_NetworkedView();
		auto networkedPlayer = target->get_NetworkedPlayer();

		if (networkedView->get_Owner()) {
			auto owner = networkedView->get_Owner();

			if (owner != networkedPlayer) //Only restore pv if the owner isn't the player itself
				networkedView->TransferOwnership(networkedPlayer);
		}
	}
}

void Cheats::Managers::PlayerList::Mods::Basic::SpawnAsset(SDK::RR::Game::Player* target) {
	if (!target)
		return;

	if (target->get_Head() && target->get_Head()->get_transform()) {
		auto spawnPosition = target->get_Head()->get_transform()->get_position() + target->get_Head()->get_transform()->get_forward();
		auto prefabScale = Globals::Vars::Spawnables::customAssetScale ? Globals::Vars::Spawnables::Var::assetScale : SDK::Structs::Unity::Vector3(1, 1, 1);
	
		SDK::RR::GameServer::RRNetworking::Instantiate(Globals::Lists::Prefabs::list[Globals::Lists::Prefabs::selectedPrefab].c_str(), spawnPosition, { 0, 0, 0, 0 }, prefabScale, false);
	}
}