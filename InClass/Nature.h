#pragma once
#include "World.h"

class Nature : public World
{
private:

public:
	Nature();
	~Nature();
};

class Water : public Nature
{
private:

public:
	Water();
	~Water();
};

class Rock :public Nature
{
private:

public:
	Rock();
	~Rock();
};

