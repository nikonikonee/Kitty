#include "Exports.h"
#include "RetSpoofer/RetSpoofer.hpp"

namespace SDK::Pointers::Exports {
	U_Exports Exports;

	void U_Exports::Setup() {
		HMODULE GameAssembly = GetModuleHandleA("GameAssembly.dll");

		il2cpp_domain_get = (void* (*)()) Utils::getAbsoluteAddress(Globals::Offsets::Exports::il2cpp_domain_get);
		il2cpp_thread_attach = (void* (*)(void*)) Utils::getAbsoluteAddress(Globals::Offsets::Exports::il2cpp_thread_attach);
		
		il2cpp_domain_assembly_open = (void* (*)(const char*)) Utils::getAbsoluteAddress(Globals::Offsets::Exports::il2cpp_domain_assembly_open);
		il2cpp_class_from_name = (void* (*)(void*, const char*, const char*)) Utils::getAbsoluteAddress(Globals::Offsets::Exports::il2cpp_class_from_name);
		il2cpp_class_get_method_from_name = (void* (*)(void*, const char*, int)) Utils::getAbsoluteAddress(Globals::Offsets::Exports::il2cpp_class_get_method_from_name);
		il2cpp_class_get_field_from_name = (void* (*)(void*, const char*)) spoof_call(Globals::Vars::Main::spoof, GetProcAddress, GameAssembly, "il2cpp_class_get_field_from_name");
		il2cpp_field_get_value_object = (void* (*)(void*, void*)) spoof_call(Globals::Vars::Main::spoof, GetProcAddress, GameAssembly, "il2cpp_field_get_value_object");
		il2cpp_class_get_methods = (void* (*)(void*, void**)) spoof_call(Globals::Vars::Main::spoof, GetProcAddress, GameAssembly, "il2cpp_class_get_methods");
		il2cpp_object_get_class = (void* (*)(void*)) spoof_call(Globals::Vars::Main::spoof, GetProcAddress, GameAssembly, "il2cpp_object_get_class");

		il2cpp_class_get_name = (const char* (*)(void*)) spoof_call(Globals::Vars::Main::spoof, GetProcAddress, GameAssembly, "il2cpp_class_get_name");
		il2cpp_class_get_parent = (void* (*)(void*)) spoof_call(Globals::Vars::Main::spoof, GetProcAddress, GameAssembly, "il2cpp_class_get_parent");
		il2cpp_method_get_name = (const char* (*)(void*)) spoof_call(Globals::Vars::Main::spoof, GetProcAddress, GameAssembly, "il2cpp_method_get_name");
		il2cpp_method_get_param_count = (uint32_t(*)(void*)) spoof_call(Globals::Vars::Main::spoof, GetProcAddress, GameAssembly, "il2cpp_method_get_param_count");
		il2cpp_method_get_param = (void* (*)(void*, uint32_t)) spoof_call(Globals::Vars::Main::spoof, GetProcAddress, GameAssembly, "il2cpp_method_get_param");
		il2cpp_method_get_param_name = (const char* (*)(void*, uint32_t)) spoof_call(Globals::Vars::Main::spoof, GetProcAddress, GameAssembly, "il2cpp_method_get_param_name");
		il2cpp_type_get_name = (char* (*)(void*)) spoof_call(Globals::Vars::Main::spoof, GetProcAddress, GameAssembly, "il2cpp_type_get_name");

		il2cpp_runtime_invoke = (void* (*)(void*, void*, void**, void**)) Utils::getAbsoluteAddress(Globals::Offsets::Exports::il2cpp_runtime_invoke);
		il2cpp_object_unbox = (void* (*)(void*)) spoof_call(Globals::Vars::Main::spoof, GetProcAddress, GameAssembly, "il2cpp_object_unbox");
	
		il2cpp_string_new = (Structs::Mono::String * (*)(const char*)) spoof_call(Globals::Vars::Main::spoof, GetProcAddress, GameAssembly, "il2cpp_string_new");
		il2cpp_object_new = (void* (*)(void*))  spoof_call(Globals::Vars::Main::spoof, GetProcAddress, GameAssembly, "il2cpp_object_new");
		il2cpp_array_new = (Structs::IL2CPP::Il2CppArray * (*)(void*, size_t))  spoof_call(Globals::Vars::Main::spoof, GetProcAddress, GameAssembly, "il2cpp_array_new");
		il2cpp_value_box = (void* (*)(void*, void*))  spoof_call(Globals::Vars::Main::spoof, GetProcAddress, GameAssembly, "il2cpp_value_box");
	}
}