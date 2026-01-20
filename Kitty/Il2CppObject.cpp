#include "Il2CppObject.h"
#include "IL2CPPUtils.h"
#include "RetSpoofer/RetSpoofer.hpp"

namespace SDK::Structs::IL2CPP {
	void* Il2CppObject::Unbox() {
		return spoof_call(Globals::Vars::Main::spoof, Pointers::Exports::Exports.il2cpp_object_unbox, (void*)this);
	}
}