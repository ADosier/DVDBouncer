#ifndef ENGINE_H
#define ENGINE_H

#include <iostream> // for console error messages

#include <SDL.h>
#include <SDL_image.h>

class Engine
{
public:
	Engine();
	~Engine();
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscr);
	void handleEvents();	//
	void update();			// Lifeline of the program loop
	void render();			//
	void close();
	bool running();

	static SDL_Renderer* renderer;

private:
	void initObjects();

	bool isRunning;
	SDL_Window* window;
};

#endif
