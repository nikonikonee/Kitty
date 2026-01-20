#include "Cheats.h"

void Cheats::Setup() {
	//Re-Initialize MinHook
	MH_Initialize();
	Sleep(1000);

	Movement::Setup();
	Combat::Setup();
	Spawnables::Setup();
	Misc::Setup();
	API::Setup();
	Unity::Setup();

	//Managers
	Managers::Players::Setup();
	Managers::Combat::Setup();
	//Managers::Visuals::Setup();
	Managers::Network::Setup();

	Sleep(1000);

	system("cls");
}