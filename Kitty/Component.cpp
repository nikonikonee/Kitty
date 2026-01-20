#include "Component.h"

namespace SDK::Pointers::Unity {
	U_Component Component;

	void U_Component::Setup() {
		klass = IL2CPP::Backends::Class("UnityEngine.CoreModule", "UnityEngine", "Component");

		get_transform = klass.GetMethod("get_transform", 0);
		get_gameObject = klass.GetMethod("get_gameObject", 0);
		GetComponent = klass.GetMethod("GetComponent", 1);
	}
}