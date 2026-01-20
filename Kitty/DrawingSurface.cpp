#include "DrawingSurface.h"

namespace SDK::Pointers::Game {
	U_DrawingSurface DrawingSurface;

	void U_DrawingSurface::Setup() {
		klass = IL2CPP::Backends::Class("", "", "DrawingSurface");

		LoadDrawing = klass.GetMethod("PPKDGGNGGKI", 1);
	}
}