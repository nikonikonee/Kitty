#include "Transform.h"

namespace SDK::Pointers::Unity {
	U_Transform Transform;

	void U_Transform::Setup() {
		klass = IL2CPP::Backends::Class("UnityEngine.CoreModule", "UnityEngine", "Transform");

		get_position = klass.GetMethod("get_position", 0);
		get_forward = klass.GetMethod("get_forward", 0);
		get_rotation = klass.GetMethod("get_rotation", 0);

		set_position = klass.GetMethod("set_position", 1);
		set_localPosition = klass.GetMethod("set_localPosition", 1);

		set_rotation = klass.GetMethod("set_rotation", 1);
		set_localScale = klass.GetMethod("set_localScale", 1);

		set_parent = klass.GetMethod("set_parent", 1);

		GetChild = klass.GetMethod("GetChild", 1);
		GetChildCount = klass.GetMethod("GetChildCount", 0);
	}
}