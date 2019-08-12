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
	gameLost = false;
	gameWon = false;
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

bool Space::checkInventory(std::string item)
{
	bool containsItem = false;
	if (std::find(inventory.begin(), inventory.end(), item) != inventory.end())
	{
		containsItem = true;
	}
	else
	{
		std::cout << "The user does not have " << item << " in their inventory." << std::endl;
		containsItem = false;
	}
}