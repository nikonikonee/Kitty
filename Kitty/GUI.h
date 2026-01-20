#pragma once
#include <fstream>
#include "json/json.hpp"

#include "GUIBase.h"
#include "Themes.h"

#include "Players.h"
#include "Runtime.h"

#include "List.h"
#include "Dictionary.h"
#include "Spawnables.h"

//Rendered Elements
#include "Headers.h"
#include "Windows.h"

namespace Render::GUI {
	extern void RainbowManager();
	extern void Draw();

	extern void DrawWindows();
	extern void DrawRuntimeWindows();
}