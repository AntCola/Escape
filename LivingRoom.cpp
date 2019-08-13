/*********************************************************************
** Program name: LivingRoom.cpp
** Author: Anthony Colannino
** Date: 8/13/2019
** Description: The living room class is derived from the space
** class and holds a space in the manor for the user to interact
** with and search for a key.
*********************************************************************/

#include "LivingRoom.hpp"

/****************************************************
*				LivingRoom::LivingRoom
* LivingRoom constructor that sets room name.
****************************************************/
LivingRoom::LivingRoom()
{
	roomName = "Living Room";
}

/****************************************************
*				LivingRoom::LivingRoom
* Overriden interact function from space class that
* will allow for the user to search the room for keys.
****************************************************/
int LivingRoom::interact()
{
	if (!hasAtticKey && !hasOfficeKey) //Player has neither key
	{
		int userChoice = getNum("Enter '1' to check the TV stand for a key, '2' to check the coffee table, or '3' to check the sofa.", 1, 3);

		if (userChoice == 1) //Search TV stand
		{
			std::cout << "After looking through the drawers in the TV stand you stumble across a key to the attic." << std::endl;
			numSteps++;
			hasAtticKey = true;
			int userChoice2 = getNum("Enter '1' to keep looking for another key, or '2' to move on.", 1, 2);
			if (userChoice2 == 1) //Keep looking
			{
				int userChoice3 = getNum("You have chosen to keep looking. Enter '1' to search the coffee table or '2' to check the sofa", 1, 2);
				if (userChoice3 == 1) //Check coffee table
				{
					std::cout << "You have chosen to look through the coffee table.  You fail to find a key." << std::endl;
					numSteps++;
					int userChoice4 = getNum("Enter '1' to keep looking for a key or '2' to move on.", 1, 2);
					if (userChoice == 1) //Keep looking
					{
						std::cout << "The only place left to check is the sofa, which is where you find a key to the office." << std::endl;
						numSteps++;
						hasOfficeKey = true;
					}
					else //Move on
					{
						std::cout << "You have chosen to move on without searching for more keys." << std::endl;
					}
				}
				else //Look through sofa
				{
					std::cout << "You have chosen to look through the sofa.  You find the key to the office." << std::endl;
					numSteps++;
					hasOfficeKey = true;
				}
			}
			else //Move on
			{
				std::cout << "You have chosen to move on without searching for more keys." << std::endl;
			}
		}
		else if (userChoice == 2) //Check coffee table
		{
			std::cout << "You have chosen to check the coffee table.  You fail to find a key." << std::endl;
			numSteps++;
				int userChoice3 = getNum("Enter '1' to search the TV stand or '2' to search the sofa.", 1, 2);
				if (userChoice3 == 1) //TV stand check
				{
					std::cout << "You have chosen to search the TV stand. You have found a key to the attic." << std::endl;
					numSteps++;
					hasAtticKey = true;
					int userChoice4 = getNum("Enter '1' to continue searching for another key or '2' to move on.", 1, 2);
					if (userChoice4 == 1) //Keep searching, search sofa
					{
						std::cout << "The only place left to check is the sofa, and you find a key to the office in the sofa." << std::endl;
						numSteps++;
						hasOfficeKey = true;
					}
					else //Move on
					{
						std::cout << "You have chosen to move on without searching for more keys." << std::endl;
					}
				}
				else //Search sofa
				{
					std::cout << "You have chosen to search the sofa. You have found a key to the office." << std::endl;
					numSteps++;
					hasOfficeKey = true;
					int userChoice4 = getNum("Enter '1' to continue searching for another key or '2' to move on.", 1, 2);
					if (userChoice4 == 1) //Keep searching
					{
						std::cout << "The only place left to check is the TV stand, and you find a key to the attic in the TV stand." << std::endl;
						numSteps++;
						hasAtticKey = true;
					}
					else
					{
						std::cout << "You have chosen to move on without searching for more keys." << std::endl;
					}
				}
			
		}
		else if (userChoice == 3) //Search sofa
		{
			std::cout << "You have chosen to check the sofa. You find a key to the office." << std::endl;
			numSteps++;
			hasOfficeKey = true;
			int userChoice2 = getNum("Enter '1' to keep looking for another key, or '2' to move on.", 1, 2);
			if (userChoice2 == 1) //Search for another key
			{
				int userChoice3 = getNum("You have chosen to keep looking. Enter '1' to check the TV stand or '2' to check the coffee table.", 1, 2);
				if (userChoice3 == 1) //TV stand check
				{
					std::cout << "You have chosen to check the TV stand and find a key to the attic." << std::endl;
					numSteps++;
					hasAtticKey = true;
				}
				else //Coffee table check
				{
					std::cout << "You have chosen to check the coffee table and fail to find a key." << std::endl;
					numSteps++;
					int userChoice4 = getNum("Enter '1' to keep searching for another key or '2' to move on.", 1, 2);
					if (userChoice4 == 1) //Keep searching
					{
						numSteps++;
						std::cout << "The only place left to check is the TV stand and you find a key to the attic." << std::endl;
						hasAtticKey = true;
					}
					else //Move on
					{
						std::cout << "You have chosen to move on without searching for more keys." << std::endl;
					}
				}
			}
		}
	}

	else if (hasAtticKey && !hasOfficeKey) //Player has attic key but not office key
	{
		std::cout << "You already have the attic key. You must search for a key to the office. " << std::endl;
		int userChoice = getNum("Enter '1' to search the coffee table or '2' to search the sofa.", 1, 2);
		if (userChoice == 1) //Search coffee table
		{
			std::cout << "You have chosen to search the coffee table and fail to find a key." << std::endl;
			numSteps++;
			std::cout << "The only place left to check is the sofa, where you end up finding the key for the office." << std::endl;
			numSteps++;
			hasOfficeKey = true;
		}
		else //Search sofa
		{
			std::cout << "You have chosen to search the sofa. You find the office key." << std::endl;
			numSteps++;
			hasOfficeKey = true;
		}
	}

	else if (!hasAtticKey && hasOfficeKey) //Player has office key but not attic key
	{
		std::cout << "You already have the office key. Would you like to keep continuing to search for another key?" << std::endl;
		int userChoice = getNum("Enter '1' to keep searching for a key or '2' to move on.", 1, 2);
		if (userChoice == 1) //Search for key
		{
			int userChoice2 = getNum("Enter '1' to check the TV stand or '2' to check the coffee table.", 1, 2);
			if (userChoice2 == 1) //Search TV stand
			{
				std::cout << "You check the TV stand and find a key to the attic." << std::endl;
				numSteps++;
				hasAtticKey = true;
			}
			else //Search coffee table
			{
				std::cout << "You check the coffee table and fail to find anything." << std::endl;
				numSteps++;
				int userChoice3 = getNum("Enter '1' to keep searching or '2' to move on.", 1, 2);
				if (userChoice3 == 1) //Keep searching
				{
					std::cout << "The last place left to check is the TV stand, where you find a key to the attic." << std::endl;
					numSteps++;
					hasAtticKey = true;
				}
				else
				{
					std::cout << "You have chosen to move on." << std::endl;
				}
			}
		}
		else
		{
			std::cout << "You have chosen to move on." << std::endl;
		}
	}

	else if (hasAtticKey && hasOfficeKey) //User has both keys
	{
		std::cout << "You have all possible keys from this room." << std::endl;
	}

	return numSteps;
}

