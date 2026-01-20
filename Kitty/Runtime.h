#pragma once
#include <iostream>
#include <vector>
#include "Quaternion.h"

namespace Globals::Vars::Runtime
{
	namespace List
	{
		extern std::vector<std::pair<void*, std::string>> tools;
		extern std::vector<std::pair<std::string, std::string >> foods;

		extern std::vector<std::tuple<int, std::string, void*>> boxCollections;

		namespace Selected
		{
			extern int food;
			extern int player;
		}
	}

	namespace Native
	{
		extern void* Object;
		extern void* Boolean;
		extern void* Int32;
		extern void* Single;
		extern void* Byte;

		extern void* Vector3;
		extern void* Quaternion;
		extern void* Material;
	
		//RR special
		extern void* NetworkedView;
	}

	namespace Instance
	{
		extern void* playerSelectorTarget;

		extern void* target; //re-cast to wtv you need ig
		extern void* targetSelectedPlayer; //re-cast to wtv :/

		extern void* GameCombatManager;
		extern void* GameTeamManager;

		extern void* boxAssetBundle;
	}

	namespace Var
	{
		extern bool needsToSelectMod, needsToSelectPlayer;
		extern int objectOrbitAmount;
		extern SDK::Structs::Unity::Vector3 silentAimbotDirection;
		extern float objectSize;
	}
}