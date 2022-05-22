#include "Engine.h"
#include "TextureManager.h"
#include "Components.h"
#include "Vector2D.h"

Manager manager;
SDL_Renderer*	Engine::renderer = nullptr;
SDL_Event		Engine::event;
// entities
auto& dvdLogo(manager.addEntity());
int counter = 0;

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

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC); // (window, int index, Uint32 flags)
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			// there are several tweaks to the renderer that can be made
			// this simply sets the draw color to black with no alpha mode set
			std::cout << "Renderer Created." << std::endl;
		}
		isRunning = true;
		initObjects(); // sets up all objects in the scene
	}
	else
	{
		// no objects are initalized because either the window or renderer failed on startup
		isRunning = false; 
	}
	return;
}

void Engine::initObjects()
{
	// This is where the game objects will be assembled one component at a time


	dvdLogo.addComponent<TransformComponent>(400,400);
	dvdLogo.addComponent<SpriteComponent>("assets/DVDlogo.png", 237, 512);
	dvdLogo.addComponent<PhysicsComponent>(5, -6, 0);

}

void Engine::handleEvents()
{
	// Description: This is where keyboard and mouse events are handled

	// function improvement
		// This function can be improved later by adding
		// a state system to poll for different events that happen one after another
	// function details
		// it simply runs a switch statement on an SDL_Event to trigger updates

	SDL_Event event;
	SDL_PollEvent(&event); // SDL sets our local event to what is currently happening.
	
	// simplified keyboad controller to allow you to exit on an ESC press (for fullscreen accessability)
	if (event.type == SDL_KEYDOWN) 
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			isRunning = false;
		}
	}
	
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
	// This phase will call update on all components attached to entities.
		// It is all done through the manager.update() function
		// all components may have overridden init, update, and draw functions to do extra steps


	// There needed to be a short delay so things have time to load in before movement happens
	// This will likely be removed as I move to a graphics card or have a different type of demo
	if (counter == 0)
	{
		manager.update();
		counter++;
	}
	if (counter < 50) // give the software 50 cycles to allow time for loading
		counter++;
	else
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
	//SDL_SetRenderDrawColor(renderer, 161, 161, 161, 255); // This will set a background color

	// This calls all of the overridden draw() functions in each component that has one
	// It paints the images on the renderer before it is presented
	manager.draw();
	
	SDL_RenderPresent(renderer); // flip the canvas around to display whatever resides in the renderer
}

void Engine::close()
{
	// essential SDL items free their memory here
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	// as SDL quits, each component that has memory 
	// allocated to resources call their deconstructor here to avoid memory leaks

	std::cout << "Cleared memory." << std::endl;
}

bool Engine::running()
{
	return isRunning;
}