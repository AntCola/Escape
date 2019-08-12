#include "Space.hpp"
#include <vector>
#include <iostream>

Space::Space()
{
	up = nullptr;
	down = nullptr;
	right = nullptr;
	left = nullptr;
	goldPieces = 0;
	roomName = "";
	hasLivingKey = false;
	hasBedroomKey = false;
	hasAtticKey = false;
	hasOfficeKey = false;
	hasPatioKey = false;
	numSteps = 0;
}

int Space::getGP()
{
	return goldPieces;
}

void Space::setRight(Space* obj)
{
	right = obj;
}

void Space::setLeft(Space* obj)
{
	left = obj;
}

void Space::setUp(Space* obj)
{
	up = obj;
}

void Space::setDown(Space* obj)
{
	down = obj;
}

Space* Space::getDown(Space* obj)
{
	return obj->down;
}

Space* Space::getUp(Space* obj)
{
	return obj->up;
}

Space* Space::getRight(Space* obj)
{
	return obj->right;
}

Space* Space::getLeft(Space* obj)
{
	return obj->left;
}

std::string Space::getRoom()
{
	return roomName;
}


int Space::getNumSteps()
{
	return numSteps;
}

bool Space::getLivingKey()
{
	return hasLivingKey;
}

bool Space::getAtticKey()
{
	return hasAtticKey;
}

bool Space::getOfficeKey()
{
	return hasOfficeKey;
}

bool Space::getPatioKey()
{
	return hasPatioKey;
}

bool Space::getBedroomKey()
{
	return hasBedroomKey;
}