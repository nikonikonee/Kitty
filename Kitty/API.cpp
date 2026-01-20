#include "API.h"
#include "Logger.h"
#include "RetSpoofer/RetSpoofer.hpp"

void (*old_NotifyServerCertificate)(void* instance, void* certificate);
void NotifyServerCertificate(void* instance, void* certificate) {
	if (instance && Globals::Vars::API::leaf)
		return;
	return old_NotifyServerCertificate(instance, certificate);
}

void (*old_Send)(void* instance);
void Send(void* instance) {
	if (instance) {
		auto uri = *(SDK::RR::System::Uri**)((uint64_t)instance + 0x10);
		if (uri) {
			if (Globals::Vars::API::uriLogger) {
				std::string tag = "[URI] " + uri->ToString()->getString();
				Globals::Vars::Loggers::uriLogs.push_back(tag);

			}
			if (uri->ToString()->getString() == ("https://econ.rec.net/api/avatar/v4/items") && Globals::Vars::API::clothingOverride) {
				if (std::filesystem::exists("Configs/clothing.json"))
					*(SDK::RR::System::Uri**)((uint64_t)instance + 0x10) = SDK::RR::System::Uri::ctor("file:///C:/Program%20Files%20(x86)/Steam/steamapps/common/RecRoom/Configs/clothing.json");
			}
			else if (uri->ToString()->getString() == ("https://econ.rec.net/api/equipment/v2/getUnlocked") && Globals::Vars::API::skinsOverride) {
				if (std::filesystem::exists("Configs/skins.json"))
					*(SDK::RR::System::Uri**)((uint64_t)instance + 0x10) = SDK::RR::System::Uri::ctor("file:///C:/Program%20Files%20(x86)/Steam/steamapps/common/RecRoom/Configs/skins.json");
			}
			else if (uri->ToString()->getString() == ("https://econ.rec.net/api/consumables/v2/getUnlocked") && Globals::Vars::API::consumablesOverride) {
				if (std::filesystem::exists("Configs/consumables.json"))
					*(SDK::RR::System::Uri**)((uint64_t)instance + 0x10) = SDK::RR::System::Uri::ctor("file:///C:/Program%20Files%20(x86)/Steam/steamapps/common/RecRoom/Configs/consumables.json");
			}
			else if (uri->ToString()->getString() == ("https://econ.rec.net/api/storefronts/v4/balance/2") && Globals::Vars::API::currencyOverride) {
				if (std::filesystem::exists("Configs/currency.json"))
					*(SDK::RR::System::Uri**)((uint64_t)instance + 0x10) = SDK::RR::System::Uri::ctor("file:///C:/Program%20Files%20(x86)/Steam/steamapps/common/RecRoom/Configs/currency.json");
			}
			else if (uri->ToString()->getString() == ("https://econ.rec.net/api/CampusCard/v1/UpdateAndGetSubscription") && Globals::Vars::API::fakeRRPlus) {
				if (std::filesystem::exists("Configs/fake_rr_plus.json"))
					*(SDK::RR::System::Uri**)((uint64_t)instance + 0x10) = SDK::RR::System::Uri::ctor("file:///C:/Program%20Files%20(x86)/Steam/steamapps/common/RecRoom/Configs/fake_rr_plus.json");
			}
			else if (uri->ToString()->getString() == ("https://api.rec.net/api/players/v2/progression") && Globals::Vars::API::fakeLevel) {
				if (std::filesystem::exists("Configs/fake_level.json"))
					*(SDK::RR::System::Uri**)((uint64_t)instance + 0x10) = SDK::RR::System::Uri::ctor("file:///C:/Program%20Files%20(x86)/Steam/steamapps/common/RecRoom/Configs/fake_level.json");
			}
			else if (uri->ToString()->getString() == ("https://rooms.rec.net/photon_access_token") && Globals::Vars::API::rolesOverride) {
				if (std::filesystem::exists("Configs/roles.json"))
					*(SDK::RR::System::Uri**)((uint64_t)instance + 0x10) = SDK::RR::System::Uri::ctor("file:///C:/Program%20Files%20(x86)/Steam/steamapps/common/RecRoom/Configs/roles.json");
			}
		}
	}
	return spoof_call(Globals::Vars::Main::spoof, old_Send, instance); //Silly Supremimum!
}


void Cheats::API::Setup() {
	/*---- Leaf Toggle ----*/
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("RecNet.Runtime", "Org.BouncyCastle.Crypto.Tls", "LegacyTlsAuthentication", "NotifyServerCertificate", 1), &NotifyServerCertificate, (void**)&old_NotifyServerCertificate);
	/*---- Leaf Overrides ----*/
	Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("RecNet.Runtime", "BestHTTP", "HTTPRequest", "Send", 0), &Send, (void**)&old_Send);
	Logger::Log(clr::magenta, "[Cheat] Setup: [API]");
}