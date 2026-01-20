#pragma once
#include "Includes.h"

namespace SDK::Pointers::Game {
	struct U_Tool {
		IL2CPP::Backends::Class klass;
		//Il2CppString* IGPJNKHJNON, UnityEngine::Vector3 EMECBHNHILC, UnityEngine::Quaternion NOLDGDLLBBL, float AMJKMJIBGNI, int32_t MHJNMPOABCE, PIFBFEKACLF HLGNKBGDBOL
		IL2CPP::Backends::Method<void*> PhotonInstantiateForRoom;

		void Setup();
	};
	extern U_Tool Tool;
}