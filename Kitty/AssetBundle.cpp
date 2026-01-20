#include "AssetBundle.h"

namespace SDK::Pointers::Unity {
	U_AssetBundle AssetBundle;

	void U_AssetBundle::Setup() {
		klass = IL2CPP::Backends::Class("UnityEngine.AssetBundleModule", "UnityEngine", "AssetBundle");

		LoadFromFile = klass.GetMethod("LoadFromFile", 1);
		LoadAsset = klass.GetSpecificMethod("LoadAsset", 1, "System.String");
		LoadAllAssets = klass.GetMethod("LoadAllAssets", 1);
	}
}