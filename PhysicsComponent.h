#ifndef PHYSICS_COMPONENT_H
#define PHYSICS_COMPONENT_H

#include "Components.h"

class PhysicsComponent : public Component
{
private:
	TransformComponent* transform;
	SpriteComponent* sprite;
	
	// velocity
	float		xvel;
	float		yvel;

	// imageRect is dimensions of the sprite that will bounce around
	SDL_Rect	imageRect;
	int			windowH = 1080;
	int			windowW = 1920;

public:
	PhysicsComponent(float Xvel = 0.0, float Yvel = 0.0, float g = 0.0)
	{
		// initalize startig velocities and the gravity of the object
		xvel = Xvel;
		yvel = Yvel;
	}
	void init() override // generic values for the initial creation
	{
		transform = &entity->getComponent<TransformComponent>();
		sprite = &entity->getComponent<SpriteComponent>();
		
		imageRect = sprite->getSrcDim();;
	}
	void update() override
	{
		// This only performs bouncing for the DVD logo for now
		

		int x = transform->position.x;
		int y = transform->position.y;

		if ((y > (windowH - imageRect.h)) || (y < 0))
		{
			// bounce on top and bottom
			yvel = -yvel;
			sprite->setRandomColor();
		}
		if ((x > (windowW - imageRect.w))|| (x < 0))
		{
			// bounce on left and right
			xvel = -xvel;
			sprite->setRandomColor();
		}
			
		// increment position based on velocity
		int tempx = x;
		tempx += xvel;
		transform->position.x = tempx;

		int tempy = y;
		tempy += yvel;
		transform->position.y = tempy;
	}
};


#endif