#include "Vars.h"

namespace Globals::Vars
{
	//Main
	namespace Main
	{
		std::string buildCode;
		void* spoof;
		void* unitySpoof;
	}
	//Player & Movement
	namespace Player
	{
		bool forceMpScale;
		namespace Var
		{
			float headScale;
		}
	}
	namespace Movement
	{
		bool dynamicFly = true, hybridMovement, staticFly, walkspeedChanger, jumpHeightChanger;
		namespace Var
		{
			float walkspeedAmount, jumpHeightAmount;
		}
	}
	//Misc
	namespace Misc
	{
		bool trialClothing = true, freeRoomKeys = true, fakeDeveloper = true, alwaysAllowBackpackTools = true, orientationSkip = true, questRoomSkip = true, questAiSkip = true, antiQuit;
	}
	//Network
	namespace Network
	{
		bool playerSelector = true, loopGrantMaster = true, playerVanish, nsKiller;
	}
	//Combat
	namespace Combat
	{
		bool questInvincibility, pvpGodMode, basicRapidFire = true, infiniteAmmo = true, noRecoil = true, noSpread = true, bulletSpeedModifier, loopFire = true, useBinding = true, bulletMultiplier;
		namespace Var
		{
			float bulletSpeed;
			int bulletAmount = 1;
		}
	}
	//Combat Aimbot
	namespace Aimbot
	{
		bool enableAimbot, enableSilentAimbot, useFovCircle;
		bool renderFovCircle, overrideAimStrength, overrideSilentAimStrictness;
		bool headLock = true, bodyLock;
		bool teamCheck, healthCheck;
		bool bhop, spinbot;

		namespace Var
		{
			float circleSize, aimStrength, silentAimRangeStrictness, hitboxSize;
		}
	}
	//Spawnables
	namespace Spawnables
	{
		//Foodsploit
		bool foodsploit, newFoodBypassToggle, customFoodPosition, customFoodRotation, customFoodAmount, customFoodScale, customFoodGuid;
		//Asset Spawn
		bool customAssetPosition, customAssetRotation, customAssetAmount, customAssetScale, noAssetRender;
		//Overriders
		bool foodOverrideSpawn, takePhotoSpawn = true, printPhotoSpawn, shareButtonSpawn = true;
		namespace Var
		{
			//Foodsploit
			SDK::Structs::Unity::Vector3 foodPosition;
			SDK::Structs::Unity::Quaternion foodRotation;
			int foodAmount = 1;
			float foodScale;
			//Asset Spawn
			SDK::Structs::Unity::Vector3 assetPosition;
			SDK::Structs::Unity::Quaternion assetRotation;
			int assetAmount = 1;
			SDK::Structs::Unity::Vector3 assetScale = SDK::Structs::Unity::Vector3(1, 1, 1);
		}
	}
	//Visuals
	namespace Visuals
	{
		bool enableEsp = true;
		bool lines, useBody, topScreen, names = true, skeletons, boxes = true, outlines, filledBoxes = true, cornerBoxes;
		bool healthCheck, teamCheck, renderTeammates;
		bool rainbowColors, customLineColor, customNameColor, customSkeletonColor, customBoxColor;
		bool basicBoxChams;
		namespace Var
		{
			float outlineThickness = 1.0f;
			SDK::Structs::Unity::Vector3 boxFix;
			SDK::Structs::Unity::Vector3 textFix = { 0, 0, 0 };

			ImVec4 rainbowColor, lineColor, nameColor, skeletonColor, boxColor;
		}
	}
	//Visuals (VR)
	namespace VisualsVR
	{
		bool lineStateChanged, simpleLines;

		bool rainbowColors, customLineColor;
		namespace Var
		{
			ImVec4 rainbowColor, lineColor;
		}
	}
	//Player List (Puppets)
	namespace PlayerList
	{
		//Game Exploits
		bool loopFire, kill, restoreHealth, invincibility;
		//Basic Exploits
		bool stealPv, restorePv, spawnAsset, forceHoldAsset;
		//RPC Exploits
		bool bring, bringToPlayer, bringAllToPlayer, voidPlayer, infinityToggle, spawn, despawn, ramCrash, bulletRamCrash, spawnRamCrash;
		bool broadcastFakeVotekick;
		//Loop RPC Exploits
		bool spin, orbit, orbitAroundPlayer;

		namespace Var
		{
			//Game Exploits
			float invincibilityDuration;
		}
	}
	namespace PlayerBlacklisted
	{
		bool autoRamCrashBlacklisted, cheerCrash, bulletCrash;
	}
	//Lobby!
	namespace Lobby
	{
		bool deleteMap;
		bool killAll, restoreHealthAll;
		bool spawnAssetAll, forceHoldAll;
		bool bringAll, bringAllToPlayer, voidAll;
	}
	//Unity
	namespace Unity
	{
		bool fovSlider = true, timescaleSlider;
		namespace Var
		{
			float fovAmount = 115.0f, timescaleAmount = 1.0f;
		}
	}
	//API
	namespace API
	{
		bool leaf = true, clothingOverride = true, skinsOverride = true, consumablesOverride = true, currencyOverride = true, fakeRRPlus = true, fakeLevel, rolesOverride = true, giftOverride, uriLogger;
	}
}


namespace Globals::Vars::Loggers
{
	std::vector<std::string> uriLogs;
}


namespace Globals::Vars::GUI
{
	namespace Themes
	{
		bool midnight = true;
	}
	namespace Watermark
	{
		bool renderWatermark = true, renderFPS = true;
	}
	namespace Windows
	{
		bool foodsploitWindow, assetSpawnWindow = true, playerListWindow = true, playerBlacklistWindow = true, lobbyPanelWindow;
	}
}
