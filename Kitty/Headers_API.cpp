#include "Headers_API.h"

void Render::GUI::Headers::API::Render() {
	if (ImGui::CollapsingHeader("API")) {
		ImGui::Checkbox("Leaf Toggle", &Globals::Vars::API::leaf);
		if (Globals::Vars::API::leaf) {
			ImGui::SeparatorText("Basic Unlockables");
			ImGui::Checkbox("Clothing Override", &Globals::Vars::API::clothingOverride);
			ImGui::Checkbox("Skins Override", &Globals::Vars::API::skinsOverride);
			ImGui::Checkbox("Consumables Override", &Globals::Vars::API::consumablesOverride);
			ImGui::SeparatorText("Account/Econ Mods");
			ImGui::Checkbox("Currency Override", &Globals::Vars::API::currencyOverride);
			ImGui::Checkbox("Fake RR+", &Globals::Vars::API::fakeRRPlus);
			ImGui::Checkbox("Fake Level 50", &Globals::Vars::API::fakeLevel);
			ImGui::SeparatorText("Other Mods");
			ImGui::Checkbox("Roles Override", &Globals::Vars::API::rolesOverride);
			ImGui::SeparatorText("Gifting");
			ImGui::Checkbox("Gift Override (WIP)", &Globals::Vars::API::giftOverride);
			ImGui::Separator();
			ImGui::Checkbox("URI Logger", &Globals::Vars::API::uriLogger);
		}

		ImGui::Separator();

		if (ImGui::Button("tetetet")) {
			using namespace SDK::Pointers::Exports;
			using namespace SDK::Pointers::Game;
			using namespace SDK::Pointers::System;
			using namespace SDK::Structs::Mono;
			using namespace SDK::Structs::Unity; 

			auto avatarConfig = AvatarItemWardrobeRuntimeConfig.get_Config.Invoke().Get();
			if (avatarConfig) {
				void* caidToAvatarItemSelections = AvatarItemWardrobeRuntimeConfig.caidToAvatarItemSelections[avatarConfig].Retrieve().Get();
				if (caidToAvatarItemSelections) {
					SDK::IL2CPP::Backends::Class avatarClass = Exports.il2cpp_object_get_class(caidToAvatarItemSelections);

					if (avatarClass.Parent()) {
						SDK::IL2CPP::Backends::Field<List<void**>*> dataField = avatarClass.Parent()->GetField("serializedData");
						printf("got field in %s\n", Exports.il2cpp_class_get_name(avatarClass.Parent()));


						auto serializedData = dataField[caidToAvatarItemSelections].Retrieve().Get();

						if (serializedData) {
							printf("going through %i\n", serializedData->getSize());
							for (int i = 0; i < serializedData->getSize(); ++i) {
								auto dataEntry = serializedData->getItems()[i];
								if (dataEntry) {
									SDK::IL2CPP::Backends::Class dataEntryClass = Exports.il2cpp_object_get_class(dataEntry);

									if (dataEntryClass.Parent()) {
										SDK::IL2CPP::Backends::Method<Array<void**>*> valMethod = dataEntryClass.Parent()->GetMethod("get_Val", 0);

										auto dataValue = valMethod[dataEntry].Invoke().Get();

										if (dataValue) {

										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}