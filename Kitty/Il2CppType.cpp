#include "Il2CppType.h"
#include "Exports.h"
#include "RetSpoofer/RetSpoofer.hpp"

namespace SDK::Structs::IL2CPP {
	char* Il2CppType::GetName() {
		return spoof_call(Globals::Vars::Main::spoof, Pointers::Exports::Exports.il2cpp_type_get_name, (void*)this);
	}
}