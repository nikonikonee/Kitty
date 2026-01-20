#include "IL2CPPUtils.h"
#include "Logger.h"
#include "RetSpoofer/RetSpoofer.hpp"

SDK::Structs::IL2CPP::Il2CppDomain* SDK::IL2CPP::Utils::il2cpp_domain_get()
{
	return (SDK::Structs::IL2CPP::Il2CppDomain*)spoof_call(Globals::Vars::Main::unitySpoof, SDK::Pointers::Exports::Exports.il2cpp_domain_get);
}

void* SDK::IL2CPP::Utils::il2cpp_runtime_invoke(void* method, void* object, void** args, void** exc)
{
	return spoof_call(Globals::Vars::Main::unitySpoof, SDK::Pointers::Exports::Exports.il2cpp_runtime_invoke, method, object, args, exc);
}

void* SDK::IL2CPP::Utils::il2cpp_object_unbox(void* object)
{
	return spoof_call(Globals::Vars::Main::unitySpoof, SDK::Pointers::Exports::Exports.il2cpp_object_unbox, object);
}

void* SDK::IL2CPP::Utils::il2cpp_object_new(void* klass)
{
	return spoof_call(Globals::Vars::Main::unitySpoof, SDK::Pointers::Exports::Exports.il2cpp_object_new, klass);
}

SDK::Structs::Mono::String* SDK::IL2CPP::Utils::il2cpp_string_new(const char* str)
{
	return spoof_call(Globals::Vars::Main::unitySpoof, SDK::Pointers::Exports::Exports.il2cpp_string_new, str);
}

SDK::Structs::IL2CPP::Il2CppClass* SDK::IL2CPP::Utils::GetClass(const char* image, const char* nameSpace, const char* klass) {
	if (strcmp(image, "") == 0)
		image = "Assembly-CSharp";
	void* assembly = spoof_call(Globals::Vars::Main::spoof, Pointers::Exports::Exports.il2cpp_domain_assembly_open, image);
	if (assembly) {
		void* pImage = *(void**)((uint64_t)assembly + 0x0);
		if (pImage) {
			void* pKlass = spoof_call(Globals::Vars::Main::spoof, Pointers::Exports::Exports.il2cpp_class_from_name, pImage, nameSpace, klass);
			if (pKlass) {
				//Logger::Log(clr::green, "[%s] pKlass: [%p]", klass, pKlass);
				return (SDK::Structs::IL2CPP::Il2CppClass*)pKlass;
			}
		}
	}
	return nullptr;
}

SDK::Structs::IL2CPP::Il2CppMethod* SDK::IL2CPP::Utils::GetMethod(const char* image, const char* nameSpace, const char* klass, const char* methodName, int args) {
	if (strcmp(image, "") == 0)
		image = "Assembly-CSharp";

	auto pKlass = GetClass(image, nameSpace, klass);
	if (pKlass) {
		auto pMethod = GetMethodFromClass(pKlass, methodName, args);
		if (pMethod) {
			//Logger::Log(clr::green, "[%s] pMethod: [%p]", methodName, pMethod);
			return pMethod;
		}
	}
	return nullptr;
}

SDK::Structs::IL2CPP::Il2CppMethod* SDK::IL2CPP::Utils::GetSpecificMethod(const char* image, const char* nameSpace, const char* klass, const char* methodName, int args, const char* parameterTypeName) {
	auto pKlass = GetClass(image, nameSpace, klass);
	if (pKlass) {
		void* iter = nullptr;
		while (auto method = pKlass->GetMethods(&iter)) {
			if (strcmp(method->GetName(), methodName) == 0) {
				for (uint32_t i = 0; i < method->GetParamCount(); ++i) {
					auto paramter = method->GetParam(i);
					if (!paramter)
						continue;
					if (strcmp(paramter->GetName(), parameterTypeName) == 0) {
						Logger::Log(clr::green, "[%s | %s] specificMethod: [%p]", methodName, paramter->GetName(), method);
						return method;
					}
				}
			}
		}
	}
	return nullptr;
}

void* SDK::IL2CPP::Utils::GetMethodPtr(const char* image, const char* nameSpace, const char* klass, const char* methodName, int args) {
	if (strcmp(image, "") == 0)
		image = "Assembly-CSharp";

	auto pKlass = GetClass(image, nameSpace, klass);
	if (pKlass) {
		auto pMethod = pKlass->GetMethod(methodName, args);
		if (pMethod) {
			auto pMethodPtr = pMethod->MethodPtr();
			if (pMethodPtr) {
				Logger::Log(clr::green, "[%s] pMethodPtr: [%p]", methodName, pMethodPtr);
				return pMethodPtr;
			}
		}
	}

	return nullptr;
}


void* SDK::IL2CPP::Utils::GetSpecificMethodPtr(const char* image, const char* nameSpace, const char* klass, const char* methodName, int args, const char* parameterTypeName) {
	auto pKlass = GetClass(image, nameSpace, klass);
	if (pKlass) {
		void* iter = nullptr;
		while (auto method = pKlass->GetMethods(&iter)) {
			if (strcmp(method->GetName(), methodName) == 0) {
				for (uint32_t i = 0; i < method->GetParamCount(); ++i) {
					auto parameter = method->GetParam(i);
					if (!parameter)
						continue;
					if (strcmp(parameter->GetName(), parameterTypeName) == 0) {
						auto methodPtr = method->MethodPtr();
						if (methodPtr) {
							Logger::Log(clr::green, "[%s | %s] specificMethodPtr: [%p]", methodName, parameter->GetName(), methodPtr);
							return methodPtr;
						}
					}
				}
			}
		}
	}
	return nullptr;
}


SDK::Structs::IL2CPP::Il2CppMethod* SDK::IL2CPP::Utils::GetMethodFromClass(Structs::IL2CPP::Il2CppClass* klass, const char* methodName, int args) {
	if (klass) {
		auto pMethod = klass->GetMethod(methodName, args);
		if (pMethod) {
			Logger::Log(clr::green, "[%s] pMethodFromKlass: [%p]", methodName, pMethod);
			return pMethod;
		}
	}
	return nullptr;
}

void* SDK::IL2CPP::Utils::GetFieldFromClass(Structs::IL2CPP::Il2CppClass* klass, const char* name) {
	if (klass) {
		auto pField = klass->GetField(name);
		if (pField) {
			Logger::Log(clr::gray, "[%s] pField: [%p]", name, pField);
			return pField;
		}
	}
	return nullptr;
}

SDK::Structs::IL2CPP::Il2CppMethod* SDK::IL2CPP::Utils::GetSpecificMethodFromClass(Structs::IL2CPP::Il2CppClass* klass, const char* methodName, int args, const char* parameterTypeName) {
	if (klass) {
		void* iter = nullptr;
		while (auto method = klass->GetMethods(&iter)) {
			if (strcmp(method->GetName(), methodName) == 0) {
				for (uint32_t i = 0; i < method->GetParamCount(); ++i) {
					auto parameter = method->GetParam(i);
					if (!parameter)
						continue;
					if (strcmp(parameter->GetName(), parameterTypeName) == 0) {
						Logger::Log(clr::darkgray, "[%s | %s] specificMethodFromKlass: [%p]", methodName, parameter->GetName(), method);
						return method;
					}
				}
			}
		}
	}
	return nullptr;
}