#include "Office.hpp"

Office::Office()
{
	goldPieces = 25;
	roomName = "Office";
}

int Office::interact()
{
	if (!hasBedroomKey && !hasPatioKey)
	{
		int userChoice = getNum("Enter '1' to check the desk for a key or '2' to check the trophy cabinet for a key.", 1, 2);
		if (userChoice == 1)
		{
			std::cout << "You search the desk for a key and find a key to the bedroom." << std::endl;
			inventory.push_back("Bedroom Key");
			numSteps++;
			hasBedroomKey = true;

			int userChoice2 = getNum("Enter '1' to keep searching for more or '2' to move on.", 1, 2);

			if (userChoice2 == 1)
			{
				std::cout << "You have chosen to keep searching." << std::endl;
				std::cout << "The only place left to check is the trophy cabinet, where you find the key to the patio." << std::endl;
				numSteps++;
				hasPatioKey = true;
				inventory.push_back("Patioo Key");
			}
			else
			{
				std::cout << "You have chose to continue without searching the office more." << std::endl;
			}
		}
		else
		{
			std::cout << "You search the trophy cabinet and find a key to the patio." << std::endl;
			numSteps++;
			inventory.push_back("Patio Key");
			hasPatioKey = true;

			int userChoice3 = getNum("Enter '1' to keep searching for more or '2' to move on.", 1, 2);

			if (userChoice3 == 1)
			{
				std::cout << "You have chosen to keep searching." << std::endl;
				std::cout << "The only place left to check is the desk, where youo find a key to the bedroom." << std::endl;
				numSteps++;
				inventory.push_back("Bedroom Key");
				hasBedroomKey = true;
			}
			else
			{
				std::cout << "You have chosen to move on." << std::endl;
			}
			
		}
	}

	else if (hasBedroomKey && !hasPatioKey)
	{
		std::cout << "You already have the bedroom key and there is one place left to look." << std::endl;
		std::cout << "You search the trophy cabinet and find the patio key." << std::endl;
		numSteps++;
		hasPatioKey = true;
	}

	else if (!hasBedroomKey && hasPatioKey)
	{
		std::cout << "You already have the patio key and there is only one place left to look." << std::endl;
		std::cout << "You search the desk to find the bedroom key." << std::endl;
		numSteps++;
		hasBedroomKey = true;
	}

	else if (hasBedroomKey && hasPatioKey)
	{
		std::cout << "There is nothing left to find in this room." << std::endl;
	}

	return numSteps;
}

