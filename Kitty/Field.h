#pragma once
#include "Exports.h"
#include "IL2CPPUtils.h"

namespace SDK::IL2CPP::Backends {
	template <typename T>
	class Field {
	private:
		void* field{};
		void* object{};
		SDK::Structs::IL2CPP::Il2CppObject* result{};
	public:
		Field() = default;
		Field(void* field) : field(field) {}

		Field& operator[](void* instance) {
			object = instance;
			return *this;
		}

		Field& Retrieve() {
			result = (SDK::Structs::IL2CPP::Il2CppObject*)Pointers::Exports::Exports.il2cpp_field_get_value_object(field, object);
			return *this;
		}

		T Get() {
			return (T)result;
		}

		T Unbox() {
			return *(T*)result->Unbox();
		}
	};
}