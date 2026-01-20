#include "Il2CppClass.h"
#include "IL2CPPUtils.h"
#include "RetSpoofer/RetSpoofer.hpp"

namespace SDK::Structs::IL2CPP {
	Il2CppMethod* Il2CppClass::GetMethod(const char* methodName, int args) {
		return (Il2CppMethod*)spoof_call(Globals::Vars::Main::spoof, Pointers::Exports::Exports.il2cpp_class_get_method_from_name, (void*)this, methodName, args);
	}
	void* Il2CppClass::GetField(const char* name) {
		return spoof_call(Globals::Vars::Main::spoof, Pointers::Exports::Exports.il2cpp_class_get_field_from_name, (void*)this, name);
	}
	Il2CppMethod* Il2CppClass::GetMethods(void** iter) {
		return (Il2CppMethod*)spoof_call(Globals::Vars::Main::spoof, Pointers::Exports::Exports.il2cpp_class_get_methods, (void*)this, iter);
	}
}