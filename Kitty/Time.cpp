#include "Time.h"

namespace SDK::Pointers::Unity {
	U_Time Time;

	void U_Time::Setup() {
		klass = IL2CPP::Backends::Class("UnityEngine.CoreModule", "UnityEngine", "Time");

		get_time = (float(*)()) Utils::getAbsoluteAddress(0x99B7750);
		get_deltaTime = klass.GetMethod("get_deltaTime", 0);
		set_timeScale = klass.GetMethod("set_timeScale", 1);
	}
}