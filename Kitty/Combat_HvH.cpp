#include "Combat_HvH.h"

/*        float angle = spinSpeed * Time.deltaTime;
        Quaternion spinRotation = Quaternion.Euler(0f, angle, 0f);

        // Rotate relative to current rotation
        Quaternion newRotation = transform.rotation * spinRotation;*/

void Cheats::Combat::Aimbot::HvH::Run() {
	if (Globals::Vars::Aimbot::bhop) {
		if (GetAsyncKeyState(VK_SPACE) & 0x8000) {

		}
	}

	if (Globals::Vars::Aimbot::spinbot) {
		auto camera = SDK::Pointers::Utils::getCamera(0);
		auto screenPlayerController = SDK::Pointers::Game::LocalPlayerController.get_ScreenPlayerControllerInstance.Invoke().Get();
		auto localPlayer = SDK::Pointers::Game::Player.get_LocalPlayer.Invoke().Get();

		if (camera && localPlayer && screenPlayerController) {
			auto cameraTransform = SDK::Pointers::Unity::Component.get_transform[camera].Invoke().Get();
			auto cameraSystem = SDK::Pointers::Game::ScreenPlayerController.get_CameraSystem[screenPlayerController].Invoke().Get();
			if (cameraTransform && cameraSystem) {
				auto cameraPosition = SDK::Pointers::Unity::Transform.get_position[cameraTransform].Invoke().Unbox();
				auto cameraForward = SDK::Pointers::Unity::Transform.get_forward[cameraTransform].Invoke().Unbox();
				
				auto calculatedMoveDirection = cameraPosition + cameraForward;

				static float totalSpinAngle = 0.0f;
				totalSpinAngle += 100.f * ImGui::GetIO().DeltaTime;
				
				if (totalSpinAngle >= 360.f)
					totalSpinAngle -= 360.f;
				
				auto cameraRotation = *(SDK::Structs::Unity::Quaternion*)((uint64_t)cameraSystem + 0x98);

				SDK::Structs::Unity::Quaternion spinRotation = SDK::Structs::Unity::Quaternion::FromEuler(0.0f, totalSpinAngle, 0.f);
				void* setRotationArgs[1] = { &spinRotation };
				SDK::Pointers::Game::Player.RpcAuthorityCV2SetRotation[localPlayer].Invoke(setRotationArgs);

				auto euler = SDK::Structs::Unity::Quaternion::ToEuler(cameraRotation);
				euler.Y = 0.0f;
				auto newCamRotation = SDK::Structs::Unity::Quaternion::FromEuler(euler.X, euler.Y, euler.Z);

				//Set cam rotation back to origin before rotation
				*(SDK::Structs::Unity::Quaternion*)((uint64_t)cameraSystem + 0x98) = newCamRotation;

				if (GetAsyncKeyState(0x57) & 0x8000) {
					void* setPositionArgs[1] = { &calculatedMoveDirection };
					SDK::Pointers::Game::Player.RpcAuthorityCV2SetPosition[localPlayer].Invoke(setPositionArgs);
				}
			}
		}
	}
}