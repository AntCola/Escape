#include "Game.hpp"
#include <vector>
#include <iostream>

Game::Game()
{
	Space* kitchenPtr = new Kitchen();
	Space* livingRoomPtr = new LivingRoom();
	Space* atticPtr = new Attic();
	Space* officePtr = new Office();
	Space* bedroomPtr = new Bedroom();
	Space* patioPtr = new Patio();

	kitchenPtr->setRight(livingRoomPtr);

	livingRoomPtr->setUp(atticPtr);
	livingRoomPtr->setLeft(kitchenPtr);
	livingRoomPtr->setRight(officePtr);

	atticPtr->setDown(livingRoomPtr);

	officePtr->setLeft(livingRoomPtr);
	officePtr->setUp(bedroomPtr);
	officePtr->setRight(patioPtr);

	bedroomPtr->setDown(officePtr);

	patioPtr->setLeft(officePtr);

	listPtrs.push_back(kitchenPtr);
	listPtrs.push_back(livingRoomPtr);
	listPtrs.push_back(atticPtr);
	listPtrs.push_back(officePtr);
	listPtrs.push_back(bedroomPtr);
	listPtrs.push_back(patioPtr);
	

}

void Game::printPtrs()
{
	for (int i = 0; i < listPtrs.size(); i++)
	{
		std::cout << "Up: " << listPtrs[i]->getUp(listPtrs[i]) << std::endl;
		std::cout << "Down: " << listPtrs[i]->getDown(listPtrs[i]) << std::endl;
		std::cout << "Right: " << listPtrs[i]->getRight(listPtrs[i]) << std::endl;
		std::cout << "Left: " << listPtrs[i]->getLeft(listPtrs[i]) << std::endl;
		std::cout << std::endl;
	}
}


