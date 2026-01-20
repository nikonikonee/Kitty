#include "Object.h"

namespace SDK::Pointers::Unity {
	U_Object Object;

	void U_Object::Setup() {
		klass = IL2CPP::Backends::Class("UnityEngine.CoreModule", "UnityEngine", "Object");

		Instantiate = klass.GetSpecificMethod("Instantiate", 1, "UnityEngine.Object");
		FindObjectsOfType = klass.GetMethod("FindObjectsOfType", 2);
		get_name = klass.GetMethod("get_name", 0);
		Destroy = klass.GetMethod("Destroy", 1);
	}
}