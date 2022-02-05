#include "Engine.h"
#include "TextureManager.h"
#include "Components.h"

Manager manager;
SDL_Renderer* Engine::renderer = nullptr;

// ball entity
auto& ball(manager.addEntity());

Engine::Engine()
{

}

Engine::~Engine()
{

}

void Engine::init(const char* title, int xpos, int ypos, int width, int height, bool fullscr)
{
	// function details
	// This function initalizes SDL and
		// creates a window from the xpos, ypos, width, height
			// will go fullscreen if flag is true
		// creates a renderer
	// else this will print out error messages and return
	// after setting the isRunning flag to false to end the program.

	int flags = 0;

	if (fullscr)
		flags = SDL_WINDOW_FULLSCREEN;	// sets flag to fullscreen

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) // if SDL initializes as intended
	{
		std::cout << "SDL Initalized." << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscr);
		if (window) // if the window is created as intended
		{
			std::cout << "Window Created." << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0); // (window, int index, Uint32 flags)
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			// there are several tweaks to the renderer that can be made
			// this simply sets the draw color to black with no alpha mode set
			std::cout << "Renderer Created." << std::endl;
		}
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
	
	initObjects(); // sets up all objects in the scene

	return;
}

void Engine::initObjects()
{
	ball.addComponent<PositionComponent>(450,450);
	ball.addComponent<SpriteComponent>("assets/ball.png");
}

void Engine::handleEvents()
{
	// function improvement
		// This function can be improved later by adding
		// a state system to poll for different events
	// function details
		// it simply runs a switch statement on an SDL_Event to trigger updates

	SDL_Event event;
	SDL_PollEvent(&event); // SDL sets our local event to what is currently happening.

	switch (event.type)
	{
	case SDL_QUIT: // triggers when you press the x on the top right of the window
		isRunning = false;
		break;
	default:
		break;
	}
}

void Engine::update()
{
	manager.update(); // this will update all components on every entity
}

void Engine::render()
{
	// function details
		// the renderer is essentially a canvas
		// you would erase everything off the canvas first
		// then draw each item
		// and lastly present the canvas to the user

	SDL_RenderClear(renderer); // clear out render buffer
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	manager.draw();
	SDL_RenderPresent(renderer);
}

void Engine::close()
{
	// function details
		// essential SDL items are destroyed here and SDL itself is quit
		// after that each thing that is dynamic memory needs to be dealt with


	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	std::cout << "Cleared memory." << std::endl;
}

bool Engine::running()
{
	return isRunning;
}