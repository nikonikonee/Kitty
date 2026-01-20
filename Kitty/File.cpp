#include "File.h"

namespace SDK::Pointers::System {
	U_File File;

	void U_File::Setup() {
		klass = IL2CPP::Backends::Class("mscorlib", "System.IO", "File");

		ReadAllBytes = klass.GetMethod("ReadAllBytes", 1);
	}
}