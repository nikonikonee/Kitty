#include "Managers_Network.h"

void Cheats::Managers::Network::Run() {
	auto localPlayer = SDK::RR::Game::Player::get_LocalPlayer();
	if (localPlayer) {
		auto localNetworkedPlayer = localPlayer->get_NetworkedPlayer();
		if (localNetworkedPlayer) {
			if (Globals::Vars::Network::loopGrantMaster) {
				localNetworkedPlayer->SetMasterClient();
			}
		}
	}
}



void (*old_OpRaiseEvent)(uint8_t eventCode, void* content, void* raiseEventOptions, int sendOptions);
void OpRaiseEvent(uint8_t eventCode, void* content, void* raiseEventOptions, int sendOptions) {
	if (content != nullptr) {
		auto hashtable = (SDK::RR::GameServer::Hashtable*)content;
		auto string = SDK::Pointers::System::Object.ToString[content].Invoke().Get();
		if (string) {
			std::string actualString = string->getString();
			if (actualString == "ExitGames.Client.Photon.Hashtable") {
				auto hashTableToString = SDK::Pointers::GameServer::Hashtable.ToString[content].Invoke().Get();
				if (hashTableToString) {
					auto hashtableCString = hashTableToString->getString();
					
					if (hashtableCString.contains("(System.Byte)0=(System.String)[Player]") && Globals::Vars::Network::playerVanish) {
						hashtable->set_Item(0, SDK::IL2CPP::Utils::il2cpp_string_new("[Chip]"));
					}
				}
			}
		}
	}
	return old_OpRaiseEvent(eventCode, content, raiseEventOptions, sendOptions);
}

void (*old_HTTPUpdateDelegator)(void* instance);
void HTTPUpdateDelegator(void* instance) {
	if (instance && Globals::Vars::Network::nsKiller)
		return;
	return old_HTTPUpdateDelegator(instance);
}

void Cheats::Managers::Network::Setup() {//0x81F2B40 //0x83A2CB0
	Utils::Hook(Utils::getAbsoluteAddress(0x83A2CB0), &OpRaiseEvent, (void**)&old_OpRaiseEvent);
	//Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("RecNet.Runtime", "BestHTTP", "HTTPUpdateDelegator", "Update", 0), &HTTPUpdateDelegator, (void**)&old_HTTPUpdateDelegator);
}