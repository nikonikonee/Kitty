#include "Combat.h"
#include "Logger.h"

bool (*old_PlayerIsInvincible)(void* instance, SDK::RR::GameServer::NetworkedPlayer* networkedPlayer);
bool PlayerIsInvincible(void* instance, SDK::RR::GameServer::NetworkedPlayer* networkedPlayer) {
	if (instance && networkedPlayer == SDK::RR::Game::Player::get_LocalPlayer()->get_NetworkedPlayer() && Globals::Vars::Combat::questInvincibility)
		return true;
	return old_PlayerIsInvincible(instance, networkedPlayer);
}

int (*old_GetPlayerHealth)(void* instance, SDK::RR::GameServer::NetworkedPlayer* networkedPlayer);
int GetPlayerHealth(void* instance, SDK::RR::GameServer::NetworkedPlayer* networkedPlayer) {
	if (instance && Globals::Vars::Combat::pvpGodMode) {
		return 999;
	}
	return old_GetPlayerHealth(instance, networkedPlayer);
}

bool (*old_IsOnCooldown)(void* instance);
bool IsOnCooldown(void* instance) {
	if (instance && Globals::Vars::Combat::basicRapidFire)
		return false;
	return old_IsOnCooldown(instance);
}

int (*old_MagazineAmmunition)(void* instance);
int MagazineAmmunition(void* instance) {
	if (instance && Globals::Vars::Combat::infiniteAmmo)
		return 1;
	return old_MagazineAmmunition(instance);
}

int (*old_TotalAmmunition)(void* instance);
int TotalAmmunition(void* instance) {
	if (instance && Globals::Vars::Combat::infiniteAmmo)
		return 1;
	return old_TotalAmmunition(instance);
}

bool (*old_HasEnoughMagazineAmmunition)(void* instance);
bool HasEnoughMagazineAmmunition(void* instance) {
	if (instance && Globals::Vars::Combat::infiniteAmmo)
		return true;
	return old_HasEnoughMagazineAmmunition(instance);
}

float (*old_CurrentRecoilMultiplier)(void* instance);
float CurrentRecoilMultiplier(void* instance) {
	if (instance && Globals::Vars::Combat::noRecoil)
		return 0.0f;
	return old_CurrentRecoilMultiplier(instance);
}

float (*old_CurrentProjectileSpreadMultiplier)(void* instance);
float CurrentProjectileSpreadMultiplier(void* instance) {
	if (instance && Globals::Vars::Combat::noSpread)
		return 0.0f;
	return old_CurrentProjectileSpreadMultiplier(instance);
}

void (*old_FireHook)(SDK::RR::Game::RangedWeapon* instance, SDK::Structs::Unity::Vector3 velocity, float charge);
void FireHook(SDK::RR::Game::RangedWeapon* instance, SDK::Structs::Unity::Vector3 velocity, float charge) {

	if (instance) {
		float bulletSpeed = instance->bulletFireSpeed();
		auto barrelTransform = instance->barrelTransform();

		if (barrelTransform) {
			if (Globals::Vars::Runtime::Var::silentAimbotDirection != SDK::Structs::Unity::Vector3(0, 0, 0) && Globals::Vars::Aimbot::enableSilentAimbot) {
				float usedBulletSpeed = Globals::Vars::Combat::bulletSpeedModifier ? Globals::Vars::Combat::Var::bulletSpeed : bulletSpeed;
				velocity = Globals::Vars::Runtime::Var::silentAimbotDirection * usedBulletSpeed;
			}

			else if (Globals::Vars::Combat::bulletSpeedModifier && !Globals::Vars::Aimbot::enableSilentAimbot) {
				velocity = barrelTransform->get_forward() * Globals::Vars::Combat::Var::bulletSpeed;
			}
		}

		if (Globals::Vars::Combat::bulletMultiplier)
			for (int i = 0; i < Globals::Vars::Combat::Var::bulletAmount - 1; ++i)
				old_FireHook(instance, velocity, charge);
	}

	return old_FireHook(instance, velocity, charge);
}


void Cheats::Combat::Setup() {
	/*---- Quest Inv ----*/
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "", "GameCombatManager", "PlayerIsInvincible", 1), &PlayerIsInvincible, (void**)&old_PlayerIsInvincible);
	/*---- PvP God Mode ----*/
	//Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "", "GameCombatManager", "GetPlayerHealth", 1), &GetPlayerHealth, (void**)&old_GetPlayerHealth);
	/*---- Basic Rapid Fire ----*/
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "RecRoom.Core.Combat", "RangedWeapon", "get_IsOnCooldown", 0), &IsOnCooldown, (void**)&old_IsOnCooldown);
	/*---- No Recoil & Spread ----*/
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "RecRoom.Core.Combat", "Weapon", "get_MagazineAmmunition", 0), &MagazineAmmunition, (void**)&old_MagazineAmmunition);
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "RecRoom.Core.Combat", "Weapon", "get_TotalAmmunition", 0), &TotalAmmunition, (void**)&old_TotalAmmunition);
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "RecRoom.Core.Combat", "Weapon", "get_HasEnoughMagazineAmmunition", 0), &HasEnoughMagazineAmmunition, (void**)&old_HasEnoughMagazineAmmunition);
	/*---- No Recoil & Spread ----*/
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "RecRoom.Core.Combat", "RangedWeapon", "get_CurrentRecoilMultiplier", 0), &CurrentRecoilMultiplier, (void**)&old_CurrentRecoilMultiplier);
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "RecRoom.Core.Combat", "RangedWeapon", "get_CurrentProjectileSpreadMultiplier", 0), &CurrentProjectileSpreadMultiplier, (void**)&old_CurrentProjectileSpreadMultiplier);
	/*---- Bullet Multiplier ----*/
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "RecRoom.Core.Combat", "RangedWeapon", "Fire", 2), &FireHook, (void**)&old_FireHook);
	Logger::Log(clr::magenta, "[Cheat] Setup: [Combat]");
}