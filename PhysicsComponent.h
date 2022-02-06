#ifndef PHYSICS_COMPONENT_H
#define PHYSICS_COMPONENT_H

#include "Components.h"

class PhysicsComponent : public Component
{
private:
	TransformComponent* transform;
	// velocity
	float xvel;
	float yvel;
	float gravity;

public:
	PhysicsComponent(float Xvel = 0.0, float Yvel = 0.0, float g = 0.0)
	{
		// initalize startig velocities and the gravity of the object
		xvel = Xvel;
		yvel = Yvel;
		gravity = g;
	}
	void init() override // generic values for the initial creation
	{
		transform = &entity->getComponent<TransformComponent>();
	}
	void update() override
	{
		// update physics sutuff
		int width = 500;
		int height = 500;
		int mapH = 960;
		int mapW = 960;
		int x = transform->position.x;
		int y = transform->position.y;
		if ((y > mapH-height) || (y < 0))
		{
			// bounce on top and bottom
			yvel = -yvel;
		}
		if ((x > (mapW - width))|| (x < 0))
		{
			// bounce on left and right
			xvel = -xvel;
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