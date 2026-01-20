#pragma once
#include <vector>
#include <tuple>
#include "Runtime.h"
#include "RR.h"


struct Player {
	//Basic PTR
	SDK::RR::Game::Player* instance;
	SDK::RR::GameServer::NetworkedPlayer* networkedPlayer;
	SDK::RR::Game::PlayerAvatar* playerAvatar;
	SDK::RR::Scripting::RRNetworkView* networkView;
	//Body Parts
	SDK::RR::Game::PlayerHead* head;
	SDK::RR::Game::PlayerBody* body;
	SDK::RR::Game::PlayerHand* leftHand;
	SDK::RR::Game::PlayerHand* rightHand;
	//Body Part Transforms
	SDK::RR::Unity::Transform* headTransform;
	SDK::RR::Unity::Transform* bodyTransform;
	SDK::RR::Unity::Transform* leftHandTransfrom;
	SDK::RR::Unity::Transform* rightHandTransform;

	//Info
	bool usesFullBodyAvatar;
	int playerIndex;
	SDK::Structs::Mono::String* playerName;

	//Extra for blacklisted
	bool hasBeenRamCrashed;
};

extern std::vector<Player> players;
extern std::vector<std::tuple<SDK::RR::Game::Player*, SDK::RR::Unity::GameObject*, SDK::RR::Unity::LineRenderer*>> playerLines;

namespace Managers {
	struct U_Players {
		bool IsPlayerPresent(SDK::RR::Game::Player* player) {
			for (auto& plr : players) {
				if (plr.instance == player) {
					return true;
				}
			}
			return false;
		}

		bool IsLinePresent(SDK::RR::Unity::LineRenderer* lineRenderer) {
			for (auto& line : playerLines) {
				if (std::get<2>(line) == lineRenderer) {
					return true;
				}
			}
			return false;
		}

		bool IsLineGoPresent(SDK::RR::Unity::GameObject* lineGO) {
			for (auto& line : playerLines) {
				if (std::get<1>(line) == lineGO) {
					return true;
				}
			}
			return false;
		}

		void AddPlayer(SDK::RR::Game::Player* player) {
			if (IsPlayerPresent(player))
				return;

			if (!player)
				return;

			Player pPlayer;
			
			pPlayer.instance = player;
			pPlayer.playerAvatar = player->get_PlayerAvatar();
			pPlayer.networkedPlayer = player->get_NetworkedPlayer();
			pPlayer.networkView = player->get_NetworkedView();


			pPlayer.head = player->get_Head();
			pPlayer.body = player->get_Body();
			pPlayer.leftHand = player->get_LeftHand();
			pPlayer.rightHand = player->get_RightHand();

			if (pPlayer.head) 
				pPlayer.headTransform = pPlayer.head->get_transform();
			
			if (pPlayer.body) 
				pPlayer.bodyTransform = pPlayer.body->get_transform();
			
			if (pPlayer.leftHand) 
				pPlayer.leftHandTransfrom = pPlayer.leftHand->get_transform();
			
			if (pPlayer.rightHand) 
				pPlayer.rightHandTransform = pPlayer.rightHand->get_transform();


			if (pPlayer.playerAvatar) 
				pPlayer.usesFullBodyAvatar = pPlayer.playerAvatar->get_UsesFullBodyAvatar();
			
			pPlayer.playerIndex = player->get_PlayerIndex();
			pPlayer.playerName = player->get_PlayerName();

			players.push_back(pPlayer);

			/*			auto lineGO = SDK::RR::Unity::GameObject::ctor("lineGO");
			if (!lineGO || IsLineGoPresent(lineGO))
				return;

			auto lineRenderer = lineGO->AddComponent<SDK::RR::Unity::LineRenderer*>(SDK::RR::System::Type::GetType("UnityEngine.LineRenderer"));
			if (!lineRenderer || IsLinePresent(lineRenderer))
				return;


			if (pPlayer.instance)
			{
				if (lineGO->get_transform())
				{
					lineGO->get_transform()->set_position({ 0.0f, -500.0f, 0.0f });
					playerLines.push_back(std::make_tuple(pPlayer.instance, lineGO, lineRenderer));
				}
			}*/
		}

		void Update() {
			/*			if (Globals::Vars::VisualsVR::lineStateChanged) {
				if (!Globals::Vars::VisualsVR::simpleLines && !playerLines.empty()) {
					for (auto& playerLine : playerLines) {
						auto lineGO = std::get<1>(playerLine);
						if (!lineGO)
							continue;

						SDK::RR::Base::Object::Destroy(lineGO);
					}
					playerLines.clear();

				}

				else if (Globals::Vars::VisualsVR::simpleLines && playerLines.empty()) {
					for (auto& plr : players) {
						auto lineGO = SDK::RR::Unity::GameObject::ctor("lineGO");
						if (!lineGO)
							continue;
						auto lineRenderer = lineGO->AddComponent<SDK::RR::Unity::LineRenderer*>(SDK::RR::System::Type::GetType("UnityEngine.LineRenderer"));
						if (!lineRenderer)
							continue;

						if (plr.instance && lineGO->get_transform())
						{
							lineGO->get_transform()->set_position({ 0.0f, -500.0f, 0.0f });
							playerLines.push_back(std::make_tuple(plr.instance, lineGO, lineRenderer));
						}
					}
				}
				Globals::Vars::VisualsVR::lineStateChanged = false;
			}*/
		}

		void RemovePlayer(SDK::RR::Game::Player* player) {
			/*			for (int i = 0; i < playerLines.size(); ++i) {
				if (std::get<0>(playerLines[i]) == player) {

					if (std::get<1>(playerLines[i]))
						SDK::RR::Base::Object::Destroy(std::get<1>(playerLines[i]));

					playerLines.erase(playerLines.begin() + i);
					break;
				}
			}*/

			for (int i = 0; i < players.size(); ++i) {
				if (players[i].instance == player) {
					players.erase(players.begin() + i);
					break;
				}
			}
		}
	};
	extern U_Players Players;
}