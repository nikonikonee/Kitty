#include "Combat_SilentAimbot.h"

void Cheats::Combat::SilentAimbot::Run() {

	if (players.empty())
		return;

	auto closestPlayer = Globals::Vars::Aimbot::useFovCircle ? Cheats::Combat::Aimbot::Utils::GetClosestPlayerWithinFOV() : Cheats::Combat::Aimbot::Utils::GetClosestPlayer();
	if (!closestPlayer) {
		Globals::Vars::Runtime::Var::silentAimbotDirection = SDK::Structs::Unity::Vector3(0, 0, 0);
		return;
	}

	auto weapon = Cheats::Combat::Aimbot::Utils::GetLocalPlayerWeapon();
	if (!weapon) return;

	auto closestPlayerHead = closestPlayer->get_Head();
	auto closestPlayerBody = closestPlayer->get_Body();

	if (closestPlayerHead && closestPlayerBody) {
		auto closestPlayerHeadTransform = closestPlayerHead->get_transform();
		auto closestPlayerBodyTransform = closestPlayerBody->get_transform();
		auto barrelTransform = weapon->barrelTransform();

		if (closestPlayerHeadTransform && closestPlayerBodyTransform && barrelTransform) {
			auto closestPlayerHeadPosition = closestPlayerHeadTransform->get_position();
			auto closestPlayerBodyPosition = closestPlayerBodyTransform->get_position();
			auto barrelPosition = barrelTransform->get_position();
		
			auto targetPosition = Globals::Vars::Aimbot::bodyLock ? closestPlayerBodyPosition : closestPlayerHeadPosition;

			auto directionToTarget = SDK::Structs::Unity::Vector3::Normalized(targetPosition - barrelPosition);

			Globals::Vars::Runtime::Var::silentAimbotDirection = directionToTarget;
		}
	}
}

void Cheats::Combat::SilentAimbot::RunPlayer(void* player) {

}