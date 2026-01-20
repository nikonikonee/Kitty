#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "imgui.h"
#include "Quaternion.h"


namespace Globals::Vars
{

	namespace Main
	{
		extern std::string buildCode;
		extern void* spoof;
		extern void* unitySpoof;
	}

	namespace Player
	{
		extern bool forceMpScale;
		namespace Var
		{
			extern float headScale;
		}
	}
	namespace Movement
	{
		extern bool dynamicFly, hybridMovement, staticFly, walkspeedChanger, jumpHeightChanger;
		namespace Var
		{
			extern float walkspeedAmount, jumpHeightAmount;
		}
	}

	namespace Misc
	{
		extern bool trialClothing, freeRoomKeys, fakeDeveloper, alwaysAllowBackpackTools, orientationSkip, questRoomSkip, questAiSkip, antiQuit;
	}

	namespace Network
	{
		extern bool playerSelector, loopGrantMaster, playerVanish, nsKiller;
	}

	namespace Combat
	{
		extern bool questInvincibility, pvpGodMode, basicRapidFire, infiniteAmmo, noRecoil, noSpread, bulletSpeedModifier, loopFire, useBinding, bulletMultiplier;
		namespace Var
		{
			extern float bulletSpeed;
			extern int bulletAmount;
		}
	}

	namespace Aimbot
	{
		extern bool enableAimbot, enableSilentAimbot, useFovCircle;
		extern bool renderFovCircle, overrideAimStrength, overrideSilentAimStrictness;
		extern bool headLock, bodyLock;
		extern bool teamCheck, healthCheck;
		extern bool bhop, spinbot;

		namespace Var
		{
			extern float circleSize, aimStrength, silentAimRangeStrictness, hitboxSize;
		}
	}

	namespace Spawnables
	{
		//Foodsploit
		extern bool foodsploit, newFoodBypassToggle, customFoodPosition, customFoodRotation, customFoodAmount, customFoodScale, customFoodGuid;
		//Asset Spawn
		extern bool customAssetPosition, customAssetRotation, customAssetAmount, customAssetScale, noAssetRender;
		//Overriders
		extern bool foodOverrideSpawn, takePhotoSpawn, printPhotoSpawn, shareButtonSpawn;
		//Object Orbit
		extern bool spawnObjectOrbit;
		namespace Var
		{
			//Foodsploit
			extern SDK::Structs::Unity::Vector3 foodPosition;
			extern SDK::Structs::Unity::Quaternion foodRotation;
			extern int foodAmount;
			extern float foodScale;
			//Asset Spawn
			extern SDK::Structs::Unity::Vector3 assetPosition;
			extern SDK::Structs::Unity::Quaternion assetRotation;
			extern int assetAmount;
			extern SDK::Structs::Unity::Vector3 assetScale;
		}
	}

	namespace Visuals
	{
		extern bool enableEsp;
		extern bool lines, useBody, topScreen, names, skeletons, boxes, outlines, filledBoxes, cornerBoxes;
		extern bool healthCheck, teamCheck, renderTeammates;
		extern bool rainbowColors, customLineColor, customNameColor, customSkeletonColor, customBoxColor;
		namespace Var
		{
			extern float outlineThickness;
			extern SDK::Structs::Unity::Vector3 boxFix;
			extern SDK::Structs::Unity::Vector3 textFix;

			extern ImVec4 rainbowColor, lineColor, nameColor, skeletonColor, boxColor;
		}
	}
	

	namespace VisualsVR
	{
		extern bool lineStateChanged, simpleLines;

		extern bool rainbowColors, customLineColor;
		namespace Var
		{
			extern ImVec4 rainbowColor, lineColor;
		}
	}


	namespace PlayerList
	{
		//Game Exploits
		extern bool loopFire, kill, restoreHealth, invincibility;
		//Basic Exploits
		extern bool stealPv, restorePv, spawnAsset, forceHoldAsset;
		//RPC Exploits
		extern bool bring, bringToPlayer, bringAllToPlayer, voidPlayer, infinityToggle, spawn, despawn, ramCrash, bulletRamCrash, spawnRamCrash;
		extern bool broadcastFakeVotekick;
		//Loop RPC Exploits
		extern bool spin, orbit, orbitAroundPlayer;

		namespace Var
		{
			//Game Exploits
			extern float invincibilityDuration;
		}
	}
	namespace PlayerBlacklisted
	{
		extern bool autoRamCrashBlacklisted, cheerCrash, bulletCrash;
	}

	namespace Lobby
	{
		extern bool deleteMap;
		extern bool killAll, restoreHealthAll;
		extern bool spawnAssetAll, forceHoldAll;
		extern bool bringAll, bringAllToPlayer, voidAll;
	}

	namespace Unity
	{
		extern bool fovSlider, timescaleSlider;
		namespace Var
		{
			extern float fovAmount, timescaleAmount;
		}
	}

	namespace API
	{
		extern bool leaf, clothingOverride, skinsOverride, consumablesOverride, currencyOverride, fakeRRPlus, fakeLevel, rolesOverride, giftOverride, uriLogger;
	}
}


namespace Globals::Vars::Loggers
{
	extern std::vector<std::string> uriLogs;
}


namespace Globals::Vars::GUI
{
	namespace Themes
	{
		extern bool midnight;
	}
	namespace Watermark
	{
		extern bool renderWatermark, renderFPS;
	}
	namespace Windows
	{
		extern bool foodsploitWindow, assetSpawnWindow, playerListWindow, playerBlacklistWindow, lobbyPanelWindow;
	}
}
