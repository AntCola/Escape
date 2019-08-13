/*********************************************************************
** Program name: Bedroom.cpp
** Author: Anthony Colannino
** Date: 8/13/2019
** Description: The bedroom class is derived from Space and
** holds the bedroom space with overriden interact function from
** space class.
*********************************************************************/

#include "Bedroom.hpp"

/****************************************************
*				Bedroom::Bedroom
* Bedroom constructor that sets room name.
****************************************************/
Bedroom::Bedroom()
{
	roomName = "Bedroom";
}

/****************************************************
*				Bedroom::interact
* Overidden interact function that informs
* the user they have wasted their time.
****************************************************/
int Bedroom::interact()
{
	std::cout << "You have entered the bedroom and there is nothing to find here. You have wasted 3 steps." << std::endl;
	numSteps += 3;
	return numSteps;
}