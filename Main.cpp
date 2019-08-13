/*********************************************************************
** Program name: Main.cpp
** Author: Anthony Colannino
** Date: 8/13/2019
** Description: Escape from Voldemort's Manor game is implemented
** in main.
*********************************************************************/

#include "Space.hpp"
#include "Game.hpp"
#include "Menu.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	//Set srand for rand()
	unsigned seed;
	seed = time(0);
	srand(seed);

	//Call menu for game
	menu();

	return 0;
}