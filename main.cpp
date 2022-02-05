// ==============================================================
// Name: Alec Dosier
// Date: 2/2022
// Description: A C++ foundation for graphical libraries
// ==============================================================


#include "Engine.h" // Library for the engine

int main(int argc, char *argv[])
{
	int FPS = 60; // limit framerate
	int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	Engine* engine = nullptr;
	engine = new Engine(); // insert name of window/../../xdim/ydim
	engine->init("Graphics Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 960, false);

	while (engine->running())
	{
		frameStart = SDL_GetTicks();

		engine->handleEvents();
		engine->update();
		engine->render();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	
	engine->close();
	
	return 0;
}
