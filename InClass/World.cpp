#include "pch.h"
#include "World.h"

// Childs 
World* worldGreen = new World();
World* worldYellow = new World();
World* worldBlue = new World();
World* worldBrown = new World();
World* worldDeep = new World();
World* worldGrass = new World();
World* worldFix = new World();
World* worldShip = new World();

World::World()
{

}

World::~World()
{

}


Texture2D World::getTexture() const
{
	return _texture;
}

void World::setTexture(Texture2D texture)
{
	_texture = texture;
}

Rectangle World::getRectangle() const
{
	return _rectangle;
}

void World::setRectangle(Rectangle rectangle)
{
	_rectangle = rectangle;
}


Vector2 World::getPosition() const
{
	return _position;
};

void World::setPosition(Vector2 position)
{
	_position = position;
};

Vector2 World::getSize() const
{
	return _size;
}

void World::setSize(Vector2 size)
{
	_size = size;
}

Rectangle World::getDrawSize() const
{
	return _drawSize;
}

void World::setDrawSize(Rectangle drawSize)
{
	_drawSize = drawSize;
}

void World::worldDraw()
{
	// Rectangles
	Rectangle recGround{ 0, 0, 100, 100 };
	worldGreen->setRectangle(recGround);

	Rectangle recBeach{ 0, 0, 60, 100 };
	worldBlue->setRectangle(recBeach);

	Rectangle recSand{ 0, 0, 10, 20 };
	worldBrown->setRectangle(recSand);

	Rectangle recWater{ 0, 47, 4, 10 };
	worldDeep->setRectangle(recWater);

	Rectangle recGrass{ 0, 0, 50, 50 };
	worldGrass->setRectangle(recGrass);

	Rectangle recShip{ 0, 0, 40, 30 };
	worldShip->setRectangle(recShip);

	// World Background	
	// - Green Grass
	DrawTextureTiled(worldGreen->getTexture(), worldGreen->getRectangle(), Rectangle{150, 0, 1050, 200}, {0, 0}, 0, 1, {255, 255, 255, 255});
	DrawTextureTiled(worldGreen->getTexture(), worldGreen->getRectangle(), Rectangle{ 150, 200, 870, 300 }, { 0, 0 }, 0, 1, { 255, 255, 255, 255 });
	DrawTextureTiled(worldGreen->getTexture(), worldGreen->getRectangle(), Rectangle{ 150, 500, 670, 200 }, { 0, 0 }, 0, 1, { 255, 255, 255, 255 });
	// - Dead Grass
	DrawTextureTiled(worldYellow->getTexture(), worldGreen->getRectangle(), Rectangle{0, 0, 150, 700}, {0, 0}, 0, 1, {255, 255, 255, 255});
	DrawTextureTiled(worldYellow->getTexture(), worldGreen->getRectangle(), Rectangle{ 0, 700, 750, 100 }, { 0, 0 }, 0, 1, { 255, 255, 255, 255 });
	DrawTextureTiled(worldYellow->getTexture(), worldGreen->getRectangle(), Rectangle{ 750, 700, 280, 100 }, { 0, 0 }, 0, 1, { 255, 255, 255, 255 });
	DrawTextureTiled(worldYellow->getTexture(), worldGreen->getRectangle(), Rectangle{ 750, 500, 280, 200 }, { 0, 0 }, 0, 1, { 255, 255, 255, 255 });
	DrawTextureTiled(worldYellow->getTexture(), worldGreen->getRectangle(), Rectangle{ 570, 0, 280, 230 }, { 0, 0 }, 0, 1, { 255, 255, 255, 255 });
	DrawTextureTiled(worldYellow->getTexture(), worldGreen->getRectangle(), Rectangle{ 420, 160, 150, 70 }, { 0, 0 }, 0, 1, { 255, 255, 255, 255 });
	DrawTextureTiled(worldYellow->getTexture(), worldGreen->getRectangle(), Rectangle{ 800, 25, 110, 50 }, { 0, 0 }, 0, 1, { 255, 255, 255, 255 });
	DrawTextureTiled(worldYellow->getTexture(), worldGreen->getRectangle(), Rectangle{ 1000, 35, 200, 90 }, { 0, 0 }, 0, 1, { 255, 255, 255, 255 });
	// - Water
	DrawTextureTiled(worldBlue->getTexture(), worldBlue->getRectangle(), Rectangle{ 1020, 260, 60, 540 }, { 0, 0 }, 0, 1, { 255, 255, 255, 255 });
	DrawTextureTiled(worldBrown->getTexture(), worldDeep->getRectangle(), Rectangle{ 1080, 260, 120, 540 }, { 0, 0 }, 0, 1, { 255, 255, 255, 255 });
	DrawTextureTiled(worldBlue->getTexture(), worldBrown->getRectangle(), Rectangle{ 1020, 200, 50, 60 }, { 0, 0 }, 0, 1, { 255, 255, 255, 255 });
	DrawTextureTiled(worldBlue->getTexture(), worldBlue->getRectangle(), Rectangle{ 1170, 200, 200, 100 }, { 0, 0 }, 90, 1, { 255, 255, 255, 255 });
	// - Death Grass Details
	DrawTextureTiled(worldGrass->getTexture(), worldGrass->getRectangle(), Rectangle{ 10, 80, 140, 85 }, { 0, 0 }, 0, 1, { 255, 255, 255, 255 });
	DrawTextureTiled(worldGrass->getTexture(), worldGrass->getRectangle(), Rectangle{ 30, 510, 120, 45 }, { 0, 0 }, 0, 1, { 255, 255, 255, 255 });
	DrawTextureTiled(worldGrass->getTexture(), worldGrass->getRectangle(), Rectangle{ 350, 680, 135, 90 }, { 0, 0 }, 0, 1, { 255, 255, 255, 255 });
	DrawTextureTiled(worldGrass->getTexture(), worldGrass->getRectangle(), Rectangle{ 890, 450, 80, 180 }, { 0, 0 }, 0, 1, { 255, 255, 255, 255 });
	DrawTextureTiled(worldGrass->getTexture(), worldGrass->getRectangle(), Rectangle{ 700, 740, 100, 70 }, { 0, 0 }, 0, 1, { 255, 255, 255, 255 });
	// - Ships
	DrawTextureTiled(worldShip->getTexture(), worldShip->getRectangle(), Rectangle{ 1160, 400, 35, 30 }, { 0, 0 }, 90, 1, { 255, 255, 255, 255 });
	DrawTextureTiled(worldShip->getTexture(), worldShip->getRectangle(), Rectangle{ 1160, 740, 35, 30 }, { 0, 0 }, 45, 1, { 255, 255, 255, 255 });
	DrawTextureTiled(worldShip->getTexture(), worldShip->getRectangle(), Rectangle{ 1080, 530, 35, 30 }, { 0, 0 }, 0, 1, { 255, 255, 255, 255 });
}

void World::worldTexture()
{
	// World Background
	Texture2D greenGrass = LoadTexture("../assets/TexturedGrass.png");
	worldGreen->setTexture(greenGrass);

	Texture2D deathGrass = LoadTexture("../assets/DeadGrass.png");
	worldYellow->setTexture(deathGrass);

	Texture2D waterBeach = LoadTexture("../assets/Shore.png");
	worldBlue->setTexture(waterBeach);

	Texture2D sandBeach = LoadTexture("../assets/Cliff-Water.png");
	worldBrown->setTexture(sandBeach);

	Texture2D smallGrass = LoadTexture("../assets/TexturedGrass.png");
	worldGrass->setTexture(smallGrass);

	Texture2D boatShip = LoadTexture("../assets/PirateShip.png");
	worldShip->setTexture(boatShip);
}