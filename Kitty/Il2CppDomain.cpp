#include "Il2CppDomain.h"
#include "IL2CPPUtils.h"
#include "RetSpoofer/RetSpoofer.hpp"

namespace SDK::Structs::IL2CPP {
	void* Il2CppDomain::ThreadAttach() {
		return spoof_call(Globals::Vars::Main::spoof, Pointers::Exports::Exports.il2cpp_thread_attach, (void*)this);
	}
}