#pragma once
//Direct X
#include <d3d11.h>
#include <dxgi.h>

//GUI Stuff
#include "GUI.h"

//Hook
#include "kiero/kiero.h"

//Additional managers & cheats to run
#include "ESP.h"
#include "VisualsVR.h"
#include "Combat_Aimbot.h"

namespace Render::Hook { extern DWORD WINAPI Initialize(LPVOID lpReserved); }