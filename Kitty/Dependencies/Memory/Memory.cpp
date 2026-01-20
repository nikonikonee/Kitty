#include "Memory.h"
#include <Psapi.h> //Include in .cpp file to avoid reintilize issues
#include <winscard.h>


BOOLEAN Memory::MaskCompare(PVOID buffer, LPCSTR pattern, LPCSTR mask) {
    for (auto b = reinterpret_cast<PBYTE>(buffer); *mask; ++pattern, ++mask, ++b) {
        if (*mask == 'x' && *reinterpret_cast<LPCBYTE>(pattern) != *b) {
            return FALSE;
        }
    }

    return TRUE;
}

PBYTE Memory::FindPattern(const char* image, LPCSTR pattern, LPCSTR mask) {
    MODULEINFO info = { 0 };
    GetModuleInformation(GetCurrentProcess(), GetModuleHandleA(image), &info, sizeof(info));

    info.SizeOfImage -= static_cast<DWORD>(strlen(mask));

    for (auto i = 0UL; i < info.SizeOfImage; ++i) {
        auto addr = reinterpret_cast<PBYTE>(info.lpBaseOfDll) + i;
        if (MaskCompare(addr, pattern, mask)) {
            return addr;
        }
    }
}

PBYTE Memory::FindPatternS(HMODULE image, LPCSTR pattern, LPCSTR mask) {
    MODULEINFO info = { 0 };
    GetModuleInformation(GetCurrentProcess(), image, &info, sizeof(info));

    info.SizeOfImage -= static_cast<DWORD>(strlen(mask));

    for (auto i = 0UL; i < info.SizeOfImage; ++i) {
        auto addr = reinterpret_cast<PBYTE>(info.lpBaseOfDll) + i;
        if (MaskCompare(addr, pattern, mask)) {
            return addr;
        }
    }
}