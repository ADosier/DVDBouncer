#include "TextureManager.h"
#include <iostream>

SDL_Texture* TextureManager::LoadTexture(const char* fileName)
{
	SDL_Surface* tempSurface = IMG_Load(fileName);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Engine::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	
	if (tex== nullptr)
	{
		std::cout << "TEXTURE MANAGER ERROR: file " << fileName << " does not exist!" << std::endl;
	}
	return tex;
}
void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Engine::renderer, tex, &src, &dest);
}