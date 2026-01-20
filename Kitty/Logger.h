#pragma once
#include <iostream>
#include <cstdarg>
#include "colored_cout.h"

namespace Logger {
	extern void Log(clr color, const char* fmt, ...);
}