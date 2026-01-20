#include "Windows_PlayerList.h"

void Render::GUI::Windows::PlayerList::Render() {
	ImGui::Begin("Player List Window");

	ImGui::BeginChild("##PlayerSelector", ImVec2(ImGui::GetContentRegionAvail().x * 0.5f, 0), false);

	static ImGuiTextFilter filter;

	filter.Draw("##PlayerName");
	ImGui::SameLine();
	if (ImGui::Button("Clear ##PlayerName"))
		filter.Clear();

	ImGui::Separator();

	void* masterClientView{};

	for (int i = 0; i < players.size(); ++i) {
		if (players[i].instance) {
			std::string tag = "[" + std::to_string(players[i].playerIndex) + "] " + players[i].playerName->getString();


			if (filter.PassFilter(tag.c_str()))
				if (ImGui::Selectable(tag.c_str(), Globals::Vars::Runtime::List::Selected::player == i)) {
					//Disbale loop modules
					if (Globals::Vars::PlayerList::loopFire)
						Globals::Vars::PlayerList::loopFire = false;

					if (Globals::Vars::PlayerList::spin)
						Globals::Vars::PlayerList::spin = false;

					Globals::Vars::Runtime::List::Selected::player = i;
				}
		}
	}

	ImGui::EndChild();

	ImGui::SameLine();
	ImGui::SeparatorEx(ImGuiSeparatorFlags_Vertical, 3.0f);
	ImGui::SameLine();

	ImGui::BeginChild("##PlayerMods", ImVec2(0, 0), false);

	if (Globals::Vars::Runtime::List::Selected::player >= 0 && Globals::Vars::Runtime::List::Selected::player < players.size()
		&& players[Globals::Vars::Runtime::List::Selected::player].instance) {

		auto player = players[Globals::Vars::Runtime::List::Selected::player];

		auto& target = (SDK::RR::Game::Player*&)Globals::Vars::Runtime::Instance::target;

		ImGui::SeparatorText("Game Exploits");
		{
			if (ImGui::Checkbox("Grant Loop Fire", &Globals::Vars::PlayerList::loopFire))
				target = player.instance;

			auto instance = (SDK::RR::Game::GameCombatManager*)Globals::Vars::Runtime::Instance::GameCombatManager;
			if (instance) {
				if (ImGui::Button("Kill")) {
					target = player.instance;
					Globals::Vars::PlayerList::kill = true;
				}
				ImGui::SameLine();
				if (ImGui::Button("Restore Health")) {
					target = player.instance;
					Globals::Vars::PlayerList::restoreHealth = true;
				}
				ImGui::SameLine();
				if (ImGui::Button("Invincibility")) {
					target = player.instance;
					Globals::Vars::PlayerList::invincibility = true;
				}
				ImGui::SameLine();
				ImGui::PushItemWidth(80.0f);
				ImGui::InputFloat("Duration", &Globals::Vars::PlayerList::Var::invincibilityDuration);
				ImGui::PopItemWidth();
			}
		}

		ImGui::SeparatorText("Basic Exploits");
		{
			if (ImGui::Button("Steal Pv")) {
				target = player.instance;
				Globals::Vars::PlayerList::stealPv = true;
			}

			ImGui::SameLine();

			if (ImGui::Button("Restore Pv")) {
				target = player.instance;
				Globals::Vars::PlayerList::restorePv = true;
			}

			if (ImGui::Button("Spawn Asset ##playerList")) {
				target = player.instance;
				Globals::Vars::PlayerList::spawnAsset = true;
			}
		}

		ImGui::SeparatorText("RPC Exploits");
		{
			if (ImGui::Button("Bring")) {
				target = player.instance;
				Globals::Vars::PlayerList::bring = true;
			}

			ImGui::SameLine();

			if (ImGui::Button("Bring To Player")) {
				Globals::Vars::Runtime::Var::needsToSelectPlayer = true;
				target = player.instance;
				Globals::Vars::PlayerList::bringToPlayer = true;
			}

			ImGui::SameLine();

			if (ImGui::Button("Bring All To Player ##playerList")) {
				target = player.instance;
				Globals::Vars::PlayerList::bringAllToPlayer = true;
			}

			if (ImGui::Button("Void")) {
				target = player.instance;
				Globals::Vars::PlayerList::voidPlayer = true;
			}

			ImGui::SameLine();

			ImGui::Checkbox("Infinity Toggle", &Globals::Vars::PlayerList::infinityToggle);

			if (ImGui::Button("Spawn")) {
				target = player.instance;
				Globals::Vars::PlayerList::spawn = true;
			}

			ImGui::SameLine();

			if (ImGui::Button("Despawn")) {
				target = player.instance;
				Globals::Vars::PlayerList::despawn = true;
			}

			if (ImGui::Button("Ram Crash (Cheer)")) {
				target = player.instance;
				Globals::Vars::PlayerList::ramCrash = true;
			}

			ImGui::SameLine();

			if (ImGui::Button("Ram Crash (Bullet)")) {
				target = player.instance;
				Globals::Vars::PlayerList::bulletRamCrash = true;
			}

			ImGui::SameLine();

			if (ImGui::Button("Broadcast Fake VoteKick Message")) {
				target = player.instance;
				Globals::Vars::PlayerList::broadcastFakeVotekick = true;
			}
		}

		ImGui::SeparatorText("Loop RPC Exploits");
		{
			if (ImGui::Checkbox("Spin", &Globals::Vars::PlayerList::spin))
				target = player.instance;
			if (ImGui::Checkbox("Orbit (WIP)", &Globals::Vars::PlayerList::orbit))
				target = player.instance;

		}
	}


	ImGui::EndChild();

	ImGui::End();
}