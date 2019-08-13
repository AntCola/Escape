/*********************************************************************
** Program name: Patio.hpp
** Author: Anthony Colannino
** Date: 8/13/2019
** Description: Header file for Patio.cpp
*********************************************************************/

#ifndef PATIO_HPP
#define PATIO_HPP
#include "Space.hpp"
#include <iostream>

class Patio : public Space
{
public:
	Patio();
	int interact();
};

#endif

