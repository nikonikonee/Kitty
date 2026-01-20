#include "ImageConversion.h"

namespace SDK::Pointers::Unity {
	U_ImageConversion ImageConversion;

	void U_ImageConversion::Setup() {
		klass = IL2CPP::Backends::Class("UnityEngine.ImageConversionModule", "UnityEngine", "ImageConversion");

		LoadImageTex = klass.GetMethod("LoadImage", 2);
	}
}