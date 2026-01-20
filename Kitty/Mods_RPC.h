#pragma once
#include "Players.h"

namespace Cheats::Managers::PlayerList::Mods::RPC {
    extern void RamCrash(SDK::RR::Game::Player* target);
    extern void BulletRamCrash(SDK::RR::Game::Player* target);
    extern void SpawnRamCrash(SDK::RR::Game::Player* target);

    extern void BroadcastVoteKick(SDK::RR::Game::Player* target);
    
    extern void Bring(SDK::RR::Game::Player* target);
    extern void BringToPlayer(SDK::RR::Game::Player* playerToBring, SDK::RR::Game::Player* target);
    extern void BringAllToPlayer(SDK::RR::Game::Player* target);
    
    extern void Void(SDK::RR::Game::Player* target);

    extern void Spawn(SDK::RR::Game::Player* target);
    extern void Despawn(SDK::RR::Game::Player* target);

    //Loop
    extern void Spin(SDK::RR::Game::Player* target);
}