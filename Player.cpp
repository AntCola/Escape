/*********************************************************************
** Program name: Player.cpp
** Author: Anthony Colannino
** Date: 8/13/2019
** Description: Player class that controls the player movements.
*********************************************************************/

#include "Player.hpp"
#include <iostream>

/****************************************************
*				Player::Player
* Player constructor that will initialize the vector
* for inventory to 5 max slot availability.
****************************************************/
Player::Player()
{
	inventory.reserve(5);
}

/****************************************************
*				Player::setUserLocation
* Setter for user location.
****************************************************/
void Player::setUserLocation(Space* obj)
{
	userLocation = obj;
}

/****************************************************
*				Player::getUserLocation
* Getter for user location.
****************************************************/
Space* Player::getUserLocation()
{
	return userLocation;
}

/****************************************************
*				Player::addInventory
* Function to add an item into the player's inventory.
****************************************************/
void Player::addInventory(std::string item)
{
	inventory.push_back(item);
}

/****************************************************
*				Player::printInventory
* A function to print the user's inventory.
****************************************************/
void Player::printInventory()
{
	for (int i = 0; i < inventory.size(); i++)
	{
		std::cout << inventory[i] << std::endl;
	}
}