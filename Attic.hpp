/*********************************************************************
** Program name: Attic.hpp
** Author: Anthony Colannino
** Date: 8/13/2019
** Description: Header file for Attic.cpp
*********************************************************************/

#ifndef ATTIC_HPP
#define ATTIC_HPP
#include "Space.hpp"
#include <iostream>

class Attic : public Space
{
public:
	Attic();
	int interact();
};

#endif
