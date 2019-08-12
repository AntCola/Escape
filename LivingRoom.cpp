#include "LivingRoom.hpp"

LivingRoom::LivingRoom()
{
	goldPieces = 100;
	roomName = "Living Room";
}

int LivingRoom::interact()
{
	if (!hasAtticKey && !hasOfficeKey)
	{
		int userChoice = getNum("Enter '1' to check the TV stand for a key, '2' to check the coffee table, or '3' to check the sofa.", 1, 3);

		if (userChoice == 1)
		{
			std::cout << "After looking through the drawers in the TV stand you stumble across a key to the attic." << std::endl;
			inventory.push_back("Attic Key");
			numSteps++;
			hasAtticKey = true;
			int userChoice2 = getNum("Enter '1' to keep looking for another key, or '2' to move on.", 1, 2);
			if (userChoice2 == 1)
			{
				int userChoice3 = getNum("You have chosen to keep looking. Enter '1' to search the coffee table or '2' to check the sofa", 1, 2);
				if (userChoice3 == 1)
				{
					std::cout << "You have chosen to look through the coffee table.  You fail to find a key." << std::endl;
					numSteps++;
					int userChoice4 = getNum("Enter '1' to keep looking for a key or '2' to move on.", 1, 2);
					if (userChoice == 1)
					{
						std::cout << "The only place left to check is the sofa, which is where you find a key to the office." << std::endl;
						inventory.push_back("Office Key");
						numSteps++;
						hasOfficeKey = true;
					}
					else
					{
						std::cout << "You have chosen to move on without searching for more keys." << std::endl;
					}
				}
				else
				{
					std::cout << "You have chosen to look through the sofa.  You find the key to the office." << std::endl;
					numSteps++;
					inventory.push_back("Office Key");
					hasOfficeKey = true;
				}
			}
			else
			{
				std::cout << "You have chosen to move on without searching for more keys." << std::endl;
			}
		}
		else if (userChoice == 2)
		{
			std::cout << "You have chosen to check the coffee table.  You fail to find a key." << std::endl;
			numSteps++;
				int userChoice3 = getNum("Enter '1' to search the TV stand or '2' to search the sofa.", 1, 2);
				if (userChoice3 == 1)
				{
					std::cout << "You have chosen to search the TV stand. You have found a key to the attic." << std::endl;
					numSteps++;
					inventory.push_back("Attic Key");
					hasAtticKey = true;
					int userChoice4 = getNum("Enter '1' to continue searching for another key or '2' to move on.", 1, 2);
					if (userChoice4 == 1)
					{
						std::cout << "The only place left to check is the sofa, and you find a key to the office in the sofa." << std::endl;
						numSteps++;
						inventory.push_back("Office Key");
						hasOfficeKey = true;
					}
					else
					{
						std::cout << "You have chosen to move on without searching for more keys." << std::endl;
					}
				}
				else
				{
					std::cout << "You have chosen to search the sofa. You have found a key to the office." << std::endl;
					numSteps++;
					inventory.push_back("Office Key");
					hasOfficeKey = true;
					int userChoice4 = getNum("Enter '1' to continue searching for another key or '2' to move on.", 1, 2);
					if (userChoice4 == 1)
					{
						std::cout << "The only place left to check is the TV stand, and you find a key to the attic in the TV stand." << std::endl;
						numSteps++;
						inventory.push_back("Attic Key");
						hasAtticKey = true;
					}
					else
					{
						std::cout << "You have chosen to move on without searching for more keys." << std::endl;
					}
				}
			
		}
		else if (userChoice == 3)
		{
			std::cout << "You have chosen to check the sofa. You find a key to the office." << std::endl;
			numSteps++;
			inventory.push_back("Office Key");
			hasOfficeKey = true;
			int userChoice2 = getNum("Enter '1' to keep looking for another key, or '2' to move on.", 1, 2);
			if (userChoice2 == 1)
			{
				int userChoice3 = getNum("You have chosen to keep looking. Enter '1' to check the TV stand or '2' to check the coffee table.", 1, 2);
				if (userChoice3 == 1)
				{
					std::cout << "You have chosen to check the TV stand and find a key to the attic." << std::endl;
					numSteps++;
					inventory.push_back("Attic Key");
					hasAtticKey = true;
				}
				else
				{
					std::cout << "You have chosen to check the coffee table and fail to find a key." << std::endl;
					numSteps++;
					int userChoice4 = getNum("Enter '1' to keep searching for another key or '2' to move on.", 1, 2);
					if (userChoice4 == 1)
					{
						numSteps++;
						std::cout << "The only place left to check is the TV stand and you find a key to the attic." << std::endl;
						inventory.push_back("Attic Key");
						hasAtticKey = true;
					}
					else
					{
						std::cout << "You have chosen to move on without searching for more keys." << std::endl;
					}
				}
			}
		}
	}

	else if (hasAtticKey && !hasOfficeKey)
	{
		std::cout << "You already have the attic key. You must search for a key to the office. " << std::endl;
		int userChoice = getNum("Enter '1' to search the coffee table or '2' to search the sofa.", 1, 2);
		if (userChoice == 1)
		{
			std::cout << "You have chosen to search the coffee table and fail to find a key." << std::endl;
			numSteps++;
			std::cout << "The only place left to check is the sofa, where you end up finding the key for the office." << std::endl;
			numSteps++;
			inventory.push_back("Office Key");
			hasOfficeKey = true;
		}
		else
		{
			std::cout << "You have chosen to search the sofa. You find the office key." << std::endl;
			numSteps++;
			inventory.push_back("Office Key");
			hasOfficeKey = true;
		}
	}

	else if (!hasAtticKey && hasOfficeKey)
	{
		std::cout << "You already have the office key. Would you like to keep continuing to search for another key?" << std::endl;
		int userChoice = getNum("Enter '1' to keep searching for a key or '2' to move on.", 1, 2);
		if (userChoice == 1)
		{
			int userChoice2 = getNum("Enter '1' to check the TV stand or '2' to check the coffee table.", 1, 2);
			if (userChoice2 == 1)
			{
				std::cout << "You check the TV stand and find a key to the attic." << std::endl;
				numSteps++;
				inventory.push_back("Attic Key");
				hasAtticKey = true;
			}
			else
			{
				std::cout << "You check the coffee table and fail to find anything." << std::endl;
				numSteps++;
				int userChoice3 = getNum("Enter '1' to keep searching or '2' to move on.", 1, 2);
				if (userChoice3 == 1)
				{
					std::cout << "The last place left to check is the TV stand, where you find a key to the attic." << std::endl;
					numSteps++;
					inventory.push_back("Attic Key");
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

	else if (hasAtticKey && hasOfficeKey)
	{
		std::cout << "You have all possible keys from this room." << std::endl;
	}

	return numSteps;
}

