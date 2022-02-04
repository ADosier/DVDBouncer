// ==============================================================
// Name: Alec Dosier
// Date: 2/2022
// Description: A C++ foundation for graphical libraries
// ==============================================================


//#include "Engine.h" // Library for the engine
#include "SDL.h"

int main(int argc, char *argv[])
{

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 700, 500, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(3000);

	system("pause");
	return 0;
}
