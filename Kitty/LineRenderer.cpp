#include "LineRenderer.h"

namespace SDK::Pointers::Unity {
	U_LineRenderer LineRenderer;

	void U_LineRenderer::Setup() {
		klass = IL2CPP::Backends::Class("UnityEngine.CoreModule", "UnityEngine", "LineRenderer");

		set_startWidth = klass.GetMethod("set_startWidth", 1);
		set_endWidth = klass.GetMethod("set_endWidth", 1);

		set_useWorldSpace = klass.GetMethod("set_useWorldSpace", 1);

		set_startColor = klass.GetMethod("set_startColor", 1);
		set_endColor = klass.GetMethod("set_endColor", 1);
	
		set_positionCount = klass.GetMethod("set_positionCount", 1);

		SetPosition = klass.GetMethod("SetPosition", 2);
	}
}