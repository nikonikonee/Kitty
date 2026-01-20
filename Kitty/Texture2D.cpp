#include "Texture2D.h"

namespace SDK::Pointers::Unity {
	U_Texture2D Texture2D;

	void U_Texture2D::Setup() {
		klass = IL2CPP::Backends::Class("UnityEngine.CoreModule", "UnityEngine", "Texture2D");

		ctor = klass.GetMethod(".ctor", 2);
	}
}