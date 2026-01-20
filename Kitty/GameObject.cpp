#include "GameObject.h"

namespace SDK::Pointers::Unity {
	U_GameObject GameObject;

	void U_GameObject::Setup() {
		klass = IL2CPP::Backends::Class("UnityEngine.CoreModule", "UnityEngine", "GameObject");

		GetComponent = klass.GetSpecificMethod("GetComponent", 1, "System.Type");
		GetComponentInChildren = klass.GetMethod("GetComponentInChildren", 1);

		GetComponentsInChildren = klass.GetMethod("GetComponentsInChildren", 1);
		GetComponents = klass.GetMethod("GetComponents", 1);

		AddComponent = klass.GetMethod("AddComponent", 1);
		get_transform = klass.GetMethod("get_transform", 0);

		ctor = klass.GetMethod(".ctor", 1);
	}
}