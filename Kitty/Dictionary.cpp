#include "pDictionary.h"

namespace SDK::Pointers::System {
	U_Dictionary Dictionary;

	void U_Dictionary::Setup() {
		klass = IL2CPP::Backends::Class("mscorlib", "System.Collections.Generic", "Dictionary");

		get_Count = klass.GetMethod("get_Count", 0);
		get_Keys = klass.GetMethod("get_Keys", 0);
		get_Values = klass.GetMethod("get_Values", 0);
	}
}