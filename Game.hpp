/*********************************************************************
** Program name: Game.hpp
** Author: Anthony Colannino
** Date: 8/13/2019
** Description: Header file for Game.cpp.
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP
#include "Space.hpp"
#include "Patio.hpp"
#include "Bedroom.hpp"
#include "Office.hpp"
#include "Attic.hpp"
#include "LivingRoom.hpp"
#include "Kitchen.hpp"
#include <vector>
#include <iostream>

class Game
{
private:
	std::vector<Space*> listPtrs;
	Space* kitchenPtr;
	Space* livingRoomPtr;
	Space* atticPtr;
	Space* officePtr;
	Space* bedroomPtr;
	Space* patioPtr;
	int totalSteps;
	bool gameWon;
	bool gameLost;
public:
	Game();
	~Game();
	void printPtrs();
	void gameFlow();
	void setGameWon(bool);
	void setGameLost(bool);
	
};

#endif
