#include "Uri.h"

namespace SDK::Pointers::System {
	U_Uri Uri;

	void U_Uri::Setup() {
		klass = IL2CPP::Backends::Class("System", "System", "Uri");

		ctor = klass.GetMethod(".ctor", 1);
		ToString = klass.GetMethod("ToString", 0);
	}
}