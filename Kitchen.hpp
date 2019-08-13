/*********************************************************************
** Program name: Kitchen.hpp
** Author: Anthony Colannino
** Date: 8/13/2019
** Description: Header file for Kitchen.cpp
*********************************************************************/

#ifndef KITCHEN_HPP
#define KITCHEN_HPP
#include "Space.hpp"
#include <iostream>
#include <string>

class Kitchen : public Space
{
public:
	Kitchen();
	int interact();
};

#endif 
