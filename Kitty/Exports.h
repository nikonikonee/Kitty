#pragma once
#include "CheatUtils.h"
#include "Pointers.h"
#include "ExportOffsets.h"
#include "Vars.h"
#include "String.h"
#include "Il2CppArray.h"

namespace SDK::Pointers::Exports {
	struct U_Exports {
		//Basic
		void* (*il2cpp_domain_get)();
		void* (*il2cpp_thread_attach)(void* domain);

		//Retreving Classes, Methods, Fields, Etc
		void* (*il2cpp_domain_assembly_open)(const char* image);
		void* (*il2cpp_class_from_name)(void* image, const char* nameSpace, const char* klass);
		void* (*il2cpp_class_get_method_from_name)(void* klass, const char* methodName, int args);
		void* (*il2cpp_class_get_field_from_name)(void* klass, const char* fieldName);
		void* (*il2cpp_field_get_value_object)(void* field, void* obj);
		void* (*il2cpp_object_get_class)(void* object);
		void* (*il2cpp_class_get_methods)(void* klass, void** iter);

		//Retreving Class, Method & type Info
		const char* (*il2cpp_class_get_name)(void* klass);
		void* (*il2cpp_class_get_parent)(void* klass);
		const char* (*il2cpp_method_get_name)(void* method);
		uint32_t (*il2cpp_method_get_param_count)(void* method);
		void* (*il2cpp_method_get_param)(void* method, uint32_t index);
		const char* (*il2cpp_method_get_param_name)(void* method, uint32_t index);
		char* (*il2cpp_type_get_name)(void* type);

		//Invoking Methods
		void* (*il2cpp_runtime_invoke)(void* methodPtr, void* object, void** args, void** exc);
		void* (*il2cpp_object_unbox)(void* object);

		//Creating C# Types
		Structs::Mono::String* (*il2cpp_string_new)(const char* str);
		void* (*il2cpp_object_new)(void* klass);
		Structs::IL2CPP::Il2CppArray* (*il2cpp_array_new)(void* elementTypeInfo, size_t length);
		void* (*il2cpp_value_box)(void* klass, void* data);

		//Add more soon

		void Setup();
	};
	extern U_Exports Exports;
}