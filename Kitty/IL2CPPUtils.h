#pragma once
#include "Exports.h"
#include "Vars.h"

#include "Il2CppDomain.h"
#include "Il2CppClass.h"
#include "Il2CppMethod.h"

namespace SDK::IL2CPP::Utils {
	//Spoofed Versions of exports
	extern Structs::IL2CPP::Il2CppDomain* il2cpp_domain_get();
	extern void* il2cpp_runtime_invoke(void* method, void* object, void** args, void** exc);
	extern void* il2cpp_object_unbox(void* object);
	extern void* il2cpp_object_new(void* klass);
	extern Structs::Mono::String* il2cpp_string_new(const char* str);

	//Getting Classes & Methods
	extern Structs::IL2CPP::Il2CppClass* GetClass(const char* image, const char* nameSpace, const char* klass);
	extern Structs::IL2CPP::Il2CppMethod* GetMethod(const char* image, const char* nameSpace, const char* klass, const char* methodName, int args);
	extern Structs::IL2CPP::Il2CppMethod* GetSpecificMethod(const char* image, const char* nameSpace, const char* klass, const char* methodName, int args, const char* parameterTypeName);

	extern void* GetMethodPtr(const char* image, const char* nameSpace, const char* klass, const char* methodName, int args);
	extern void* GetSpecificMethodPtr(const char* image, const char* nameSpace, const char* klass, const char* methodName, int args, const char* parameterTypeName);
	
	//Getting Methods From Pre-Existing Pointers, for backends.
	extern Structs::IL2CPP::Il2CppMethod* GetMethodFromClass(Structs::IL2CPP::Il2CppClass* klass, const char* methodName, int args);
	extern void* GetFieldFromClass(Structs::IL2CPP::Il2CppClass* klass, const char* name);
	extern Structs::IL2CPP::Il2CppMethod* GetSpecificMethodFromClass(Structs::IL2CPP::Il2CppClass* klass, const char* methodName, int args, const char* parameterTypeName);

	//Getting Fields (TODO) (MAKE SPECIAL BACKEND)
	//Getting Properties (TODO) (MAKE SPECIAL BACKEND)
}