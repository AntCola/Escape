/*********************************************************************
** Program name: Attic.cpp
** Author: Anthony Colannino
** Date: 8/13/2019
** Description: The attic class is derived from the space class.
** It contains the attic game space and an overriden interact function
** from the space class.
*********************************************************************/

#include "Attic.hpp"

/****************************************************
*				Attic::Attic	
* Attic constructor that will initialize the room
* name to attic.
****************************************************/
Attic::Attic()
{
	roomName = "Attic";
}

/****************************************************
*				Attic::interact
* Overriden function from the space class that 
* will give the user options to interact with
* the properties of the attic room.
****************************************************/
int Attic::interact()
{
	std::cout << "There is only a dusty wardrobe in the corner of the Attic." << std::endl;
	int userChoice = getNum("Enter '1' to search the wardrobe or '2' to move on.", 1, 2);
	if (userChoice == 1) //Wardrobe search
	{
		numSteps++;
		std::cout << "Unfortunately you have wasted your time in the attic and you do not find any keys." << std::endl;
		std::cout << "You make your way back to the living room." << std::endl;
	}
	else //Doesn't waste time in attic
	{
		std::cout << "Good choice. There are no key's in the attic and you would of wasted a step." << std::endl;
		std::cout << "You make your way back to the living room." << std::endl;
	}
	return numSteps;
}