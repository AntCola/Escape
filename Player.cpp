#include "Player.hpp"
#include <iostream>

Player::Player()
{
	inventory.reserve(5);
}

void Player::setUserLocation(Space* obj)
{
	userLocation = obj;
}

Space* Player::getUserLocation()
{
	return userLocation;
}

void Player::addInventory(std::string item)
{
	inventory.push_back(item);
}

void Player::printInventory()
{
	for (int i = 0; i < inventory.size(); i++)
	{
		std::cout << inventory[i] << std::endl;
	}
}