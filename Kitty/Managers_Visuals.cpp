#include "Managers_Visuals.h"

void Cheats::Managers::Visuals::OnRenderObject() {
	printf("OnRender\n");
}

void (*old_OnRenderObject)(void* instance);
void OnRenderObject(void* instance) {
	printf("OnRender\n");
	return old_OnRenderObject(instance);
}

void Cheats::Managers::Visuals::Setup() {
	//Utils::Hook(SDK::IL2CPP::Utils::GetMethodPtr("", "", "LightShafts", "OnRenderObject",0), &OnRenderObject, (void**)&old_OnRenderObject);
}