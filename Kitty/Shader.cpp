#include "Shader.h"

namespace SDK::Pointers::Unity {
	U_Shader Shader;

	void U_Shader::Setup() {
		klass = IL2CPP::Backends::Class("UnityEngine.CoreModule", "UnityEngine", "Shader");

		Find = klass.GetMethod("Find", 1);
		GetPropertyName = klass.GetMethod("GetPropertyName", 2);
		GetPropertyCount = klass.GetMethod("GetPropertyCount", 0);
	}
}