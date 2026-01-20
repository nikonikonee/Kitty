#include "SphereCollider.h"

namespace SDK::Pointers::Unity {
	U_SphereCollider SphereCollider;

	void U_SphereCollider::Setup() {
		klass = IL2CPP::Backends::Class("UnityEngine.PhysicsModule", "UnityEngine", "SphereCollider");

		set_radius = klass.GetMethod("set_radius", 1);
	}
}