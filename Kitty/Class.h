#pragma once
#include "IL2CPPUtils.h"
#include "Il2CppClass.h"

namespace SDK::IL2CPP::Backends {
	class Class {
	private:
		Structs::IL2CPP::Il2CppClass* pClass{};
	public:
		Class() = default;

		//Create Class From Ptr
		Class(Structs::IL2CPP::Il2CppClass* pClass) : pClass(pClass) {}

		//Create Class From void ptr
		Class(void* pClass) : pClass((Structs::IL2CPP::Il2CppClass*)pClass) {}

		//Create Class From Exports
		Class(const char* image, const char* nameSpace, const char* klass) {
			if (strcmp(image, "") == 0)
				image = "Assembly-CSharp";

			this->pClass = IL2CPP::Utils::GetClass(image, nameSpace, klass);
		}

		//Retrieve Pointer
		Structs::IL2CPP::Il2CppClass* Get() { return pClass; };

		//Retrieve Parent
		Structs::IL2CPP::Il2CppClass* Parent() { return (Structs::IL2CPP::Il2CppClass*)Pointers::Exports::Exports.il2cpp_class_get_parent(pClass); }

		//Check If Class is nullptr
		bool IsValid() const { return (pClass != nullptr); }

		//Create new object from class
		void* New() { return IsValid() ? Pointers::Exports::Exports.il2cpp_object_new(pClass) : nullptr; }

		//Retrieve method from class
		Structs::IL2CPP::Il2CppMethod* GetMethod(const char* methodName, int args) { return IsValid() ? IL2CPP::Utils::GetMethodFromClass(pClass, methodName, args) : nullptr; }
		//Retrieve field from class
		void* GetField(const char* name) { return IsValid() ? IL2CPP::Utils::GetFieldFromClass(pClass, name) : nullptr; }
		//Retrieve specific method from class
		Structs::IL2CPP::Il2CppMethod* GetSpecificMethod(const char* methodName, int args, const char* parameterTypeName) { return IsValid() ? IL2CPP::Utils::GetSpecificMethodFromClass(pClass, methodName, args, parameterTypeName) : nullptr; }
		//Retrieve methodptr from class
		void* GetMethodPtr(const char* methodName, int args) { return IsValid() ? IL2CPP::Utils::GetMethodFromClass(pClass, methodName, args)->MethodPtr() : nullptr; }
	};
}