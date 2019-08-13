/*********************************************************************
** Program name: LivingRoom.hpp
** Author: Anthony Colannino
** Date: 8/13/2019
** Description: Header file for LivingRoom.cpp
*********************************************************************/

#ifndef LIVINGROOM_HPP
#define LIVINGROOM_HPP
#include "Space.hpp"
#include <iostream>

class LivingRoom : public Space
{
public:
	LivingRoom();
	int interact();
};

#endif
