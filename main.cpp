// ==============================================================
// Name: Alec Dosier
// Date: 2/2022
// Description: A C++ foundation for graphical libraries
// ==============================================================


#include "Engine.h" // Library for the engine that runs everything

int main(int argc, char *argv[])
{
	int FPS = 60; // limit framerate
	int frameDelay = 1000 / FPS; // how many ticks/cycles per frame to run at 60fps
	Uint32 frameStart;
	int frameTime;

	Engine* engine = nullptr;
	engine = new Engine(); 
	
	// This will initalize SDL and all objects running durring the application 
	engine->init("Graphics Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Engine::windowW, Engine::windowH, Engine::fullscr);

	while (engine->running()) // any time the isRunning flag is set, the program will close
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
