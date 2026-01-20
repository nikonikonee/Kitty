#include "Type.h"

namespace SDK::Pointers::System {
	U_Type Type;

	void U_Type::Setup() {
		klass = IL2CPP::Backends::Class("mscorlib", "System", "Type");

		GetType = klass.GetMethod("GetType", 1);
	}
}