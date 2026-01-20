#include "RR_System.h"

namespace SDK::RR::System {
	Type* Type::GetType(const char* typeName) {
		auto typeNameString = IL2CPP::Utils::il2cpp_string_new(typeName);
		void* args[1] = { typeNameString };
		return (Type*)Pointers::System::Type.GetType.Invoke(args).Get();
	}
}

namespace SDK::RR::System {
	Uri* Uri::ctor(const char* uriString) {
		auto uriObject = Pointers::System::Uri.klass.New();
		if (uriObject) {
			auto createdUriString = IL2CPP::Utils::il2cpp_string_new(uriString);
			void* args[1] = { createdUriString };

			Pointers::System::Uri.ctor[uriObject].Invoke(args);
			return (Uri*)uriObject;
		}
	}

	Structs::Mono::String* Uri::ToString() { return Pointers::System::Uri.ToString[this].Invoke().Get(); }
}

namespace SDK::RR::System {
	Structs::Mono::Array<uint8_t**>* File::ReadAllBytes(const char* filePath) {
		auto filePathString = IL2CPP::Utils::il2cpp_string_new(filePath);
		void* args[1] = { filePathString };
		return Pointers::System::File.ReadAllBytes.Invoke(args).Get();
	}
}