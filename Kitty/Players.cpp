#include "Players.h"


std::vector<Player> players;
std::vector<SDK::RR::Unity::LineRenderer*> createdLines;
std::vector<std::tuple<SDK::RR::Game::Player*, SDK::RR::Unity::GameObject*, SDK::RR::Unity::LineRenderer*>> playerLines;

namespace Managers {
	U_Players Players;
}