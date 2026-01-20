#include "VisualsVR.h"

void Cheats::Visuals::VR::SimpleLines() {
	if (!Globals::Vars::VisualsVR::simpleLines)
		return;


	auto lineColorVar = Globals::Vars::VisualsVR::Var::lineColor;
	SDK::Structs::Unity::Vector4 lineColor = (Globals::Vars::VisualsVR::customLineColor) ? 
		SDK::Structs::Unity::Vector4(lineColorVar.x, lineColorVar.y, lineColorVar.z, lineColorVar.w) :
		SDK::Structs::Unity::Vector4(1.0f, 1.0f, 1.0f, 1.0f);


	auto localPlayer = SDK::RR::Game::Player::get_LocalPlayer();
	if (!localPlayer)
		return;

	auto localPlayerBody = localPlayer->get_Body();
	if (!localPlayerBody)
		return;

	auto localPlayerBodyTransform = localPlayerBody->get_transform();
	if (!localPlayerBodyTransform)
		return;

	for (auto playerLine : playerLines) {
		if ((std::get<0>(playerLine) && std::get<1>(playerLine) && std::get<2>(playerLine)) && (std::get<0>(playerLine) != localPlayer)) {
			auto player = std::get<0>(playerLine);
			auto lineGO = std::get<1>(playerLine);
			auto lineRenderer = std::get<2>(playerLine);

			if ((player->get_Head() && player->get_Body()) && (player->get_Head()->get_transform() && player->get_Body()->get_transform())) {
				auto playerHeadTransform = player->get_Head()->get_transform();
				auto playerBodyTransform = player->get_Head()->get_transform();

				if (lineGO->get_transform()) {
					lineGO->get_transform()->set_parent(playerBodyTransform);

					static auto zTestAlways = SDK::RR::Unity::Shader::Find("UI/Default-ZTestAlways");
					auto chamsMaterial = SDK::RR::Unity::Material::ctor(zTestAlways);

					if (zTestAlways && chamsMaterial) {

						if (Globals::Vars::VisualsVR::rainbowColors) {
							auto rainbowColor = Globals::Vars::VisualsVR::Var::rainbowColor;
							lineColor = SDK::Structs::Unity::Vector4(rainbowColor.x, rainbowColor.y, rainbowColor.z, rainbowColor.w);
						}

						//setup material properties
						chamsMaterial->SetColor("_Color", lineColor);


						//setup line properties
						lineRenderer->set_material(chamsMaterial);
						lineRenderer->set_positionCount(2);
						lineRenderer->set_useWorldSpace(true);


						lineRenderer->set_startColor(lineColor);
						lineRenderer->set_endColor(lineColor);


						lineRenderer->set_startWidth(0.01f);
						lineRenderer->set_endWidth(0.01f);


						lineRenderer->SetPosition(0, localPlayerBodyTransform->get_position());
						lineRenderer->SetPosition(1, playerHeadTransform->get_position());
					}
				}
			}
		}
	}
}