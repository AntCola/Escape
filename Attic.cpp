#include "Attic.hpp"

Attic::Attic()
{
	goldPieces = 10;
	roomName = "Attic";
}

int Attic::interact()
{
	std::cout << "There is only a dusty wardrobe in the corner of the Attic." << std::endl;
	int userChoice = getNum("Enter '1' to search the wardrobe or '2' to move on.", 1, 2);
	if (userChoice == 1)
	{
		numSteps++;
		std::cout << "Unfortunately you have wasted your time in the attic and you do not find any keys." << std::endl;
		std::cout << "You make your way back to the living room." << std::endl;
	}
	else
	{
		std::cout << "Good choice. There are no key's in the attic and you would of wasted a step." << std::endl;
		std::cout << "You make your way back to the living room." << std::endl;
	}
	return numSteps;
}