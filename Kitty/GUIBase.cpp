#include "GUIBase.h"

void Render::GUI::Base::Initialize(HWND window, ID3D11Device* device, ID3D11DeviceContext* context) {
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();

	//Setup Font
	io.Fonts->AddFontFromMemoryTTF(Roboto_Regular, sizeof(Roboto_Regular), 18.0f);

	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(device, context);
}


bool Render::GUI::Base::Opened = false;
bool Render::GUI::Base::IsOpened() { return Opened; }

inline void Render::GUI::Base::KeyManager() {
	if (GetAsyncKeyState(VK_INSERT) & 1 || GetAsyncKeyState(VK_DELETE) & 1) {
		Opened = !Opened;
	}

	ImGui::GetIO().MouseDrawCursor = (Opened || Globals::Vars::Runtime::Var::needsToSelectMod);
}