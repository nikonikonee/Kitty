#include "Mods_Lobby.h"


void Cheats::Managers::Lobby::Mods::DeleteMap() {
	auto gameObjects = SDK::RR::Base::Object::FindObjectsOfType<SDK::RR::Unity::GameObject*>(SDK::RR::System::Type::GetType("UnityEngine.GameObject, UnityEngine.CoreModule"));
	if (!gameObjects)
		return;

	for (int i = 0; i < gameObjects->getLength(); ++i) {
		auto gameObject = gameObjects->getPointer()[i];
		
		if (gameObject) {
			auto creationObject = gameObject->GetComponent<SDK::RR::Game::CreationObject*>(SDK::RR::System::Type::GetType("RecRoom.Core.Creation.CreationObject, Assembly-CSharp"));
			if (creationObject) {
				auto creationObjectPv = creationObject->get_NetworkedView();
				if (creationObjectPv) {
					creationObjectPv->RPC("RpcMasterDespawn", 0, nullptr);
				}
			}
		}

	}
}


void Cheats::Managers::Lobby::Mods::KillAll() {
	if (!Globals::Vars::Runtime::Instance::GameCombatManager)
		return;

	auto instance = (SDK::RR::Game::GameCombatManager*)Globals::Vars::Runtime::Instance::GameCombatManager;

	for (auto& plr : players) {
		if (plr.instance && plr.networkedPlayer)
			instance->MasterKillPlayer(plr.networkedPlayer);
	}
}

void Cheats::Managers::Lobby::Mods::RestoreHealthAll() {
	if (!Globals::Vars::Runtime::Instance::GameCombatManager)
		return;

	auto instance = (SDK::RR::Game::GameCombatManager*)Globals::Vars::Runtime::Instance::GameCombatManager;

	for (auto& plr : players) {
		if (plr.instance && plr.networkedPlayer)
			instance->MasterSetPlayerHealth(plr.networkedPlayer, 100);
	}
}


void Cheats::Managers::Lobby::Mods::SpawnAssetAll() {
	for (auto& plr : players) {
		if (plr.instance && plr.headTransform) {
			auto prefabScale = Globals::Vars::Spawnables::customAssetScale ? Globals::Vars::Spawnables::Var::assetScale : SDK::Structs::Unity::Vector3(1, 1, 1);
			auto spawnPosition = plr.headTransform->get_position() + plr.headTransform->get_forward();

			SDK::RR::GameServer::RRNetworking::Instantiate(Globals::Lists::Prefabs::list[Globals::Lists::Prefabs::selectedPrefab].c_str(), spawnPosition, { 0, 0, 0, 0 }, prefabScale, false);
		}
	}
}

void Cheats::Managers::Lobby::Mods::ForceHoldAll() {
	for (auto& plr : players) {
		if (plr.instance && plr.rightHand) {
			auto prefabScale = Globals::Vars::Spawnables::customAssetScale ? Globals::Vars::Spawnables::Var::assetScale : SDK::Structs::Unity::Vector3(1, 1, 1);
			auto prefab = SDK::RR::GameServer::RRNetworking::Instantiate(Globals::Lists::Prefabs::list[Globals::Lists::Prefabs::selectedPrefab].c_str(), { 0, -100, 0 }, { 0, 0, 0, 0 }, prefabScale, false);

			if (prefab) {
				auto tool = prefab->GetComponent<SDK::RR::Game::Tool*>(SDK::RR::System::Type::GetType("Tool, Assembly-CSharp"));
				if (tool) {
					plr.rightHand->TryPickupTool(tool);
				}
			}
		}
	}
}

void Cheats::Managers::Lobby::Mods::BringAll() {
	auto localPlayer = SDK::RR::Game::Player::get_LocalPlayer();
	if (!localPlayer)
		return;

	for (auto& plr : players) {
		if (plr.instance && plr.instance != localPlayer && localPlayer->get_Head() && plr.networkView) {
			auto head = localPlayer->get_Head();

			auto tpPosition = head->get_transform()->get_position() + head->get_transform()->get_forward();

			auto parameters = SDK::Pointers::Exports::Exports.il2cpp_array_new(Globals::Vars::Runtime::Native::Object, 1);
			parameters->vector[0] = SDK::Pointers::Exports::Exports.il2cpp_value_box(Globals::Vars::Runtime::Native::Vector3, &tpPosition);

			plr.networkView->RPC("RpcAuthorityCV2SetPosition", 0, parameters);
		}
	}
}

void Cheats::Managers::Lobby::Mods::BringAllToPlayer(SDK::RR::Game::Player* target) {
	if (!target)
		return;

	for (auto& plr : players) {
		if (plr.instance && plr.instance != target && target->get_Head() && plr.networkView) {
			auto head = target->get_Head();

			auto tpPosition = head->get_transform()->get_position() + head->get_transform()->get_forward();

			auto parameters = SDK::Pointers::Exports::Exports.il2cpp_array_new(Globals::Vars::Runtime::Native::Object, 1);
			parameters->vector[0] = SDK::Pointers::Exports::Exports.il2cpp_value_box(Globals::Vars::Runtime::Native::Vector3, &tpPosition);

			plr.networkView->RPC("RpcAuthorityCV2SetPosition", 0, parameters);
		}
	}
}


void Cheats::Managers::Lobby::Mods::VoidAll() {
	auto localPlayer = SDK::RR::Game::Player::get_LocalPlayer();
	if (!localPlayer)
		return;

	for (auto& plr : players) {
		if (plr.instance && plr.instance != localPlayer && plr.networkView) {

			auto tpPosition = Globals::Vars::PlayerList::infinityToggle ? SDK::Structs::Unity::Vector3(-99999997781963083612160.000, -99999997781963083612160.000, -99999997781963083612160.000) : SDK::Structs::Unity::Vector3(0, -100000, 0);

			auto parameters = SDK::Pointers::Exports::Exports.il2cpp_array_new(Globals::Vars::Runtime::Native::Object, 1);
			parameters->vector[0] = SDK::Pointers::Exports::Exports.il2cpp_value_box(Globals::Vars::Runtime::Native::Vector3, &tpPosition);

			plr.networkView->RPC("RpcAuthorityCV2SetPosition", 0, parameters);
		}
	}
}