#pragma once
#include <Windows.h>


namespace Memory {
	extern BOOLEAN MaskCompare(PVOID buffer, LPCSTR pattern, LPCSTR mask);
	extern PBYTE FindPattern(const char* image, LPCSTR pattern, LPCSTR mask);
	extern PBYTE FindPatternS(HMODULE image, LPCSTR pattern, LPCSTR mask);
}