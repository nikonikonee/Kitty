#include "Hook.h"

//Signatures
extern  LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef uintptr_t PTR;

//Variables
Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;

LRESULT WINAPI WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);

	if (Render::GUI::Base::IsOpened() || Globals::Vars::Runtime::Var::needsToSelectMod)
		ClipCursor(NULL);

	return (Render::GUI::Base::IsOpened() || Globals::Vars::Runtime::Var::needsToSelectMod) ? true : CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

bool init = false;
HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			Render::GUI::Base::Initialize(window, pDevice, pContext);
			init = true;
		}

		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	Render::GUI::Base::KeyManager();

	Render::GUI::RainbowManager();
	Render::GUI::Draw();

	Render::GUI::DrawWindows();
	Render::GUI::DrawRuntimeWindows();

	if (Globals::Vars::Visuals::enableEsp)
		Cheats::Visuals::ESP::Run();
	
	Cheats::Visuals::VR::SimpleLines();
	
	if (Globals::Vars::Aimbot::enableAimbot)
		Cheats::Combat::Aimbot::Run();

	if (Globals::Vars::Network::playerSelector) {
		if (GetAsyncKeyState(VK_F1) & 0x8000) {
			if (!Globals::Vars::Runtime::Var::needsToSelectMod) {
				auto closestPlayer = Cheats::Combat::Aimbot::Utils::GetClosestPlayerWithinStaticFOV(65.0f);
				if (closestPlayer) {
					Globals::Vars::Runtime::Instance::playerSelectorTarget = closestPlayer;
					Globals::Vars::Runtime::Var::needsToSelectMod = true;
				}
			}
		}
	}

	auto background = ImGui::GetBackgroundDrawList();

	if (background && Globals::Vars::Aimbot::renderFovCircle && (Globals::Vars::Aimbot::enableAimbot || Globals::Vars::Aimbot::enableSilentAimbot))
		background->AddCircle(ImVec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2), Globals::Vars::Aimbot::Var::circleSize, ImColor(255, 255, 255, 255), 360, 1.0f);

	ImGui::Render();

	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(pSwapChain, SyncInterval, Flags);
}


DWORD WINAPI Render::Hook::Initialize(LPVOID lpReserved)
{
	bool finished = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)&oPresent, hkPresent);
			finished = true;
		}
	} while (!finished);
	return TRUE;
}