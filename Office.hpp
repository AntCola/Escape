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
