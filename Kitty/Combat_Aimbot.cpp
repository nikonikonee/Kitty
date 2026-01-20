#include "Combat_Aimbot.h"

void Cheats::Combat::Aimbot::Run() {
	ImVec2 center = ImVec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2);

	if (players.empty())
		return;

	auto camera = SDK::RR::Unity::Camera::getCamera(0);
	if (!camera) return;

	auto screenPlayerController = SDK::Pointers::Game::LocalPlayerController.get_ScreenPlayerControllerInstance.Invoke().Get();
	if (!screenPlayerController) return;

	auto closestPlayer = Cheats::Combat::Aimbot::Utils::GetClosestPlayerWithinFOV();
	if (!closestPlayer) return;


	auto closestPlayerHead = closestPlayer->get_Head();
	auto closestPlayerBody = closestPlayer->get_Body();

	if (closestPlayerHead && closestPlayerBody) {
		auto cameraSystem = SDK::Pointers::Game::ScreenPlayerController.get_CameraSystem[screenPlayerController].Invoke().Get();

		auto cameraTransform = camera->get_transform();
		auto closestPlayerHeadTransform = closestPlayerHead->get_transform();
		auto closestPlayerBodyTransform = closestPlayerBody->get_transform();

		if (cameraSystem && cameraTransform && closestPlayerHeadTransform && closestPlayerBodyTransform) {
			auto cameraPosition = cameraTransform->get_position();
			auto cameraRotation = *(SDK::Structs::Unity::Quaternion*)((uint64_t)cameraSystem + 0x98);
			
			auto closestPlayerHeadPosition = closestPlayerHeadTransform->get_position();
			auto closestPlayerBodyPosition = closestPlayerBodyTransform->get_position();

			//TO-DO Custom binding support
			if (GetAsyncKeyState(VK_XBUTTON1) & 0x8000) {
				if (Globals::Vars::Aimbot::headLock) {
					SDK::Structs::Unity::Quaternion rotationToTarget{};
					auto directionToTarget = SDK::Structs::Unity::Vector3::Normalized(closestPlayerHeadPosition - cameraPosition);

					if (Globals::Vars::Aimbot::overrideAimStrength)
						rotationToTarget = SDK::Structs::Unity::Quaternion::Slerp(cameraRotation, SDK::Structs::Unity::Quaternion::LookRotation(directionToTarget), ImGui::GetIO().DeltaTime * Globals::Vars::Aimbot::Var::aimStrength);
					else
						rotationToTarget = SDK::Structs::Unity::Quaternion::LookRotation(directionToTarget);
					*(SDK::Structs::Unity::Quaternion*)((uint64_t)cameraSystem + 0x98) = rotationToTarget;
				}
				else if (Globals::Vars::Aimbot::bodyLock) {
					SDK::Structs::Unity::Quaternion rotationToTarget{};
					auto directionToTarget = SDK::Structs::Unity::Vector3::Normalized(closestPlayerBodyPosition - cameraPosition);

					if (Globals::Vars::Aimbot::overrideAimStrength)
						rotationToTarget = SDK::Structs::Unity::Quaternion::Slerp(cameraRotation, SDK::Structs::Unity::Quaternion::LookRotation(directionToTarget), ImGui::GetIO().DeltaTime * Globals::Vars::Aimbot::Var::aimStrength);
					else
						rotationToTarget = SDK::Structs::Unity::Quaternion::LookRotation(directionToTarget);
					*(SDK::Structs::Unity::Quaternion*)((uint64_t)cameraSystem + 0x98) = rotationToTarget;
				}
			}
		}
	}
}