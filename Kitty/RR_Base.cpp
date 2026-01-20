#include "RR_Base.h"

namespace SDK::RR::Base {
	Structs::Mono::String* Object::get_name() { return Pointers::Unity::Object.get_name[this].Invoke().Get(); }
	
	void Object::Destroy(Object* obj) {
		void* args[1] = { obj };
		Pointers::Unity::Object.Destroy.Invoke(args);
	}
}

namespace SDK::RR::Base {
	Unity::Transform* Component::get_transform() { return (Unity::Transform*)Pointers::Unity::Component.get_transform[this].Invoke().Get(); }
	Unity::GameObject* Component::get_gameObject() { return (Unity::GameObject*)Pointers::Unity::Component.get_gameObject[this].Invoke().Get(); }
}