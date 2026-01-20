#include "Camera.h"

namespace SDK::Pointers::Unity {
	U_Camera Camera;

	void U_Camera::Setup() {
		klass = IL2CPP::Backends::Class("UnityEngine.CoreModule", "UnityEngine", "Camera");

		WorldToScreenPoint = klass.GetMethod("WorldToScreenPoint", 1);
		get_allCameras = klass.GetMethod("get_allCameras", 0);
	}
}