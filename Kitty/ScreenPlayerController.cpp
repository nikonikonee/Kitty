#include "ScreenPlayerController.h"

namespace SDK::Pointers::Game {
	U_ScreenPlayerController ScreenPlayerController;

	void U_ScreenPlayerController::Setup() {
		klass = IL2CPP::Backends::Class("", "RecRoom", "ScreenPlayerController");

		get_CameraSystem = klass.GetMethod("get_CameraSystem", 0);
	}
}