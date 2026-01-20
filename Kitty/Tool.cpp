#include "Tool.h"

namespace SDK::Pointers::Game {
	U_Tool Tool;

	void U_Tool::Setup() {
		klass = IL2CPP::Backends::Class("", "", "Tool");

		PhotonInstantiateForRoom = klass.GetMethod("PhotonInstantiateForRoom", 6);
	}
}