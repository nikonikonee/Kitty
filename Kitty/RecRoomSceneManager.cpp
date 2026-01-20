#include "RecRoomSceneManager.h"

namespace SDK::Pointers::Game {
	U_RecRoomSceneManager RecRoomSceneManager;

	void U_RecRoomSceneManager::Setup() {
		klass = IL2CPP::Backends::Class("", "", "RecRoomSceneManager");

		get_Instance = klass.GetMethod("get_Instance", 0);
	}
}