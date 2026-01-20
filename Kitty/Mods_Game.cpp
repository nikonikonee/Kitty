#include "Mods_Game.h"

void Cheats::Managers::PlayerList::Mods::Game::LoopFire(SDK::RR::Game::Player* target) {
	if (!target)
		return;

	auto toolsHeld = target->get_AllToolsHeld();

	for (int i = 0; i < toolsHeld->getLength(); ++i) {
		auto tool = toolsHeld->getPointer()[i];
		if (tool) {
			auto rangedWeapon = tool->GetComponent<SDK::RR::Game::RangedWeapon*>(SDK::RR::System::Type::GetType("RecRoom.Core.Combat.RangedWeapon, Assembly-CSharp"));
			if (rangedWeapon)
				rangedWeapon->Fire();
		}
	}
}

void Cheats::Managers::PlayerList::Mods::Game::Kill(SDK::RR::Game::GameCombatManager* instance, SDK::RR::Game::Player* target) {
	if (!instance || !target)
		return;

	if (target->get_NetworkedPlayer())
		instance->MasterKillPlayer(target->get_NetworkedPlayer());
}

void Cheats::Managers::PlayerList::Mods::Game::RestoreHealth(SDK::RR::Game::GameCombatManager* instance, SDK::RR::Game::Player* target, int health) {
	if (!instance || !target)
		return;

	if (target->get_NetworkedPlayer())
		instance->MasterSetPlayerHealth(target->get_NetworkedPlayer(), health);
}

void Cheats::Managers::PlayerList::Mods::Game::Invincibility(SDK::RR::Game::GameCombatManager* instance, SDK::RR::Game::Player* target, float duration) {
	if (!instance || !target)
		return;

	if (target->get_NetworkedPlayer())
		instance->MasterRequestPlayerInvincibility(target->get_NetworkedPlayer(), duration);
}