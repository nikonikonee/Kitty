#pragma once
#include "imgui.h"
#include "RR.h"

namespace Draw {
	//Basic Elements
	extern void DrawLine(ImVec2 start, ImVec2 end, ImVec4 color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
	extern void DrawTxt(ImVec2 position, const char* txt, ImVec4 color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f));

	//Various Boxes
	extern void DrawBox(float x, float y, float w, float h, ImVec4 color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
	extern void DrawBoxOutlined(float x, float y, float w, float h, ImVec4 color, float thickness = 1.0f, ImVec4 outlineColor = ImVec4(0, 0, 0, 1));
	extern void DrawBoxFilled(float x, float y, float w, float h, ImVec4 color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
	extern void DrawBoxCornered(float x, float y, float w, float h, float thickness, ImVec4 color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
}