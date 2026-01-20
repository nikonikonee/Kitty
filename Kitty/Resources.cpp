#include "Resources.h"

namespace SDK::Pointers::Unity {
	U_Resources Resources;

	void U_Resources::Setup() {
		klass = IL2CPP::Backends::Class("UnityEngine.CoreModule", "UnityEngine", "Resources");

		FindObjectsOfTypeAll = klass.GetMethod("FindObjectsOfTypeAll", 1);
	}
}