#ifndef POSITION_COMPONENT_H
#define POSITION_COMPONENT_H

#include "Components.h"
#include "Vector2D.h"

//========================================
//	Description:	This is a Transform component that just keeps track of the following
//					-position
//					-scale
//					-rotation
//========================================
class TransformComponent : public Component
{
public:
	Vector2D position;
	Vector2D velocity;

	int speed;


	TransformComponent	()
	{
		position.x = 0.0f;
		position.y = 0.0f;
	}
	TransformComponent	(float x, float y)
	{
		position.x = x;
		position.y = y;
	}
	void init() override
	{
		velocity.x = 0;
		velocity.y = 0;
	}
	void	update				() override
	{
		// if the velocity is antyhing but 0, the entity will move that direction every tick
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}
};


#endif
