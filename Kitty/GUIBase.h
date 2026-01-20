#pragma once
//Windows API
#include <Windows.h>
//ImGui
#include "imgui.h"
#include "imgui_internal.h"
//Backends
#include "imgui_impl_dx11.h"
#include "imgui_impl_win32.h"
//Styling
#include "Roboto_Regular.h"
//Vars
#include "Runtime.h"

namespace Render::GUI::Base {
	//Setup
	extern void Initialize(HWND window, ID3D11Device* device, ID3D11DeviceContext* context);

	//Flags
	extern bool Opened;
	extern bool IsOpened();

	//Manager
	extern inline void KeyManager();
}