#ifndef GAME_HPP
#define GAME_HPP
#include "Space.hpp"
#include "Patio.hpp"
#include "Bedroom.hpp"
#include "Office.hpp"
#include "Attic.hpp"
#include "LivingRoom.hpp"
#include "Kitchen.hpp"
#include <vector>
#include <iostream>


class Game
{
private:
	std::vector<Space*> listPtrs;
public:
	Game();
	void printPtrs();
	
};

#endif
