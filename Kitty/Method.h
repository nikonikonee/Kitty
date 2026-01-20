#pragma once
#include "Exports.h"
#include "IL2CPPUtils.h"
#include "Il2CppMethod.h"

namespace SDK::IL2CPP::Backends {
	template <typename T>
	class Method {
	private:
		Structs::IL2CPP::Il2CppMethod* method{};
		void* object{};
		Structs::IL2CPP::Il2CppObject* result{};
	public:
		Method() = default;
		//Create Method From pointer
		Method(Structs::IL2CPP::Il2CppMethod* method) : method(method) {}
		//Pass Object Optionally Through [] operator
		Method& operator[](void* object) {
			this->object = object;
			return *this;
		}
		//Invoke Method & Store Result
		Method& Invoke(void** args = nullptr) {
			result = method->RuntimeInvoke(object, args, nullptr);
			return *this;
		}

		T Get() { return (T)result; }
		T Unbox() { return *(T*)result->Unbox(); }
	};
}