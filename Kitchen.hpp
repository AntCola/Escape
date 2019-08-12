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
