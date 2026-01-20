#pragma once
#include "RR_Includes.h"
#include "RR_System.h"


namespace SDK::RR::Base {
	struct Object {

		template <typename T>

		static T Instantiate(T original) {
			void* args[1] = { original };
			return (T)Pointers::Unity::Object.Instantiate.Invoke(args).Get();
		}

		Structs::Mono::String* get_name();
		static void Destroy(Object* obj);

		template <typename T>
		static Structs::Mono::Array<T*>* FindObjectsOfType(System::Type* type, bool includeInactive = false) {
			void* args[2] = { type, &includeInactive };
			return (Structs::Mono::Array<T*>*)Pointers::Unity::Object.FindObjectsOfType.Invoke(args).Get();
		}
	};

	struct Component : Object {
		Unity::Transform* get_transform();
		Unity::GameObject* get_gameObject();

		template <typename T>
		T GetComponent(System::Type* type) {
			void* args[1] = { type };
			return (T)Pointers::Unity::Component.GetComponent[this].Invoke(args).Get();
		}
	};


	struct Behaviour : Component {};
	struct MonoBehaviour : Behaviour {};
}
