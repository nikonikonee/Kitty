#pragma once
#include "Il2CppMethod.h"

namespace SDK::Structs::IL2CPP {
	struct Il2CppClass {
		Il2CppMethod* GetMethod(const char* methodName, int args);
		void* GetField(const char* fieldName);
		Il2CppMethod* GetMethods(void** iter);
	};
}