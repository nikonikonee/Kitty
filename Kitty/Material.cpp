#include "Material.h"

namespace SDK::Pointers::Unity {
	U_Material Material;

	void U_Material::Setup() {
		klass = IL2CPP::Backends::Class("UnityEngine.CoreModule", "UnityEngine", "Material");

		ctor = klass.GetMethod(".ctor", 1);
		SetInt = klass.GetMethod("SetInt", 2);
		SetColor = klass.GetMethod("SetColor", 2);
	}
}