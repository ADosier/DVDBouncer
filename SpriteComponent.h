#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include "Components.h"
#include "SDL.h"

#include "Rando.h" // allows you to set a sprite to a random color

class SpriteComponent : public Component
{
public:
	SpriteComponent() = default;
	SpriteComponent(const char* path, int srcrectH = 32, int srcrectW = 32)
	{
		texture = TextureManager::LoadTexture(path);
		srcRect.x = srcRect.y = 0;
		
		srcRect.w = srcrectW;
		srcRect.h = srcrectH;

		destRect.w = srcrectW;
		destRect.h = srcrectH;

	}
	~SpriteComponent()
	{
		SDL_DestroyTexture(texture);
	}
	void init() override // generic values for the initial creation
	{
		transform = &entity->getComponent<TransformComponent>();
		
	}

	void update() override
	{
		destRect.x = (int)transform->position.x;
		destRect.y = (int)transform->position.y;
	}

	void draw() override
	{
		TextureManager::Draw(texture, srcRect, destRect);
	}

	void setRandomColor()
	{
		int r = rand.getRand(0, 255);
		int g = rand.getRand(0, 255);
		int b = rand.getRand(0, 255);
		SDL_SetTextureColorMod(texture, r, g, b);
	}

	SDL_Rect getSrcDim()
	{
		return destRect; // returns a copy of the rect to relay dimension data
	};
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

	Rando rand;
};
#endif