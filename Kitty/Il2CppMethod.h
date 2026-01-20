#pragma once
#include <iostream>
#include "Il2CppObject.h"
#include "Il2CppType.h"

namespace SDK::Structs::IL2CPP {
	struct Il2CppMethod {
		void* MethodPtr();
		//Retreive Method information
		const char* GetName();
		uint32_t GetParamCount();
		Il2CppType* GetParam(uint32_t index);

		Il2CppObject* RuntimeInvoke(void* object, void** args, void** exc);
	};
}