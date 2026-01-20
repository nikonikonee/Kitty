#include "Il2CppMethod.h"
#include "IL2CPPUtils.h"
#include "RetSpoofer/RetSpoofer.hpp"

namespace SDK::Structs::IL2CPP {
	void* Il2CppMethod::MethodPtr() {
		//return ((void**)this)[0];
		return *(void**)((uint64_t)this + 0x8);
		//return ((void**)this)[0];
	}

	const char* Il2CppMethod::GetName() {
		return spoof_call(Globals::Vars::Main::spoof, Pointers::Exports::Exports.il2cpp_method_get_name, (void*)this);
	}

	uint32_t Il2CppMethod::GetParamCount() {
		return spoof_call(Globals::Vars::Main::spoof, Pointers::Exports::Exports.il2cpp_method_get_param_count, (void*)this);
	}

	Il2CppType* Il2CppMethod::GetParam(uint32_t index) {
		return (Il2CppType*)spoof_call(Globals::Vars::Main::spoof, Pointers::Exports::Exports.il2cpp_method_get_param, (void*)this, index);
	}

	Il2CppObject* Il2CppMethod::RuntimeInvoke(void* object, void** args, void** exc) {
		return (Il2CppObject*)spoof_call(Globals::Vars::Main::spoof, Pointers::Exports::Exports.il2cpp_runtime_invoke, (void*)this, object, args, exc);
	}
}