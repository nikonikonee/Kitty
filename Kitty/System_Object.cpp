#include "System_Object.h"

namespace SDK::Pointers::System {
	U_Object Object;
	
	void U_Object::Setup() {
		klass = IL2CPP::Backends::Class("mscorlib", "System", "Object");

		ToString = klass.GetMethod("ToString", 0);
	}
}