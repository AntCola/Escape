/*********************************************************************
** Program name: Bedroom.hpp
** Author: Anthony Colannino
** Date: 8/13/2019
** Description: Header file for Bedroom.cpp.
*********************************************************************/

#ifndef BEDROOM_HPP
#define BEDROOM_HPP
#include "Space.hpp"
#include <iostream>

class Bedroom : public Space
{
private:
public:
	Bedroom();
	int interact();
};

#endif
