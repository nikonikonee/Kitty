#pragma once
#include "RR_Includes.h"

namespace SDK::RR::System {
	struct Type {
		static Type* GetType(const char* typeName);
	};

	struct Uri {
		static Uri* ctor(const char* uriString);
		Structs::Mono::String* ToString();
	};

	struct File {
		static Structs::Mono::Array<uint8_t**>* ReadAllBytes(const char* filePath);
	};
}