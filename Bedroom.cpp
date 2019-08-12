#include "Bedroom.hpp"

Bedroom::Bedroom()
{
	goldPieces = 100;
	roomName = "Bedroom";
}

void Bedroom::interact()
{
	std::cout << "You have entered the bedroom and there is nothing to find here. You have wasted 3 steps." << std::endl;
	numSteps += 3;
}