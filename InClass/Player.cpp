#include "pch.h"
#include "Player.h"

Player::Player()
{
	_position = { 0 , 0 };

	// Stats
	_attack = 10;
	_lifePoints = 50;
	_gold = 18;
};

Player :: ~Player()
{

};

Vector2 Player::getPosition() const
{
	return _position;
};

void Player::setPosition(Vector2 position)
{
	_position = position;
};

Rectangle Player::getRectangle() const
{
	return _rectangle;
}

void Player::setRectangle(Rectangle rectangle)
{
	_rectangle = rectangle;
}

Texture2D Player::getTexture() const
{
	return _texture;
}
void Player::setTexture(Texture2D texture)
{
	_texture = texture;
}

int Player::getLife() const
{
	return _lifePoints;
}

void Player::setLife(int lifePoints)
{
	_lifePoints = lifePoints;
}

int Player::getAttack() const
{
	return _attack;
}

void Player::setAttack(int attack)
{
	_attack = attack;
}

// Childs
// Avatar
Avatar::Avatar()
{
	Vector2 avatarPos = { 1000 , 70 };
	setPosition(avatarPos);

	Rectangle recChar{ 0, 0, 15, 15 };
	setRectangle(recChar);

	_attack = 10;
	_lifePoints = 1000;
	_gold = 25;

}

Avatar::~Avatar()
{

}

int Avatar::getGold() const
{
	return _gold;
}

void Avatar::setGold(int gold)
{
	_gold = gold;
}

// NPCs
NPC::NPC()
{
	_active = true;
	_speed = 1;
	_size = { 15 , 15 };
}

NPC::~NPC()
{

}

bool NPC::getStatus() const
{
	return _active;
}

void NPC::setStatus(bool active)
{
	_active = active;
}

int NPC::getSpeed() const
{
	return _speed;
}

Vector2 NPC::getSize() const
{
	return _size;
}

void NPC::setSize(Vector2 size)
{
	_size = size;
}

Rectangle NPC::getDrawSize() const
{
	return _drawSize;
}

void NPC::setDrawSize(Rectangle drawSize)
{
	_drawSize = drawSize;
}

// NPC's Childs
Enemy::Enemy()
{
	_lifePoints = 25;
	_attack = 5;

	Rectangle drawSize{ 0, 0, 15, 15 };
	setDrawSize(drawSize);
}

Enemy::~Enemy()
{

}

Folk::Folk()
{
	Rectangle drawSize{ 0, 0, 15, 15 };
	setDrawSize(drawSize);
}

Folk::~Folk()
{

}

Boss::Boss()
{
	Vector2 _bossSize = { 25 , 25 };
	setSize(_bossSize);
	Rectangle drawSize{ 0, 0, 15, 15 };
	setDrawSize(drawSize);
}

Boss::~Boss()
{

}