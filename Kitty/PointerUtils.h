#pragma once
#include "imgui.h"
#include "PointerIncludes.h"


namespace SDK::Pointers::Utils
{
	//Visual
	extern void* getCamera(int index);
	extern SDK::Structs::Unity::Vector3 WorldToScreenPoint(void* camera, SDK::Structs::Unity::Vector3 position);
}