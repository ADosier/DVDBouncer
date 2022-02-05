#ifndef POSITION_COMPONENT_H
#define POSITION_COMPONENT_H

#include "Components.h"

//========================================
//	Description:	This is a position component that just keeps track 
//					of an object's position within a 2D positional system (x and y coordinates)
//========================================
class PositionComponent : public Component
{
public:
	PositionComponent()
	{
		xpos = 0;
		ypos = 0;
	}
	PositionComponent(int x, int y) 
	{
		xpos = x;
		ypos = y;
	}
	void update() override
	{
	}
	int x() { return xpos; }
	void x(int x) { xpos = x; }
	int y() { return ypos; }
	void y(int y) { ypos = y; }
	void setPos(int x, int y) { xpos = x; ypos = y; }
private:
	int xpos;
	int ypos;
};


#endif
