#include "pch.h"
#include "Combat.h"
#include "Player.h"

//Global Variable
bool _combatActive = false;

// Childs
Combat::Combat()
{
	_position = { 1200 , 800 };
	_size = { 340 , 80 };
}

Combat::~Combat()
{

}

bool Combat::getCombatActive() const
{
	return _active;
}

void Combat::setCombatActive(bool active)
{
	_active = active;
}

Vector2 Combat::getPosition() const
{
	return _position;
}
void Combat::setPosition(Vector2 position)
{
	_position = position;
}

Vector2 Combat::getSize() const
{
	return _size;
}

void Combat::setSize(Vector2 size)
{
	_size = size;
}

void Combat::enemyText()
{
	DrawRectangle(getPosition().x, getPosition().y, getSize().x, getSize().y, SKYBLUE);

	DrawText("You are facing a Spearman!", getPosition().x + 25, getPosition().y + 5, 10, BLACK);
	DrawText("What do you do?", getPosition().x + 25, getPosition().y + 15, 10, BLACK);
	DrawText("Press [A] to Fight", getPosition().x + 25, getPosition().y + 25, 10, BLACK);
	DrawText("Press [S] to Run", getPosition().x + 25, getPosition().y + 35, 10, BLACK);
}

void Combat::bossText()
{
	DrawRectangle(getPosition().x, getPosition().y, getSize().x, getSize().y, SKYBLUE);

	DrawText("You are facing a Armoured Demon!", getPosition().x + 25, getPosition().y + 5, 10, BLACK);
	DrawText("What do you do?", getPosition().x + 25, getPosition().y + 15, 10, BLACK);
	DrawText("Press [A] to Fight", getPosition().x + 25, getPosition().y + 25, 10, BLACK);
	DrawText("Press [S] to Run", getPosition().x + 25, getPosition().y + 35, 10, BLACK);
}

void Combat::folkText()
{
	DrawRectangle(getPosition().x, getPosition().y, getSize().x, getSize().y, SKYBLUE);

	DrawText("You encounter a Farmer", getPosition().x + 25, getPosition().y + 5, 10, BLACK);
	DrawText("What do you do?", getPosition().x + 25, getPosition().y + 15, 10, BLACK);
	DrawText("Press [A] to Trade", getPosition().x + 25, getPosition().y + 25, 10, BLACK);
	DrawText("Press [S] to Walk Away", getPosition().x + 25, getPosition().y + 35, 10, BLACK);
}

void Combat::combatAttack()
{
		DrawText("You charge at the Enemy", getPosition().x + 25, getPosition().y + 55, 10, BLACK);
		DrawText("It was a tough fight but you manage to survive another day", getPosition().x + 25, getPosition().y + 65, 10, BLACK);
}

void Combat::combatRun()
{
	DrawText("You run on the opposite direction", getPosition().x + 25, getPosition().y + 55, 10, BLACK);
	DrawText("The enemy managed to hurt you while running away ", getPosition().x + 25, getPosition().y + 65, 10, BLACK);
}

void Combat::combatTrade()
{
	DrawText("You give the Peasant some gold", getPosition().x + 25, getPosition().y + 55, 10, BLACK);
	DrawText("The Peasant show you gratitud by giving you an item ", getPosition().x + 25, getPosition().y + 65, 10, BLACK);
}

void Combat::combatWalkAway()
{
	DrawText("The Peasent seem to dirty", getPosition().x + 25, getPosition().y + 55, 10, BLACK);
	DrawText("TYou turn round and walk away from the Peasant", getPosition().x + 25, getPosition().y + 65, 10, BLACK);

}