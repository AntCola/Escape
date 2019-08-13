/*********************************************************************
** Program name: Office.cpp
** Author: Anthony Colannino
** Date: 8/13/2019
** Description: Office class derived from Space class that
** will hold the office space and allow for user interaction.
*********************************************************************/

#include "Office.hpp"

/****************************************************
*				Office::Office
* Office constructor for room name.
****************************************************/
Office::Office()
{
	roomName = "Office";
}

/****************************************************
*				Game::interact
* Overriden interact function from the space class
* allowing for the user to search the room.
****************************************************/
int Office::interact()
{
	if (!hasBedroomKey && !hasPatioKey) //User has neither key
	{
		int userChoice = getNum("Enter '1' to check the desk for a key or '2' to check the trophy cabinet for a key.", 1, 2);
		if (userChoice == 1) //Check desk
		{
			std::cout << "You search the desk for a key and find a key to the bedroom." << std::endl;
			numSteps++;
			hasBedroomKey = true;

			int userChoice2 = getNum("Enter '1' to keep searching for more or '2' to move on.", 1, 2);

			if (userChoice2 == 1) //Keep searching
			{
				std::cout << "You have chosen to keep searching." << std::endl;
				std::cout << "The only place left to check is the trophy cabinet, where you find the key to the patio." << std::endl;
				numSteps++;
				hasPatioKey = true;
			}
			else //Stop searching
			{
				std::cout << "You have chose to continue without searching the office more." << std::endl;
			}
		}
		else //Search trophy cabinet
		{
			std::cout << "You search the trophy cabinet and find a key to the patio." << std::endl;
			numSteps++;;
			hasPatioKey = true;

			int userChoice3 = getNum("Enter '1' to keep searching for more or '2' to move on.", 1, 2);

			if (userChoice3 == 1) //Keep searching
			{
				std::cout << "You have chosen to keep searching." << std::endl;
				std::cout << "The only place left to check is the desk, where youo find a key to the bedroom." << std::endl;
				numSteps++;
				hasBedroomKey = true;
			}
			else //Move on
			{
				std::cout << "You have chosen to move on." << std::endl;
			}
			
		}
	}

	else if (hasBedroomKey && !hasPatioKey) //User has bedroom key but not patio key
	{
		std::cout << "You already have the bedroom key and there is one place left to look." << std::endl;
		std::cout << "You search the trophy cabinet and find the patio key." << std::endl;
		numSteps++;
		hasPatioKey = true;
	}

	else if (!hasBedroomKey && hasPatioKey) //User has patio key but not bedroom key
	{
		std::cout << "You already have the patio key and there is only one place left to look." << std::endl;
		std::cout << "You search the desk to find the bedroom key." << std::endl;
		numSteps++;
		hasBedroomKey = true;
	}

	else if (hasBedroomKey && hasPatioKey) //User has both keys
	{
		std::cout << "There is nothing left to find in this room." << std::endl;
	}

	return numSteps;
}

