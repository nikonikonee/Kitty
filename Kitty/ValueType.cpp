#include "ValueType.h"

namespace SDK::Pointers::System {
	U_ValueType ValueType;

	void U_ValueType::Setup() {
		klass = IL2CPP::Backends::Class("mscorlib", "System", "ValueType");

		ToString = klass.GetMethod("ToString", 0);
	}
}