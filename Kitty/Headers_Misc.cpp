#include "Headers_Misc.h"

void Render::GUI::Headers::Misc::Render() {
	if (ImGui::CollapsingHeader("Misc")) {
		ImGui::Checkbox("Trial Clothing", &Globals::Vars::Misc::trialClothing);
		ImGui::Checkbox("Free Room Keys", &Globals::Vars::Misc::freeRoomKeys);
		ImGui::Checkbox("Fake Developer", &Globals::Vars::Misc::fakeDeveloper);
		ImGui::Checkbox("Always Allow Backpack Tools", &Globals::Vars::Misc::alwaysAllowBackpackTools);
		ImGui::Checkbox("Orientation Skip", &Globals::Vars::Misc::orientationSkip);
		ImGui::Checkbox("Quest Room Skip (Authority)", &Globals::Vars::Misc::questRoomSkip);
		ImGui::Checkbox("Quest AI Skip (Authority)", &Globals::Vars::Misc::questAiSkip);
		ImGui::Checkbox("Anti Quit", &Globals::Vars::Misc::antiQuit);

		if (ImGui::Button("Drawing Test", ImVec2(ImGui::GetContentRegionAvail().x * 1.0f, 0))) {
			auto drawingSurfaceObjs = SDK::RR::Base::Object::FindObjectsOfType<SDK::RR::Game::DrawingSurface*>(SDK::RR::System::Type::GetType("DrawingSurface"));

			if (drawingSurfaceObjs) {

				for (int i = 0; i < drawingSurfaceObjs->getLength(); ++i) {
					auto drawingSurface = drawingSurfaceObjs->getPointer()[i];
					if (drawingSurface) {
						const char* imagePath("C:\\Users\\Sigma\\Downloads\\SPOILER_IMG_0513.jpg");
						
						auto newTexture = SDK::RR::Unity::Texture2D::ctor(2, 2);

						auto fileBytes = SDK::RR::System::File::ReadAllBytes(imagePath);

						SDK::RR::Unity::ImageConversion::LoadImageTex(newTexture, fileBytes);

						drawingSurface->LoadDrawing(newTexture);
					}
				}
			}
		}
	}
}