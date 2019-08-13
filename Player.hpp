/*********************************************************************
** Program name: Player.hpp
** Author: Anthony Colannino
** Date: 8/13/2019
** Description: Header file for Player.cpp
*********************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Space.hpp"
#include "Attic.hpp"
#include "Bedroom.hpp"
#include "Game.hpp"
#include "Kitchen.hpp"
#include "LivingRoom.hpp"
#include "Office.hpp"
#include "Patio.hpp"

class Player
{
private:
	Space* userLocation;
	std::vector<std::string> inventory;
public:
	Player();
	void setUserLocation(Space*);
	Space* getUserLocation();
	void addInventory(std::string);
	void printInventory();
};

#endif
