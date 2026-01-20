#include "PointerUtils.h"

void* SDK::Pointers::Utils::getCamera(int index) {
	auto cameras = Unity::Camera.get_allCameras.Invoke().Get();
	if (index >= 0 && index < cameras->getLength())
	{
		void** camera = cameras->getPointer();
		return camera[index];
	}
	return nullptr;
}


SDK::Structs::Unity::Vector3 SDK::Pointers::Utils::WorldToScreenPoint(void* camera, SDK::Structs::Unity::Vector3 position) {
	if (camera) {
		void* args[1] = { &position };
		auto screenPosition = Unity::Camera.WorldToScreenPoint[camera].Invoke(args).Unbox();
		return Structs::Unity::Vector3(screenPosition.X, ImGui::GetIO().DisplaySize.y - screenPosition.Y, screenPosition.Z);
	}
	return SDK::Structs::Unity::Vector3(0, 0, 0);
}