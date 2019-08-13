/*********************************************************************
** Program name: Menu.cpp
** Author: Anthony Colannino
** Date: 8/13/2019
** Description: Menu function to control the game so the user
** is able to start or quit after finish.
*********************************************************************/

#include "Menu.hpp"
#include "Game.hpp"
#include "getNum.hpp"

/****************************************************
*				Menu
* Menu function to control game flow.
****************************************************/
void menu()
{
	int userChoice = getNum("Enter '1' to start Escape from Voldemort's Manor game or '2' to exit.", 1, 2);

	while (userChoice == 1)
	{
		Game game1;
		game1.gameFlow();
		userChoice = getNum("Enter '1' to play again or '2' to quit.", 1, 2);
	}
}