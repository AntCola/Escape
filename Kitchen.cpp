/*********************************************************************
** Program name: Kitchen.cpp
** Author: Anthony Colannino
** Date: 8/13/2019
** Description: Kitchen class is derived from the space class and
** has an overidden interact function for the user to explore
** the room.
*********************************************************************/

#include "Kitchen.hpp"

/****************************************************
*				Kitchen::Kitchen
* Kitchen constructor that sets room name.
****************************************************/
Kitchen::Kitchen()
{
	roomName = "Kitchen";
}

/****************************************************
*				Kitchen::interact
* Overriden space function that will allow the
* user to search the kitchen and interact with it.
****************************************************/
int Kitchen::interact()
{
	if (!hasLivingKey)
	{
		int userChoice = getNum("Enter '1' to check the cabinets for the key to the living room, or '2' to check the closet.", 1, 2);
		if (userChoice == 1) //Look at cabinets
		{
			std::cout << "You check the cabinet, but to your dissapointment you have not found the key." << std::endl;
			std::cout << "The only other option is to check the closet" << std::endl;
			std::cout << "After checking the closet, you have found the key and are able to move to the living room." << std::endl;
			numSteps++;
			hasLivingKey = true;
		}
		else //Check closet
		{
			std::cout << "You check the closet, and you find the key to the living room! You make your way into the living room." << std::endl;
			numSteps++;
			hasLivingKey = true;
		}
	}
	else
	{
		std::cout << "You hvae all available keys in this room, there is nothing to search for." << std::endl;
	}
	return numSteps;
}

