#include "Cheat.h"
#include "Logger.h"
#include "RetSpoofer/RetSpoofer.hpp"

void Cheat::Setup() {
	//Bypass Referee
	Referee::Bypass();
	Logger::Log(clr::magenta, "[Setup] 1/5");


	Globals::Vars::Main::spoof = Memory::FindPattern("GameAssembly.dll", "\xFF\x23", "xx");
	Globals::Vars::Main::unitySpoof = Memory::FindPattern("UnityPlayer.dll", "\xFF\x23", "xx");
	Logger::Log(clr::yellow, "Spoof: [%p]", Globals::Vars::Main::spoof);
	Logger::Log(clr::yellow, "UnitySpoof: [%p]", Globals::Vars::Main::unitySpoof);

	SDK::Pointers::Exports::Exports.Setup();
	Logger::Log(clr::yellow, "[>] Setup Exported Pointers");
	Logger::Log(clr::magenta, "[Setup] 2/5");
	Sleep(500);

	auto domain = SDK::IL2CPP::Utils::il2cpp_domain_get();
	if (!domain)
		return;

	Logger::Log(clr::yellow, "[>] domain: [%p]", domain);

	auto thread = domain->ThreadAttach();
	if (!thread)
		return;

	Logger::Log(clr::green, "[+] thread: [%p]", thread);
	system("cls");
	Logger::Log(clr::magenta, "[Setup] 3/5");
	Sleep(1000);
	
	Logger::Log(clr::yellow, "[>] method test: %p", SDK::IL2CPP::Backends::Class("", "", "Player").GetMethod("Update", 0));
	SDK::Pointers::Setup();
	Sleep(1000);
	system("cls");

	//Setup natives
	Globals::Vars::Runtime::Native::Object = SDK::IL2CPP::Utils::GetClass("mscorlib", "System", "Object");
	Globals::Vars::Runtime::Native::Boolean = SDK::IL2CPP::Utils::GetClass("mscorlib", "System", "Boolean");
	Globals::Vars::Runtime::Native::Int32 = SDK::IL2CPP::Utils::GetClass("mscorlib", "System", "Int32");
	Globals::Vars::Runtime::Native::Single = SDK::IL2CPP::Utils::GetClass("mscorlib", "System", "Single");
	Globals::Vars::Runtime::Native::Byte = SDK::IL2CPP::Utils::GetClass("mscorlib", "System", "Byte");


	Globals::Vars::Runtime::Native::Vector3 = SDK::IL2CPP::Utils::GetClass("UnityEngine.CoreModule", "UnityEngine", "Vector3");
	Globals::Vars::Runtime::Native::Quaternion = SDK::IL2CPP::Utils::GetClass("UnityEngine.CoreModule", "UnityEngine", "Quaternion");
	Globals::Vars::Runtime::Native::Material = SDK::IL2CPP::Utils::GetClass("UnityEngine.CoreModule", "UnityEngine", "Material");

	Globals::Vars::Runtime::Native::NetworkedView = SDK::IL2CPP::Utils::GetClass("RecRoom.Networking.RRNetworkLayer", "RecRoom.Networking", "RRNetworkView");

	Globals::Vars::Runtime::Instance::boxAssetBundle = SDK::RR::Unity::AssetBundle::LoadFromFile("C:\\Users\\Sigma\\Boxes\\AssetBundles\\2dbox");
	
	Logger::Log(clr::magenta, "[Setup] 4/5 Natives/Vars Setup");
	Sleep(1000);
	system("cls");

	Logger::Log(clr::magenta, "[>] Testing ptrs...");
	SDK::RR::Unity::Time::set_timeScale(5.0f);
	Sleep(100);
	SDK::RR::Unity::Time::set_timeScale(1.0f);
	Logger::Log(clr::magenta, "[Setup] 5/5 PROCEEDING WITH INITALIZING");


	//Setup Cheats
	Cheats::Setup();
}