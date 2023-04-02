#pragma once
#include "World.h"
class Building :
    public World
{
    private:
	Vector2 _position;
	Vector2 _size;
	Rectangle _drawSize;

public:
	Building();
	~Building();
};

