#pragma once
#include "Includes.h"

namespace SDK::Pointers::Unity {
	struct U_AssetBundle {
		IL2CPP::Backends::Class klass;

		IL2CPP::Backends::Method<void*> LoadFromFile;
		IL2CPP::Backends::Method<void*> LoadAsset;
		IL2CPP::Backends::Method<Structs::Mono::Array<void**>*> LoadAllAssets;

		void Setup();
	};
	extern U_AssetBundle AssetBundle;
}