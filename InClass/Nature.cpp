#include "pch.h"
#include "Nature.h"

Nature::Nature()
{

}

Nature::~Nature()
{

}

// - Water
Water::Water()
{
	Vector2 waterPos = { 1080 , 260 };
	setPosition(waterPos);

	Vector2 waterSize = { 120 , 540 };
	setSize(waterSize);

	Rectangle waterRec = { getPosition().x, getPosition().y, getSize().x, getSize().y };
	setRectangle(waterRec);

}

Water::~Water()
{

}

// - Rock
Rock::Rock()
{
	Rectangle drawSize{ 0, 50, 45, 50 };
	setDrawSize(drawSize);
}

Rock::~Rock()
{

}