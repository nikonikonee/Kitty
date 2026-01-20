#include "Misc.h"
#include "Logger.h"

bool (*old_IsTrialItem)(void* instance, void* avatar, bool wtv);
bool IsTrialItem(void* instance, void* avatar, bool wtv) {
	if (instance && Globals::Vars::Misc::trialClothing)
		return false;
	return old_IsTrialItem(instance, avatar, wtv);
}

bool (*old_DoesLocalPlayerOwnKeyG)(void* instance, void* guid);
bool DoesLocalPlayerOwnKeyG(void* instance, void* guid) {
	if (instance && Globals::Vars::Misc::freeRoomKeys)
		return true;
	return old_DoesLocalPlayerOwnKeyG(instance, guid);
}

bool (*old_DoesLocalPlayerOwnKeyL)(void* instance, void* int64);
bool DoesLocalPlayerOwnKeyL(void* instance, void* int64) {
	if (instance && Globals::Vars::Misc::freeRoomKeys)
		return true;
	return old_DoesLocalPlayerOwnKeyL(instance, int64);
}

bool (*old_IsSelfScaling)(void* instance);
bool IsSelfScaling(void* instance) {
	if (instance && Globals::Vars::Player::forceMpScale)
		return true;
	return old_IsSelfScaling(instance);
}

bool (*old_IsDeveloper)();
bool IsDeveloper() {
	if (Globals::Vars::Misc::fakeDeveloper)
		return true;
	return old_IsDeveloper();
}

bool (*old_LocalAccountIsDeveloper)(void* instance);
bool LocalAccountIsDeveloper(void* instance) {
	if (instance && Globals::Vars::Misc::fakeDeveloper)
		return true;
	return old_LocalAccountIsDeveloper(instance);
}

bool (*old_LocalAccountIsModerator)(void* instance);
bool LocalAccountIsModerator(void* instance) {
	if (instance && Globals::Vars::Misc::fakeDeveloper)
		return true;
	return old_LocalAccountIsModerator(instance);
}

bool (*old_CanLocalPlayerEnableTool)(void* ptr, bool wtv);
bool CanLocalPlayerEnableTool(void* ptr, bool wtv) {
	if (Globals::Vars::Misc::alwaysAllowBackpackTools)
		return true;
	return old_CanLocalPlayerEnableTool(ptr, wtv);
}

bool (*old_HasCompletedOrientation)(void* instance);
bool HasCompletedOrientation(void* instance) {
	if (instance && Globals::Vars::Misc::orientationSkip)
		return true;
	return old_HasCompletedOrientation(instance);
}

bool (*old_HasRecievedWatch)(void* instance);
bool HasRecievedWatch(void* instance) {
	if (instance && Globals::Vars::Misc::orientationSkip)
		return true;
	return old_HasRecievedWatch(instance);
}

bool (*old_OrientationIsFinished)(void* instance);
bool OrientationIsFinished(void* instance) {
	if (instance && Globals::Vars::Misc::orientationSkip)
		return true;
	return old_OrientationIsFinished(instance);
}

int (*old_GetNextGameplayRoomIndex)(void* instance);
int GetNextGameplayRoomIndex(void* instance) {
	if (instance && Globals::Vars::Misc::questRoomSkip) {
		int roomCount = *(int*)((uint64_t)instance + 0x150);
		
		if (old_GetNextGameplayRoomIndex(instance) < roomCount)
			roomCount -= 1;

		return roomCount;
	}
	return old_GetNextGameplayRoomIndex(instance);
}

bool (*old_EncounterIsFinished)(void* instance);
bool EncounterIsFinished(void* instance) {
	if (instance && Globals::Vars::Misc::questAiSkip)
		return true;
	return old_EncounterIsFinished(instance);
}

void (*old_TryApplicationQuit)();
void TryApplicationQuit() {
	if (Globals::Vars::Misc::antiQuit)
		return;
	return old_TryApplicationQuit();
}

void (*old_TryApplicationQuitInt)(int code);
void TryApplicationQuitInt(int code) {
	if (Globals::Vars::Misc::antiQuit)
		return;
	return old_TryApplicationQuitInt(code);
}

void (*old_FatalApplicationQuit)(int code, void* reason);
void FatalApplicationQuit(int code, void* reason) {
	if (Globals::Vars::Misc::antiQuit)
		return;
	return old_FatalApplicationQuit(code, reason);
}

void (*old_LogoutToBootScene)();
void LogoutToBootScene() {
	if (Globals::Vars::Misc::antiQuit)
		return;
	return old_LogoutToBootScene();
}

void (*old_LogoutToBootSceneAsync)();
void LogoutToBootSceneAsync() {
	if (Globals::Vars::Misc::antiQuit)
		return;
	return old_LogoutToBootSceneAsync();
}


void Cheats::Misc::Setup() {
	/*--- Trial Clothing ----*/
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "RecRoom.Avatars.Outfit", "OutfitManager", "IsTrialItem", 2), &IsTrialItem, (void**)&old_IsTrialItem);
	/*---- Free Room Keys ----*/
	Utils::Hook(SDK::IL2CPP::Utils::GetSpecificMethodPtr("", "RecRoom.Systems.Economy.RoomKeys", "RoomKeysManager", "DoesLocalPlayerOwnKey", 1, "System.Guid"), &DoesLocalPlayerOwnKeyG, (void**)&old_DoesLocalPlayerOwnKeyG);
	Utils::Hook(SDK::IL2CPP::Utils::GetSpecificMethodPtr("", "RecRoom.Systems.Economy.RoomKeys", "RoomKeysManager", "DoesLocalPlayerOwnKey", 1, "System.Int64"), &DoesLocalPlayerOwnKeyL, (void**)&old_DoesLocalPlayerOwnKeyL);
	/*---- Force MP Scale ----*/
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "", "Player", "get_IsSelfScaling", 0), &IsSelfScaling, (void**)&old_IsSelfScaling);
	/*---- Fake Developer ----*/
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "", "SessionManager", "get_IsDeveloper", 0), &IsDeveloper, (void**)&old_IsDeveloper);
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "RRUI.Data", "GlobalModel", "get_LocalAccountIsDeveloper", 0), &LocalAccountIsDeveloper, (void**)&old_LocalAccountIsDeveloper);
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "RRUI.Data", "GlobalModel", "get_LocalAccountIsModerator", 0), &LocalAccountIsModerator, (void**)&old_LocalAccountIsModerator);
	/*---- Always Allow Backpack Tools ----*/
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "RecRoom.Players", "PlayerBackpack", "CanLocalPlayerEnableTool", 2), &CanLocalPlayerEnableTool, (void**)&old_CanLocalPlayerEnableTool);
	/*---- Orientation Skip ----*/
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "", "TutorialManager", "get_HasCompletedOrientation", 0), &HasCompletedOrientation, (void**)&old_HasCompletedOrientation);
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "", "TutorialManager", "get_HasReceivedWatch", 0), &HasRecievedWatch, (void**)&old_HasRecievedWatch);
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "RecRoom.Activities.Orientation", "OrientationSubScene", "get_IsFinished", 0), &OrientationIsFinished, (void**)&old_OrientationIsFinished);
	/*---- Quest Room Skip ----*/
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "RecRoom.Activities.Quest", "QuestManager", "KCBEPHBHKBL", 0), &GetNextGameplayRoomIndex, (void**)&old_GetNextGameplayRoomIndex);
	/*---- Quest AI Skip ----*/
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "RecRoom.Core.Encounters", "GameEncounter", "get_IsFinished", 0), &EncounterIsFinished, (void**)&old_EncounterIsFinished);
	/*---- Anti Quit ----*/
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "", "SessionManager", "TryApplicationQuit", 0), &TryApplicationQuit, (void**)&old_TryApplicationQuit);
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "", "SessionManager", "TryApplicationQuit", 1), &TryApplicationQuitInt, (void**)&old_TryApplicationQuitInt);
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "", "SessionManager", "FatalApplicationQuit", 2), &FatalApplicationQuit, (void**)&old_FatalApplicationQuit);
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "", "SessionManager", "LogoutToBootScene", 0), &LogoutToBootScene, (void**)&old_LogoutToBootScene);
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "", "SessionManager", "LogoutToBootSceneAsync", 0), &LogoutToBootSceneAsync, (void**)&old_LogoutToBootSceneAsync);
	Logger::Log(clr::magenta, "[Cheat] Setup: [Misc]");
}