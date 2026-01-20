#include "LocalPlayerController.h"

namespace SDK::Pointers::Game {
	U_LocalPlayerController LocalPlayerController;

	void U_LocalPlayerController::Setup() {
		klass = IL2CPP::Backends::Class("", "RecRoom", "LocalPlayerController");

		get_ScreenPlayerControllerInstance = klass.GetMethod("get_ScreenPlayerControllerInstance", 0);
	}
}