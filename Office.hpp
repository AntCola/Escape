/*********************************************************************
** Program name: Office.hpp
** Author: Anthony Colannino
** Date: 8/13/2019
** Description: Header file for Office.cpp
*********************************************************************/

#ifndef OFFICE_HPP
#define OFFICE_HPP
#include "Space.hpp"
#include <iostream>

class Office : public Space
{
public:
	Office();
	int interact();
};

#endif
