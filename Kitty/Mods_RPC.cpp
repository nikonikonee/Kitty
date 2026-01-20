#include "Mods_RPC.h"

void Cheats::Managers::PlayerList::Mods::RPC::RamCrash(SDK::RR::Game::Player* target) {
	if (!target)
		return;

	if (target->get_NetworkedPlayer() && target->get_PlayerProgression()) {
		auto playerProgression = target->get_PlayerProgression();

		if (playerProgression->get_NetworkedView()) {
			int cheer = 1;

			auto parameters = SDK::Pointers::Exports::Exports.il2cpp_array_new(Globals::Vars::Runtime::Native::Object, 1);
			parameters->vector[0] = SDK::Pointers::Exports::Exports.il2cpp_value_box(Globals::Vars::Runtime::Native::Int32, &cheer);

			for (int i = 0; i < 32000; ++i) {
				playerProgression->get_NetworkedView()->RPC("RpcPlayLevelUpFeedback", target->get_NetworkedPlayer(), parameters);
			}
		}
	}
}

void Cheats::Managers::PlayerList::Mods::RPC::BulletRamCrash(SDK::RR::Game::Player* target) {
	if (!target)
		return;

	if (target->get_Body() && target->get_Body()->get_transform() && target->get_NetworkedPlayer()) {
		auto bodyTransform = target->get_Body()->get_transform();

		auto spawnPosition = bodyTransform->get_position() - SDK::Structs::Unity::Vector3(0, -5000, 0);

		auto weapon = SDK::RR::GameServer::RRNetworking::Instantiate("[Quest_Dracula1_BlunderBuss]", spawnPosition, { 0, 0, 0, 0 }, { 0.1, 0.1, 0.1 }, true);

		auto rangedWeapon = weapon->GetComponent<SDK::RR::Game::RangedWeapon*>(SDK::RR::System::Type::GetType("RecRoom.Core.Combat.RangedWeapon, Assembly-CSharp"));

		if (rangedWeapon->get_NetworkedView()) {
			auto position = spawnPosition;
			auto rotation = SDK::Structs::Unity::Quaternion(0, 0, 0, 0);
			auto velocity = SDK::Structs::Unity::Vector3(0, 0, 0);
			auto chargeAmount = 100.0f;
			auto misFire = false;
			auto shotId = 69;

			auto parameters = SDK::Pointers::Exports::Exports.il2cpp_array_new(Globals::Vars::Runtime::Native::Object, 6);
			parameters->vector[0] = SDK::Pointers::Exports::Exports.il2cpp_value_box(Globals::Vars::Runtime::Native::Vector3, &position);
			parameters->vector[1] = SDK::Pointers::Exports::Exports.il2cpp_value_box(Globals::Vars::Runtime::Native::Quaternion, &rotation);
			parameters->vector[2] = SDK::Pointers::Exports::Exports.il2cpp_value_box(Globals::Vars::Runtime::Native::Vector3, &velocity);
			parameters->vector[3] = SDK::Pointers::Exports::Exports.il2cpp_value_box(Globals::Vars::Runtime::Native::Single, &chargeAmount);
			parameters->vector[4] = SDK::Pointers::Exports::Exports.il2cpp_value_box(Globals::Vars::Runtime::Native::Boolean, &misFire);
			parameters->vector[5] = SDK::Pointers::Exports::Exports.il2cpp_value_box(Globals::Vars::Runtime::Native::Byte, &shotId);

			for (int i = 0; i < 10000; ++i)
				rangedWeapon->get_NetworkedView()->RPC("RpcFireShot", target->get_NetworkedPlayer(), parameters);
		}
	}
}

void Cheats::Managers::PlayerList::Mods::RPC::SpawnRamCrash(SDK::RR::Game::Player* target) {
	if (!target)
		return;

	//	private void RpcForceDiscontinuitySync(UnityEngine::Vector3 DDIHIBMHCDH, UnityEngine::Quaternion JCDLBIBEGAF, UnityEngine::Vector3 DILGPPEHCGK, int32_t NPOKFOAFECB) { }

	SDK::Structs::Unity::Vector3 position = { 0, 0, 0 };
	SDK::Structs::Unity::Quaternion rotation = { 0, 0, 0, 0 };
	SDK::Structs::Unity::Vector3 scale = { 3, 0, 0 };
	int wtv = 0;

	auto parameters = SDK::Pointers::Exports::Exports.il2cpp_array_new(Globals::Vars::Runtime::Native::Object, 1);
	parameters->vector[0] = SDK::Pointers::Exports::Exports.il2cpp_value_box(Globals::Vars::Runtime::Native::Vector3, &position);

	printf("test rpc\n");

	target->get_NetworkedView()->RPC("RpcPlayStrikeSound", 0, nullptr);
}

void Cheats::Managers::PlayerList::Mods::RPC::BroadcastVoteKick(SDK::RR::Game::Player* target) {
	if (!target)
		return;

	auto playerModeration = target->get_PlayerModeration();
	if (!playerModeration)
		return;

	auto moderationView = playerModeration->get_NetworkedView();
	if (!moderationView)
		return;

	moderationView->RPC("RpcRoomModKickMessage", 0, nullptr);
}

void Cheats::Managers::PlayerList::Mods::RPC::Bring(SDK::RR::Game::Player* target) {
	if (!target)
		return;

	auto localPlayer = SDK::RR::Game::Player::get_LocalPlayer();
	if (!localPlayer)
		return;

	if (localPlayer->get_Head() && target->get_NetworkedView()) {
		auto head = localPlayer->get_Head();
		auto networkView = target->get_NetworkedView();
	
		if (head->get_transform()) {
			auto tpPosition = head->get_transform()->get_position() + head->get_transform()->get_forward();

			auto parameters = SDK::Pointers::Exports::Exports.il2cpp_array_new(Globals::Vars::Runtime::Native::Object, 1);
			parameters->vector[0] = SDK::Pointers::Exports::Exports.il2cpp_value_box(Globals::Vars::Runtime::Native::Vector3, &tpPosition);

			networkView->RPC("RpcAuthorityCV2SetPosition", 0, parameters);
		}
	}
}

void Cheats::Managers::PlayerList::Mods::RPC::BringToPlayer(SDK::RR::Game::Player* playerToBring, SDK::RR::Game::Player* target) {
	if (!playerToBring || !target)
		return;

	if (playerToBring->get_NetworkedView() && target->get_Head()) {
		auto networkView = playerToBring->get_NetworkedView();
		auto head = target->get_Head();

		if (networkView && head) {
			auto tpPosition = head->get_transform()->get_position() + head->get_transform()->get_forward();

			auto parameters = SDK::Pointers::Exports::Exports.il2cpp_array_new(Globals::Vars::Runtime::Native::Object, 1);
			parameters->vector[0] = SDK::Pointers::Exports::Exports.il2cpp_value_box(Globals::Vars::Runtime::Native::Vector3, &tpPosition);

			networkView->RPC("RpcAuthorityCV2SetPosition", 0, parameters);
		}
	}
}

void Cheats::Managers::PlayerList::Mods::RPC::BringAllToPlayer(SDK::RR::Game::Player* target) {
	if (!target)
		return;

	if (target->get_Head() && target->get_Head()->get_transform()) {
		for (auto& plr : players) {
			if (plr.instance && plr.instance != target && plr.networkView) {
				auto tpPosition = target->get_Head()->get_transform()->get_position() + target->get_Head()->get_transform()->get_forward();

				auto parameters = SDK::Pointers::Exports::Exports.il2cpp_array_new(Globals::Vars::Runtime::Native::Object, 1);
				parameters->vector[0] = SDK::Pointers::Exports::Exports.il2cpp_value_box(Globals::Vars::Runtime::Native::Vector3, &tpPosition);

				plr.networkView->RPC("RpcAuthorityCV2SetPosition", 0, parameters);
			}
		}
	}
}

void Cheats::Managers::PlayerList::Mods::RPC::Void(SDK::RR::Game::Player* target) {
	if (!target)
		return;

	if (target->get_NetworkedView()) {
		auto tpPosition = Globals::Vars::PlayerList::infinityToggle ? SDK::Structs::Unity::Vector3(-99999997781963083612160.000, -99999997781963083612160.000, -99999997781963083612160.000) : SDK::Structs::Unity::Vector3(0, -100000, 0);
		
		auto parameters = SDK::Pointers::Exports::Exports.il2cpp_array_new(Globals::Vars::Runtime::Native::Object, 1);
		parameters->vector[0] = SDK::Pointers::Exports::Exports.il2cpp_value_box(Globals::Vars::Runtime::Native::Vector3, &tpPosition);

		target->get_NetworkedView()->RPC("RpcAuthorityCV2SetPosition", 0, parameters);
	}
}

void Cheats::Managers::PlayerList::Mods::RPC::Spawn(SDK::RR::Game::Player* target) {
	if (!target)
		return;

	if (target->get_Head() && target->get_NetworkedView()) {
		auto headTransform = target->get_Head()->get_transform();
		if (headTransform) {
			bool wtv = true;
			auto spawnPosition = headTransform->get_position();
			bool secondWtv = true;

			auto parameters = SDK::Pointers::Exports::Exports.il2cpp_array_new(Globals::Vars::Runtime::Native::Object, 3);
			parameters->vector[0] = SDK::Pointers::Exports::Exports.il2cpp_value_box(Globals::Vars::Runtime::Native::Boolean, &wtv);
			parameters->vector[1] = SDK::Pointers::Exports::Exports.il2cpp_value_box(Globals::Vars::Runtime::Native::Vector3, &spawnPosition);
			parameters->vector[2] = SDK::Pointers::Exports::Exports.il2cpp_value_box(Globals::Vars::Runtime::Native::Boolean, &secondWtv);

			target->get_NetworkedView()->RPC("RpcBroadcastSpawnPlayer", 0, parameters);
		}
	}
}

void Cheats::Managers::PlayerList::Mods::RPC::Despawn(SDK::RR::Game::Player* target) {
	if (!target)
		return;

	if (target->get_NetworkedView()) {
		bool showModel = false;

		auto parameters = SDK::Pointers::Exports::Exports.il2cpp_array_new(Globals::Vars::Runtime::Native::Object, 1);
		parameters->vector[0] = SDK::Pointers::Exports::Exports.il2cpp_value_box(Globals::Vars::Runtime::Native::Boolean, &showModel);

		target->get_NetworkedView()->RPC("RpcBroadcastDespawnPlayer", 0, parameters);
	}
}

void Cheats::Managers::PlayerList::Mods::RPC::Spin(SDK::RR::Game::Player* target) {
	if (!target)
		return;


	if (target->get_NetworkedView()) {
		static float totalSpinAngle = 0.0f;
		totalSpinAngle += 100.f * ImGui::GetIO().DeltaTime;

		if (totalSpinAngle >= 360.f)
			totalSpinAngle -= 360.f;

		auto spinRotation = SDK::Structs::Unity::Quaternion::FromEuler(0.0f, totalSpinAngle, 0.f);

		auto parameters = SDK::Pointers::Exports::Exports.il2cpp_array_new(Globals::Vars::Runtime::Native::Object, 1);
		parameters->vector[0] = SDK::Pointers::Exports::Exports.il2cpp_value_box(Globals::Vars::Runtime::Native::Quaternion, &spinRotation);

		target->get_NetworkedView()->RPC("RpcAuthorityCV2SetRotation", 0, parameters);
	}
}