#include "Runtime.h"

namespace Globals::Vars::Runtime
{
	namespace List
	{
		std::vector<std::pair<void*, std::string>> tools;
		std::vector<std::pair<std::string, std::string >> foods;
		
		std::vector<std::tuple<int, std::string, void*>> boxCollections;

		namespace Selected
		{
			int food;
			int player;
		}
	}

	namespace Native
	{
		void* Object;
		void* Boolean;
		void* Int32;
		void* Single;
		void* Byte;

		void* Vector3;
		void* Quaternion;
		void* Material;
		
		//RR Special
		void* NetworkedView;
	}

	namespace Instance
	{
		void* playerSelectorTarget;

		void* target;
		void* targetSelectedPlayer;

		void* GameCombatManager;
		void* GameTeamManager;

		void* boxAssetBundle;
	}

	namespace Var
	{
		bool needsToSelectMod, needsToSelectPlayer;
		int objectOrbitAmount;
		SDK::Structs::Unity::Vector3 silentAimbotDirection;
		float objectSize;
	}
}