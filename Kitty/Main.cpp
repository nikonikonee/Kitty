#include "Main.h"

//Written as of 7/5/25 | Write back here whenever this cheat becomes a success :3



void Main::Setup(LPVOID lpReserved) {
	Globals::Vars::Main::buildCode = "Code Re-Writing";

	Console::Setup("Kitty Logs (Supremium's Mouse) - @pillowguy._.");
	Console::Main();

	//Start Rendering Thread

	Logger::Log(clr::yellow, "[>] Starting Rendering Thread");
	std::thread(&Render::Setup, lpReserved).detach();
	Logger::Log(clr::green, "[+] Rendering Thread Running");
	
	Sleep(1000);

	Logger::Log(clr::yellow, "[>] Starting Cheat Thread");
	std::thread(&Cheat::Setup).detach();
	Logger::Log(clr::green, "[+] Cheat Thread Running");

	system("cls");
}

BOOL APIENTRY DllMain(HMODULE hMod, DWORD ulReason, LPVOID lpReserved) {
	switch (ulReason) {
	case 1:
		std::thread(&Main::Setup, hMod).detach();
		break;
	}
	return TRUE;
}

