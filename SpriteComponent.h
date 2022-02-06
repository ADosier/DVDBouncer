#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include "Components.h"
#include "SDL.h"

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
		std::cout << "texture destroyed" << std::endl;
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
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
};
#endif