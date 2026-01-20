#include "Spawnables.h"
#include "Logger.h"
#include "RetSpoofer/RetSpoofer.hpp"


void (*old_SpawnConsumableForLocalPlayer)(void* instance, SDK::Structs::Mono::String* foodGuid, void* nullable, SDK::Structs::Unity::Vector3 position, SDK::Structs::Unity::Quaternion rotation, float scale, void* spawnedEquipment);
void SpawnConsumableForLocalPlayer(void* instance, SDK::Structs::Mono::String* foodGuid, void* nullable, SDK::Structs::Unity::Vector3 position, SDK::Structs::Unity::Quaternion rotation, float scale, void* spawnedEquipment) {
	if (instance && Globals::Vars::Spawnables::foodsploit) {
		//Pre-defined vars
		auto customFoodGuid = SDK::Pointers::Exports::Exports.il2cpp_string_new(Globals::Vars::Runtime::List::foods[Globals::Vars::Runtime::List::Selected::food].second.c_str());

		//Switches
		auto amount = Globals::Vars::Spawnables::customFoodAmount ? Globals::Vars::Spawnables::Var::foodAmount : 1;
		position = Globals::Vars::Spawnables::customFoodPosition ? Globals::Vars::Spawnables::Var::foodPosition : position;
		rotation = Globals::Vars::Spawnables::customFoodRotation ? Globals::Vars::Spawnables::Var::foodRotation : rotation;
		scale = Globals::Vars::Spawnables::customFoodScale ? Globals::Vars::Spawnables::Var::foodScale : scale;
		foodGuid = Globals::Vars::Spawnables::customFoodGuid ? customFoodGuid : foodGuid;


		for (int i = 0; i < amount; ++i)
			old_SpawnConsumableForLocalPlayer(instance, foodGuid, nullable, position, rotation, scale, spawnedEquipment);
	}
	else if (instance && Globals::Vars::Spawnables::foodOverrideSpawn) {
		//Pre-defined variables
		auto defaultRotation = SDK::Structs::Unity::Quaternion(0, 0, 0, 0);

		//Switches
		auto amount = Globals::Vars::Spawnables::customAssetAmount ? Globals::Vars::Spawnables::Var::assetAmount : 1;
		SDK::Structs::Unity::Vector3 assetPosition = Globals::Vars::Spawnables::customAssetPosition ? Globals::Vars::Spawnables::Var::assetPosition : position;
		SDK::Structs::Unity::Quaternion assetRotation = Globals::Vars::Spawnables::customAssetRotation ? Globals::Vars::Spawnables::Var::assetRotation : SDK::Structs::Unity::Quaternion(0, 0, 0, 0);
		SDK::Structs::Unity::Vector3 assetScale = Globals::Vars::Spawnables::customAssetScale ? Globals::Vars::Spawnables::Var::assetScale : SDK::Structs::Unity::Vector3(1, 1, 1);

		for (int i = 0; i < amount; ++i) {
			auto prefab = SDK::RR::GameServer::RRNetworking::Instantiate(Globals::Lists::Prefabs::list[Globals::Lists::Prefabs::selectedPrefab].c_str(), assetPosition, assetRotation, assetScale, false);
			if (Globals::Vars::Spawnables::noAssetRender)
				SDK::RR::Base::Object::Destroy(prefab);
		}
	}
	else if (!Globals::Vars::Spawnables::foodsploit || !Globals::Vars::Spawnables::foodOverrideSpawn)
		return old_SpawnConsumableForLocalPlayer(instance, foodGuid, nullable, position, rotation, scale, spawnedEquipment);
}

void (*old_IsNew)(void* instance, bool isNew);
void IsNew(void* instance, bool isNew) {
	if (instance && Globals::Vars::Spawnables::newFoodBypassToggle) {
		printf("fax %i\n", isNew);
		return old_IsNew(instance, false);
	}
	return old_IsNew(instance, isNew);
}

void (*old_OnTookPhoto)(void* instance);
void OnTookPhoto(void* instance) {
	if (instance && Globals::Vars::Spawnables::takePhotoSpawn) {
		auto localPlayer = SDK::Pointers::Game::Player.get_LocalPlayer.Invoke().Get();
		if (localPlayer) {
			auto head = SDK::Pointers::Game::Player.get_Head[localPlayer].Invoke().Get();
			if (head) {
				auto headTransform = SDK::Pointers::Unity::Component.get_transform[head].Invoke().Get();
				if (headTransform) {
					//Pre-defined vars
					auto fixedPosition = SDK::Pointers::Unity::Transform.get_position[headTransform].Invoke().Unbox() + SDK::Pointers::Unity::Transform.get_forward[headTransform].Invoke().Unbox();
					auto amount = Globals::Vars::Spawnables::customAssetAmount ? Globals::Vars::Spawnables::Var::assetAmount : 1;
					auto defaultRotation = SDK::Structs::Unity::Quaternion(0, 0, 0, 0);
					auto defaultScale = SDK::Structs::Unity::Vector3(1, 1, 1);

					//Switches
					SDK::Structs::Unity::Vector3 assetPosition = Globals::Vars::Spawnables::customAssetPosition ? Globals::Vars::Spawnables::Var::assetPosition : fixedPosition;
					SDK::Structs::Unity::Quaternion assetRotation = Globals::Vars::Spawnables::customAssetRotation ? Globals::Vars::Spawnables::Var::assetRotation : defaultRotation;
					SDK::Structs::Unity::Vector3 assetScale = Globals::Vars::Spawnables::customAssetScale ? Globals::Vars::Spawnables::Var::assetScale : defaultScale;

					for (int i = 0; i < amount; ++i) {
						auto prefab = SDK::RR::GameServer::RRNetworking::Instantiate(Globals::Lists::Prefabs::list[Globals::Lists::Prefabs::selectedPrefab].c_str(), assetPosition, assetRotation, assetScale, false);
						if (Globals::Vars::Spawnables::noAssetRender)
							SDK::RR::Base::Object::Destroy(prefab);
					}
				}
			}
		}
	}
	else if (!Globals::Vars::Spawnables::takePhotoSpawn)
		return old_OnTookPhoto(instance);
}

void (*old_PrintPhoto)(void* instance);
void PrintPhoto(void* instance) {
	if (instance && Globals::Vars::Spawnables::printPhotoSpawn) {
		auto localPlayer = SDK::Pointers::Game::Player.get_LocalPlayer.Invoke().Get();
		if (localPlayer) {
			auto head = SDK::Pointers::Game::Player.get_Head[localPlayer].Invoke().Get();
			if (head) {
				auto headTransform = SDK::Pointers::Unity::Component.get_transform[head].Invoke().Get();
				if (headTransform) {
					//Pre-defined vars
					auto fixedPosition = SDK::Pointers::Unity::Transform.get_position[headTransform].Invoke().Unbox() + SDK::Pointers::Unity::Transform.get_forward[headTransform].Invoke().Unbox();
					auto amount = Globals::Vars::Spawnables::customAssetAmount ? Globals::Vars::Spawnables::Var::assetAmount : 1;
					auto defaultRotation = SDK::Structs::Unity::Quaternion(0, 0, 0, 0);
					auto defaultScale = SDK::Structs::Unity::Vector3(1, 1, 1);

					//Switches
					SDK::Structs::Unity::Vector3 assetPosition = Globals::Vars::Spawnables::customAssetPosition ? Globals::Vars::Spawnables::Var::assetPosition : fixedPosition;
					SDK::Structs::Unity::Quaternion assetRotation = Globals::Vars::Spawnables::customAssetRotation ? Globals::Vars::Spawnables::Var::assetRotation : defaultRotation;
					SDK::Structs::Unity::Vector3 assetScale = Globals::Vars::Spawnables::customAssetScale ? Globals::Vars::Spawnables::Var::assetScale : defaultScale;

					for (int i = 0; i < amount; ++i) {
						auto prefab = SDK::RR::GameServer::RRNetworking::Instantiate(Globals::Lists::Prefabs::list[Globals::Lists::Prefabs::selectedPrefab].c_str(), assetPosition, assetRotation, assetScale, false);
						if (Globals::Vars::Spawnables::noAssetRender)
							SDK::RR::Base::Object::Destroy(prefab);
					}
				}
			}
		}
	}
	else if (!Globals::Vars::Spawnables::printPhotoSpawn)
		return old_PrintPhoto(instance);
}

void (*old_ShareRoomCode)(void* instance);
void ShareRoomCode(void* instance) {
	if (instance && Globals::Vars::Spawnables::shareButtonSpawn) {
		auto localPlayer = SDK::Pointers::Game::Player.get_LocalPlayer.Invoke().Get();
		if (localPlayer) {
			auto head = SDK::Pointers::Game::Player.get_Head[localPlayer].Invoke().Get();
			if (head) {
				auto headTransform = SDK::Pointers::Unity::Component.get_transform[head].Invoke().Get();
				if (headTransform) {
					//Pre-defined vars
					auto fixedPosition = SDK::Pointers::Unity::Transform.get_position[headTransform].Invoke().Unbox() + SDK::Pointers::Unity::Transform.get_forward[headTransform].Invoke().Unbox();
					auto amount = Globals::Vars::Spawnables::customAssetAmount ? Globals::Vars::Spawnables::Var::assetAmount : 1;
					auto defaultRotation = SDK::Structs::Unity::Quaternion(0, 0, 0, 0);
					auto defaultScale = SDK::Structs::Unity::Vector3(1, 1, 1);

					//Switches
					SDK::Structs::Unity::Vector3 assetPosition = Globals::Vars::Spawnables::customAssetPosition ? Globals::Vars::Spawnables::Var::assetPosition : fixedPosition;
					SDK::Structs::Unity::Quaternion assetRotation = Globals::Vars::Spawnables::customAssetRotation ? Globals::Vars::Spawnables::Var::assetRotation : defaultRotation;
					SDK::Structs::Unity::Vector3 assetScale = Globals::Vars::Spawnables::customAssetScale ? Globals::Vars::Spawnables::Var::assetScale : defaultScale;

					for (int i = 0; i < amount; ++i) {
						auto prefab = SDK::RR::GameServer::RRNetworking::Instantiate(Globals::Lists::Prefabs::list[Globals::Lists::Prefabs::selectedPrefab].c_str(), assetPosition, assetRotation, assetScale, false);
						if (Globals::Vars::Spawnables::noAssetRender)
							SDK::RR::Base::Object::Destroy(prefab);
					}
				}
			}
		}
	}
	else if (!Globals::Vars::Spawnables::shareButtonSpawn)
		return old_ShareRoomCode(instance);
}

void Cheats::Spawnables::Setup() {
	auto consumableManager = SDK::IL2CPP::Backends::Class("", "RecRoom.Consumable", "ConsumableManager");
	auto playerEvents = SDK::IL2CPP::Backends::Class("", "", "PlayerEvents");
	auto shareCameraToolMenuModel = SDK::IL2CPP::Backends::Class("", "RRUI.Data", "ShareCameraToolMenuModel");
	auto roomModel = SDK::IL2CPP::Backends::Class("", "RRUI.Data", "RoomModel");
	auto playerSpawnedEquipment = SDK::IL2CPP::Backends::Class("", "", "PlayerSpawnedEquipment");


	Utils::Hook(consumableManager.GetMethodPtr("SpawnConsumableForLocalPlayer", 6), &SpawnConsumableForLocalPlayer, (void**)&old_SpawnConsumableForLocalPlayer);
	Utils::Hook(playerSpawnedEquipment.GetMethodPtr("set_IsNew", 1), &IsNew, (void**)&old_IsNew);
	Utils::Hook(playerEvents.GetMethodPtr("OnTookPhoto", 3), &OnTookPhoto, (void**)&old_OnTookPhoto);
	Utils::Hook(shareCameraToolMenuModel.GetMethodPtr("PrintPhoto", 0), &PrintPhoto, (void**)&old_PrintPhoto);
	Utils::Hook(roomModel.GetMethodPtr("ShareRoomCode", 0), &ShareRoomCode, (void**)&old_ShareRoomCode);

	Logger::Log(clr::magenta, "[Cheat] Setup: [Spawnables]");
}