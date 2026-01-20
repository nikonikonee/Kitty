#include "Draw.h"

void Draw::DrawLine(ImVec2 start, ImVec2 end, ImVec4 color) {
	auto background = ImGui::GetBackgroundDrawList();
	if (background)
		background->AddLine(start, end, ImColor(color.x, color.y, color.z, color.w));
}

void Draw::DrawTxt(ImVec2 position, const char* txt, ImVec4 color) {
	auto background = ImGui::GetBackgroundDrawList();
	if (background) {
		background->AddText(position, ImColor(color.x, color.y, color.z, color.w), txt);
	}
}

void Draw::DrawBox(float x, float y, float w, float h, ImVec4 color) {
	auto background = ImGui::GetBackgroundDrawList();
	if (background)
		background->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), ImColor(color.x, color.y, color.z, color.w), 0.0f);
}

void Draw::DrawBoxOutlined(float x, float y, float w, float h, ImVec4 color, float thickness, ImVec4 outlineColor) {
	auto background = ImGui::GetBackgroundDrawList();
	if (background) {
		background->AddRect(ImVec2(x - thickness, y - thickness), ImVec2(x + w + thickness, y + h + thickness), ImColor(outlineColor.x, outlineColor.y, outlineColor.z, outlineColor.w), 0.0f, 0, thickness);
		background->AddRect(ImVec2(x + thickness, y + thickness), ImVec2(x + w - thickness, y + h - thickness), ImColor(outlineColor.x, outlineColor.y, outlineColor.z, outlineColor.w), 0.0f, 0, thickness);
		background->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), ImColor(color.x, color.y, color.z, color.w), 0.0f, 0, thickness);
	}
}

void Draw::DrawBoxFilled(float x, float y, float w, float h, ImVec4 color) {
	auto background = ImGui::GetBackgroundDrawList();
	if (background) {
		background->AddRectFilled(ImVec2(x, y - 1), ImVec2(x + w, y + h), ImColor(color.x, color.y, color.z, 0.07), 0, 0);
		background->AddRectFilled(ImVec2(x, y + 1), ImVec2(x + w, y + h), ImColor(color.x, color.y, color.z, 0.07), 0, 0);
		background->AddRectFilled(ImVec2(x - 1, y), ImVec2(x + w, y + h), ImColor(color.x, color.y, color.z, 0.07), 0, 0);
		background->AddRectFilled(ImVec2(x + 1, y), ImVec2(x + w, y + h), ImColor(color.x, color.y, color.z, 0.07), 0, 0);
		background->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImColor(color.x, color.y, color.z, 0.07), 0, 0);

		background->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), ImColor(color.x, color.y, color.z, 1.0), 0, 0);
	}
}

//https://www.unknowncheats.me/forum/counter-strike-2-a/607062-help-corner-box.html
void Draw::DrawBoxCornered(float x, float y, float w, float h, float thickness, ImVec4 color) {
	auto background = ImGui::GetBackgroundDrawList();
	if (background) {
		float lineW = (w / 3);
		float lineH = (h / 3);

		//corners
		background->AddLine(ImVec2(x, y - thickness / 2), ImVec2(x, y + lineH), ImColor(color.x, color.y, color.z, color.w), thickness);//top left
		background->AddLine(ImVec2(x - thickness / 2, y), ImVec2(x + lineW, y), ImColor(color.x, color.y, color.z, color.w), thickness);

		background->AddLine(ImVec2(x + w - lineW, y), ImVec2(x + w + thickness / 2, y), ImColor(color.x, color.y, color.z, color.w), thickness);//top right horizontal
		background->AddLine(ImVec2(x + w, y - thickness / 2), ImVec2(x + w, y + lineH), ImColor(color.x, color.y, color.z, color.w), thickness);

		background->AddLine(ImVec2(x, y + h - lineH), ImVec2(x, y + h + (thickness / 2)), ImColor(color.x, color.y, color.z, color.w), thickness);//bot left
		background->AddLine(ImVec2(x - thickness / 2, y + h), ImVec2(x + lineW, y + h), ImColor(color.x, color.y, color.z, color.w), thickness);

		background->AddLine(ImVec2(x + w - lineW, y + h), ImVec2(x + w + thickness / 2, y + h), ImColor(color.x, color.y, color.z, color.w), thickness);//bot right
		background->AddLine(ImVec2(x + w, y + h - lineH), ImVec2(x + w, y + h + (thickness / 2)), ImColor(color.x, color.y, color.z, color.w), thickness);
	}
}