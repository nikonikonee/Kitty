#include "Console.h"
#include "Vars.h"

void Console::Setup(std::string title) {
	AllocConsole();
	SetConsoleTitle(title.c_str());
	FILE* f{};
	freopen_s(&f, "CONOUT$", "w", stdout);
}

void Console::Main() {
	Logger::Log(clr::magenta, "[<3] Kitty ;3");
	Logger::Log(clr::yellow, "[>] Supremium tried to fix methodPtr!");
	Logger::Log(clr::yellow, "[>] BuildCode: (%s)", Globals::Vars::Main::buildCode.c_str());
	Sleep(2000);
	system("cls");
}