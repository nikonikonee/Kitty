#pragma once
#include "Method.h"
#include "Il2CppClass.h"

namespace SDK::IL2CPP::Backends::Helper {
	template <typename T>
	static void AssignSpecificType(void* object, const char* methodName, int args, Method<T>& method) {
		auto klass = Pointers::Exports::Exports.il2cpp_object_get_class(object);
		if (!klass)
			return;
		printf("[runtime] klass: %p\n", klass);
		auto methodFromClass = Utils::GetMethodFromClass((Structs::IL2CPP::Il2CppClass*)klass, methodName, args);
		if (!methodFromClass)
			return;
		method = methodFromClass;
	}
}