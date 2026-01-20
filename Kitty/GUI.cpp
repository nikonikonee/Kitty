#include "GUI.h"
#include "RetSpoofer/RetSpoofer.hpp"
#include "Vars.h"
#include <algorithm>

#undef max

inline std::string lowerCaseString(std::string& targetString) {
	std::string result = targetString;
	std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) {return std::tolower(c);});
	return result;
}

void Render::GUI::RainbowManager() {
	auto isFrames = ImGui::GetFrameCount();
	static float isRed = 0.0f, isGreen = 0.01f, isBlue = 0.0f;
	if (isFrames % 1 == 0)
	{
		if (isGreen == 0.01f && isBlue == 0.0f)
		{
			isRed += 0.01f;

		}
		if (isRed > 0.99f && isBlue == 0.0f)
		{
			isRed = 1.0f;

			isGreen += 0.01f;

		}
		if (isGreen > 0.99f && isBlue == 0.0f)
		{
			isGreen = 1.0f;

			isRed -= 0.01f;

		}
		if (isRed < 0.01f && isGreen == 1.0f)
		{
			isRed = 0.0f;

			isBlue += 0.01f;

		}
		if (isBlue > 0.99f && isRed == 0.0f)
		{
			isBlue = 1.0f;

			isGreen -= 0.01f;

		}
		if (isGreen < 0.01f && isBlue == 1.0f)
		{
			isGreen = 0.0f;

			isRed += 0.01f;

		}
		if (isRed > 0.99f && isGreen == 0.0f)
		{
			isRed = 1.0f;

			isBlue -= 0.01f;

		}
		if (isBlue < 0.01f && isGreen == 0.0f)
		{
			isBlue = 0.0f;

			isRed -= 0.01f;

			if (isRed < 0.01f)
				isGreen = 0.01f;

		}
	}

	Globals::Vars::Visuals::Var::rainbowColor = ImVec4(isRed, isGreen, isBlue, 1.0f);
	Globals::Vars::VisualsVR::Var::rainbowColor = ImVec4(isRed, isGreen, isBlue, 1.0f);
}


void Render::GUI::Draw() {

	if (!Base::Opened)
		return;

	if (Globals::Vars::GUI::Themes::midnight)
		Themes::Midnight();
	else
		Themes::Matcha();

	/*	static bool quickThreadSetup{ false };
	if (!quickThreadSetup) {
		quickThreadSetup = true;
		auto domain = SDK::IL2CPP::Utils::il2cpp_domain_get();
		if (!domain)
			return;

		auto thread = domain->ThreadAttach();
		if (!thread)
			return;

		printf("[Dbg] thread: [%p]\n", thread);
	}*/

	/*
	static bool quickSetupFoodList{ false };
	if (!quickSetupFoodList && quickThreadSetup) {
		quickSetupFoodList = true;
		auto newConsumableConfigObj = SDK::Pointers::Game::ConsumableInfo.klass.New();
		if (newConsumableConfigObj) {
			auto consumableConfig = SDK::Pointers::Game::ConsumableInfo.get_Config.Invoke().Get();
			printf("%p\n", consumableConfig);
			if (consumableConfig) {
				auto consumablesList = SDK::Pointers::Game::ConsumableCollectionRuntimeConfig.get_List[consumableConfig].Invoke().Get();
				if (consumablesList) {
					for (int i = 0; i < consumablesList->getLength(); ++i) {
						auto consumable = consumablesList->getPointer()[i];
						if (consumable) {
							SDK::Structs::Mono::String* pConsumableItemDesc = *(SDK::Structs::Mono::String**)((uint64_t)consumable + 0x18);
							SDK::Structs::Mono::String* pFriendlyName = *(SDK::Structs::Mono::String**)((uint64_t)consumable + 0x20);
							if (pConsumableItemDesc && pFriendlyName) {
								std::string consumableItemDesc = pConsumableItemDesc->getString();
								std::string friendlyName = pFriendlyName->getString();
								Globals::Vars::Runtime::List::foods.push_back({ friendlyName, consumableItemDesc });
								printf("[Dbg] Pushing Back Food Entry: {%s, %s}\n", friendlyName.c_str(), consumableItemDesc.c_str());
							}
						}
					}
					printf("[Dbg] Finished Parsing %i consumables\n", consumablesList->getLength());
					system("cls");
				}
			}
		}
	}*/

	static bool quickSetupColors{ false };
	if (!quickSetupColors) {
		quickSetupColors = true;

		Globals::Vars::Visuals::Var::lineColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
		Globals::Vars::Visuals::Var::nameColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
		Globals::Vars::Visuals::Var::skeletonColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
		Globals::Vars::Visuals::Var::boxColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);

		Globals::Vars::VisualsVR::Var::lineColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
	}


	ImGui::Begin("Kitty GUI");
	
	Headers::Render();
	
	ImGui::End();

}

void Render::GUI::DrawWindows() { Windows::Render(); }

void Render::GUI::DrawRuntimeWindows() {
	//run this manager in here temporarily
	if (Globals::Vars::PlayerBlacklisted::autoRamCrashBlacklisted) {

		for (auto& plr : players) {
			if (plr.instance && plr.playerName) {
				for (auto& blacklistedName : blacklistedNames) {
					auto name = plr.playerName->getString();
					auto playerNameString = lowerCaseString(name);

					if (!plr.hasBeenRamCrashed && playerNameString.contains(lowerCaseString(blacklistedName))) {
						if (Globals::Vars::PlayerBlacklisted::cheerCrash) {
							Globals::Vars::Runtime::Instance::target = plr.instance;
							Globals::Vars::PlayerList::ramCrash = true;
							plr.hasBeenRamCrashed = true;
						}

						else if (Globals::Vars::PlayerBlacklisted::bulletCrash) {
							Globals::Vars::Runtime::Instance::target = plr.instance;
							Globals::Vars::PlayerList::bulletRamCrash = true;
							plr.hasBeenRamCrashed = true;
						}
					}
				}
			}
		}
	}

	if (Globals::Vars::Runtime::Var::needsToSelectMod && Globals::Vars::Runtime::Instance::playerSelectorTarget && Globals::Vars::Network::playerSelector) {
		//Modifiable vars
		auto& needsToSelectMod = Globals::Vars::Runtime::Var::needsToSelectMod;
		auto& target = (SDK::RR::Game::Player*&)Globals::Vars::Runtime::Instance::target;

		auto instance = (SDK::RR::Game::GameCombatManager*)Globals::Vars::Runtime::Instance::GameCombatManager;
		auto selectedPlayer = (SDK::RR::Game::Player*)Globals::Vars::Runtime::Instance::playerSelectorTarget;

		if (Globals::Vars::PlayerList::loopFire)
			Globals::Vars::PlayerList::loopFire = false;

		if (Globals::Vars::PlayerList::spin)
			Globals::Vars::PlayerList::spin = false;



		if (Base::Opened)
			ImGui::SetNextWindowFocus();

		ImGui::Begin("Select A Mod");

		ImGui::Text("%s", selectedPlayer->get_PlayerName()->getString().c_str());
		ImGui::Separator();

		if (ImGui::Checkbox("Grant Loop Fire ##playerSelector", &Globals::Vars::PlayerList::loopFire)) {
			target = selectedPlayer;
			needsToSelectMod = false;
		}

		if (instance) {
			if (ImGui::Button("Kill ##playerSelector", ImVec2(ImGui::GetContentRegionAvail().x * 1.0f, 0))) {
				target = selectedPlayer;
				Globals::Vars::PlayerList::kill = true;
				needsToSelectMod = false;
			}

			if (ImGui::Button("Restore Health ##playerSelector", ImVec2(ImGui::GetContentRegionAvail().x * 1.0f, 0))) {
				target = selectedPlayer;
				Globals::Vars::PlayerList::restoreHealth = true;
				needsToSelectMod = false;
			}

			if (ImGui::Button("Invincibility ##playerSelector", ImVec2(ImGui::GetContentRegionAvail().x * 0.5f, 0))) {
				target = selectedPlayer;
				Globals::Vars::PlayerList::invincibility = true;
				needsToSelectMod = false;
			}

			ImGui::SameLine();
			ImGui::PushItemWidth(80.0f);
			ImGui::InputFloat("Duration", &Globals::Vars::PlayerList::Var::invincibilityDuration);
			ImGui::PopItemWidth();

			ImGui::Separator();
		}

		if (ImGui::Button("Spawn Asset ##playerSelector", ImVec2(ImGui::GetContentRegionAvail().x * 1.0f, 0))) {
			target = selectedPlayer;
			Globals::Vars::PlayerList::spawnAsset = true;
			needsToSelectMod = false;
		}

		if (ImGui::Button("Force Hold Asset ##playerSelector", ImVec2(ImGui::GetContentRegionAvail().x * 1.0f, 0))) {
			target = selectedPlayer;
			Globals::Vars::PlayerList::forceHoldAsset = true;
			needsToSelectMod = false;
		}

		ImGui::Separator();

		if (ImGui::Button("Steal Pv ##playerSelector", ImVec2(ImGui::GetContentRegionAvail().x * 1.0f, 0))) {
			target = selectedPlayer;
			Globals::Vars::PlayerList::stealPv = true;
			needsToSelectMod = false;
		}


		if (ImGui::Button("Restore Pv ##playerSelector", ImVec2(ImGui::GetContentRegionAvail().x * 1.0f, 0))) {
			target = selectedPlayer;
			Globals::Vars::PlayerList::restorePv = true;
			needsToSelectMod = false;
		}

		ImGui::Separator();

		if (ImGui::Button("Bring ##playerSelector", ImVec2(ImGui::GetContentRegionAvail().x * 1.0f, 0))) {
			target = selectedPlayer;
			Globals::Vars::PlayerList::bring = true;
			needsToSelectMod = false;
		}

		if (ImGui::Button("Bring To Player ##playerSelector", ImVec2(ImGui::GetContentRegionAvail().x * 1.0f, 0))) {
			Globals::Vars::Runtime::Var::needsToSelectPlayer = true;
			target = selectedPlayer;
			Globals::Vars::PlayerList::bringToPlayer = true;
		}

		if (ImGui::Button("Bring All To Player ##playerSelector", ImVec2(ImGui::GetContentRegionAvail().x * 1.0f, 0))) {
			target = selectedPlayer;
			Globals::Vars::PlayerList::bringAllToPlayer = true;
			needsToSelectMod = false;
		}

		if (ImGui::Button("Void ##playerSelector", ImVec2(ImGui::GetContentRegionAvail().x * 0.5f, 0))) {
			target = selectedPlayer;
			Globals::Vars::PlayerList::voidPlayer = true;
			needsToSelectMod = false;
		}

		ImGui::SameLine();

		ImGui::Checkbox("Infinity Toggle", &Globals::Vars::PlayerList::infinityToggle);

		ImGui::Separator();

		if (ImGui::Button("Despawn ##playerSelector", ImVec2(ImGui::GetContentRegionAvail().x * 1.0f, 0))) {
			target = selectedPlayer;
			Globals::Vars::PlayerList::despawn = true;
			needsToSelectMod = false;
		}

		if (ImGui::Button("Spawn ##playerSelector", ImVec2(ImGui::GetContentRegionAvail().x * 1.0f, 0))) {
			target = selectedPlayer;
			Globals::Vars::PlayerList::spawn = true;
			needsToSelectMod = false;
		}

		if (ImGui::Checkbox("Spin ##playerSelector", &Globals::Vars::PlayerList::spin)) {
			target = selectedPlayer;
			needsToSelectMod = false;
		}

		ImGui::Separator();

		if (ImGui::Button("Ram Crash (Cheer)", ImVec2(ImGui::GetContentRegionAvail().x * 1.0f, 0))) {
			target = selectedPlayer;
			Globals::Vars::PlayerList::ramCrash = true;
			needsToSelectMod = false;
		}

		if (ImGui::Button("Ram Crash (Bullet)", ImVec2(ImGui::GetContentRegionAvail().x * 1.0f, 0))) {
			target = selectedPlayer;
			Globals::Vars::PlayerList::bulletRamCrash = true;
			needsToSelectMod = false;
		}

		ImGui::Separator();

		if (ImGui::Button("Broadcast Fake VoteKick Message", ImVec2(ImGui::GetContentRegionAvail().x * 1.0f, 0.f))) {
			target = selectedPlayer;
			Globals::Vars::PlayerList::broadcastFakeVotekick = true;
			needsToSelectMod = false;
		}

		ImGui::Separator();

		if (ImGui::Button("Close", ImVec2(ImGui::GetContentRegionAvail().x * 1.0f, 0))) {
			needsToSelectMod = false;
		}

		ImGui::End();
	}

	if (Globals::Vars::Runtime::Var::needsToSelectPlayer && (Base::Opened || Globals::Vars::Runtime::Var::needsToSelectMod)) {
		if (Base::Opened)
			ImGui::SetNextWindowFocus();

		ImGui::Begin("Select A Player");
		for (auto& plr : players) {
			if (plr.instance) {
				if (ImGui::Button(plr.playerName->getString().c_str(), ImVec2(ImGui::GetContentRegionAvail().x * 1.0f, 0.f))) {
					if (Globals::Vars::Runtime::Var::needsToSelectMod)
						Globals::Vars::Runtime::Var::needsToSelectMod = false;
					Globals::Vars::Runtime::Instance::targetSelectedPlayer = plr.instance;
					Globals::Vars::Runtime::Var::needsToSelectPlayer = false;
				}
			}
		}
		ImGui::End();
	}
}