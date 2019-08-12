#include "Kitchen.hpp"

Kitchen::Kitchen()
{
	goldPieces = 50;
	roomName = "Kitchen";
}

void Kitchen::interact()
{
	if (!hasLivingKey)
	{
		int userChoice = getNum("Enter '1' to check the cabinets for the key to the living room, or '2' to check the closet.", 1, 2);
		if (userChoice == 1)
		{
			std::cout << "You check the cabinet, but to your dissapointment you have not found the key." << std::endl;
			std::cout << "The only other option is to check the closet" << std::endl;
			std::cout << "After checking the closet, you have found the key and are able to move to the living room." << std::endl;
			inventory.push_back("Living Room Key");
			numSteps++;
			hasLivingKey = true;
		}
		else
		{
			std::cout << "You check the closet, and you find the key to the living room! You make your way into the living room." << std::endl;
			inventory.push_back("Living Room Key");
			numSteps++;
			hasLivingKey = true;
		}
	}
	else
	{
		std::cout << "You hvae all available keys in this room, there is nothing to search for." << std::endl;
	}
}

