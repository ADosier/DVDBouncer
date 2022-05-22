#pragma once

#include "Components.h"
#include <SDL.h>

class ScreenBounceLogic
{
private:
	//components of the bouncer
	TransformComponent* transform;
	SpriteComponent* sprite;

	// velocity
	float xvel;
	float yvel;

	SDL_Rect imageRect;
	int windowH = 1080;
	int windowW = 1920;

public:
	ScreenBounceLogic(float Xvel = 0.0, float Yvel = 0.0)
	{
		xvel = Xvel;
		yvel = Yvel;

	}
	void init(TransformComponent* t, SpriteComponent* s, int wW, int wH) // generic values for the initial creation
	{
		transform = t;
		sprite = s;
		windowW = wW;
		windowH = wH;
		imageRect = sprite->getSrcDim();;
	}
	void update()
	{
		int x = transform->position.x;
		int y = transform->position.y;

		if ((y > (windowH - imageRect.h)) || (y < 0))
		{
			// bounce on top and bottom
			yvel = -yvel;
			sprite->setRandomColor();
		}
		if ((x > (windowW - imageRect.w)) || (x < 0))
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