#include "Renderer.h"

namespace SDK::Pointers::Unity {
	U_Renderer Renderer;

	void U_Renderer::Setup() {
		klass = IL2CPP::Backends::Class("UnityEngine.CoreModule", "UnityEngine", "Renderer");

		get_material = klass.GetMethod("get_material", 0);
		set_material = klass.GetMethod("set_material", 1);
	}
}