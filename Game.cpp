#include "Game.hpp"
#include "Player.hpp"
#include "Space.hpp"
#include <vector>
#include <iostream>
#include "getNum.hpp"

Game::Game()
{
	kitchenPtr = new Kitchen();
	livingRoomPtr = new LivingRoom();
	atticPtr = new Attic();
	officePtr = new Office();
	bedroomPtr = new Bedroom();
	patioPtr = new Patio();

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

	totalSteps = 0;
	gameLost = false;
	gameWon = false;
	

}

Game::~Game()
{
	for (int i = 0; i < listPtrs.size(); i++)
	{
		delete listPtrs[i];
	}
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

void Game::setGameLost(bool status)
{
	gameLost = status;
}

void Game::setGameWon(bool status)
{
	gameWon = status;
}

void Game::gameFlow()
{
	std::cout << "Welcome to Escape from Voldemort's Manor!! Here are the directions." << std::endl;
	std::cout << "You will start in the kitchen of Voldemort's manor. In each room of the manor you are searching for a key."<< std::endl;
	std::cout << "You will use these keys to unlock any available rooms to you from your current location." << std::endl;
	std::cout << "Your goal is to make your way through the manor until your able to make it outside in under 50 steps." << std::endl;
	std::cout << "Once you are able to make it outside you will have to fight Voldemort himself to win the game!." << std::endl;
	//Add all necessary information for the user at the start of the function, I am going to write all of the conditionals first and then worry about that later*************]
	Player player1;
	player1.setUserLocation(kitchenPtr);
	std::cout << "You have just started the game. You start in the kitchen." << std::endl;
	totalSteps = kitchenPtr->interact();
	player1.addInventory("Living Room Key");
	std::cout << "You have found the only key in this room, you will move to the living room now." << std::endl;
	player1.setUserLocation(livingRoomPtr);
	gameLost = false;
	gameWon = false;
	while (totalSteps < 50 && player1.getUserLocation() != patioPtr)
	{
		if (player1.getUserLocation() == kitchenPtr) //Player is in kitchen
		{
			std::cout << "You have already receieved the only item in this room. You use your living room key on the door and arrive in the living room." << std::endl;
			player1.setUserLocation(livingRoomPtr);
		}
		else if (player1.getUserLocation() == livingRoomPtr) //Player is in living room
		{
			std::cout << "You are currently in the living room." << std::endl;
			if (!livingRoomPtr->getAtticKey() && !livingRoomPtr->getOfficeKey()) //If player has neither key
			{
				totalSteps = livingRoomPtr->interact();

				if (livingRoomPtr->getAtticKey()) //Add key to inventory if player obtained
				{
					player1.addInventory("Attic Key");
				}
				if (livingRoomPtr->getOfficeKey()) //Add key to inventory if player obtained
				{
					player1.addInventory("Office Key");
				}
				if (livingRoomPtr->getAtticKey() && livingRoomPtr->getOfficeKey()) //If user has both keys
				{
					std::cout << "You have both the attic and the office key. You have the option to move to either room." << std::endl;
					int userChoice = getNum("Enter '1' to enter the attic or '2' to enter the office.", 1, 2);
					if (userChoice == 1) //User chose to move to attic
					{
						player1.setUserLocation(atticPtr);
					}
					else if (userChoice == 2) //User chose to move to office
					{
						player1.setUserLocation(officePtr);
					}
				}
				else if (!livingRoomPtr->getAtticKey() && livingRoomPtr->getOfficeKey()) //User got the office key and not the attic
				{
					std::cout << "You have chosen to move with just an office key.  You unlock the office and move into the office." << std::endl;
					player1.setUserLocation(officePtr);
				}
				else if (livingRoomPtr->getAtticKey() && !livingRoomPtr->getOfficeKey()) //User got the attic key and not the office
				{
					std::cout << "You have chosen to move with just an attic key.  You unlock the attic and move into the attic." << std::endl;
					player1.setUserLocation(atticPtr);
				}
			}
			else if (livingRoomPtr->getAtticKey() && !livingRoomPtr->getOfficeKey()) //If player has an attic key but not office key
			{
				std::cout << "You are in the living room." << std::endl;
				std::cout << "You currently have a key to the attic." << std::endl;
				int userChoice = getNum("Enter '1' to proceed to the attic or '2' to stay in the living room to search more.",1, 2);
				if (userChoice == 1) //User moves to attic
				{
					player1.setUserLocation(atticPtr);
				}
				else if (userChoice == 2) //User searches for another key
				{
					totalSteps = livingRoomPtr->interact();

					if (livingRoomPtr->getOfficeKey()) //User found office key
					{
						player1.addInventory("Office Key");
						std::cout << "You now have the office key and the attic key. This is all the living room has to offer." << std::endl;
						int userChoice2 = getNum("Enter '1' to move to the attic or '2' to move to the office.", 1, 2);
						if (userChoice2 == 1) //User move to attic
						{
							player1.setUserLocation(atticPtr);
						}
						else if (userChoice2 == 2) //User move to office
						{
							player1.setUserLocation(officePtr);
						}
					}
				}
			}
			else if (!livingRoomPtr->getAtticKey() && livingRoomPtr->getOfficeKey()) //If player has an office key but not an attic key
			{
				std::cout << "You are in the living room." << std::endl;
				std::cout << "You currently have a key to the office." << std::endl;
				int userChoice = getNum("Enter '1' to proceed to the office or '2' to stay in the living room to search more.", 1, 2);
				if (userChoice == 1) //User moves to office
				{
					player1.setUserLocation(officePtr);
				}
				else if (userChoice == 2) //User searches for another key
				{
					totalSteps = livingRoomPtr->interact();

					if (livingRoomPtr->getAtticKey()) //User found attic key
					{
						player1.addInventory("Attic Key");
						std::cout << "You now have the office key and the attic key. This is all the living room has to offer." << std::endl;
						int userChoice2 = getNum("Enter '1' to move to the attic or '2' to move to the office.", 1, 2);
						if (userChoice2 == 1) //User move to attic
						{
							player1.setUserLocation(atticPtr);
						}
						else if (userChoice2 == 2) //User move to office
						{
							player1.setUserLocation(officePtr);
						}
					}
				}
			}
			else if (livingRoomPtr->getAtticKey() && livingRoomPtr->getOfficeKey()) //If player has both keys
			{
				std::cout << "You currently have both the office key and the attic key. This is all the living room has to offer." << std::endl;
				int userChoice = getNum("Enter '1' to enter the attic or '2' to enter the office.", 1, 2);
				if (userChoice == 1)
				{
					player1.setUserLocation(atticPtr);
				}
				else if (userChoice == 2)
				{
					player1.setUserLocation(officePtr);
				}
			}

		}
		
		else if (player1.getUserLocation() == atticPtr)
		{
			std::cout << "You are currently in the attic." << std::endl;
			totalSteps = atticPtr->interact();
			player1.setUserLocation(livingRoomPtr);
		}
		
		else if (player1.getUserLocation() == officePtr)
		{
			std::cout << "You are currently in the office." << std::endl;
			if (!officePtr->getBedroomKey() && !officePtr->getPatioKey()) //User has neither key
			{
				totalSteps = officePtr->interact();

				if (officePtr->getBedroomKey()) //If user got bedroom key
				{
					player1.addInventory("Bedroom Key");
				}
				if (officePtr->getPatioKey()) //If user got patio key
				{
					player1.addInventory("Patio Key");
				}
				if (officePtr->getBedroomKey() && officePtr->getPatioKey()) //User gets both keys
				{
					std::cout << "You have both the bedroom and patio key. You have the option to move to either room." << std::endl;
					int userChoice = getNum("Enter '1' to enter the bedroom or '2' to enter the patio.", 1, 2);
					if (userChoice == 1) //Move to bedroom
					{
						player1.setUserLocation(bedroomPtr);
					}
					else if (userChoice == 2) //Move to patio
					{
						player1.setUserLocation(patioPtr);
					}
				}
				else if (!officePtr->getBedroomKey() && officePtr->getPatioKey()) //User got patio key and not the bedroom key
				{
					std::cout << "You have chosen to move with just a patio key. You unlock the patio and move outside to face Voldemort." << std::endl;
					player1.setUserLocation(patioPtr);
				}
				else if (officePtr->getBedroomKey() && !officePtr->getPatioKey()) //User gets bedroom key and not patio key
				{
					std::cout << "You have chosen to move with just a bedroom key. You unlock the bedroom and enter." << std::endl;
					player1.setUserLocation(bedroomPtr);
				}

			}
			else if (!officePtr->getBedroomKey() && officePtr->getPatioKey()) //If player has patio key but not bedroom key
			{
				std::cout << "You are in the office." << std::endl;
				std::cout << "You currently have a key to the patio." << std::endl;
				int userChoice = getNum("Enter '1' to enter the patio or '2' to search the office more.", 1, 2);
				if (userChoice == 1)
				{
					player1.setUserLocation(patioPtr);
				}
				else if (userChoice == 2)
				{
					totalSteps = officePtr->interact();

					if (officePtr->getBedroomKey())
					{
						player1.addInventory("Bedroom Key");
						std::cout << "You have both the bedroom key and the patio key now." << std::endl;
						int userChoice2 = getNum("Enter '1' to enter the bedroom or '2' to enter the patio.", 1, 2);
						if (userChoice2 == 1)
						{
							player1.setUserLocation(bedroomPtr);
						}
						else if (userChoice2 == 2)
						{
							player1.setUserLocation(patioPtr);
						}
					}
				}
			}
			else if (officePtr->getBedroomKey() && !officePtr->getPatioKey()) //If player has a bedroom key but not a patio key
			{
				std::cout << "You are in the office" << std::endl;
				std::cout << "You currently have a key to the bedroom." << std::endl;
				int userChoice = getNum("Enter '1' to enter the bedroom or '2' to search the office more.", 1, 2);
				if (userChoice == 1)
				{
					player1.setUserLocation(bedroomPtr);
				}
				else if (userChoice == 2)
				{
					totalSteps = officePtr->interact();

					if (officePtr->getPatioKey())
					{
						player1.addInventory("Patio Key");
						std::cout << "You have both the bedroom key and the patio key now." << std::endl;
						int userChoice2 = getNum("Enter '1' to enter the bedroom or '2' to enter the patio", 1, 2);
						if (userChoice2 == 1)
						{
							player1.setUserLocation(bedroomPtr);
						}
						else if (userChoice2 == 2)
						{
							player1.setUserLocation(patioPtr);
						}
					}
				}
			}
			else if (officePtr->getBedroomKey() && officePtr->getPatioKey())
			{
				std::cout << "You are in the office" << std::endl;
				std::cout << "You have both the patio key and the bedroom key. This is all the office has to offer." << std::endl;
				int userChoice = getNum("Enter '1' to enter the patio or '2' to enter the bedroom.", 1, 2);
				if (userChoice == 1)
				{
					player1.setUserLocation(patioPtr);
				}
				else if (userChoice == 2)
				{
					player1.setUserLocation(bedroomPtr);
				}
			}

		}
		
		else if (player1.getUserLocation() == bedroomPtr)
		{
			std::cout << "You are in the bedroom. There is nothing to be found in this room, you have wasted 3 steps entering this room." << std::endl;
			std::cout << "You leave the bedroom and head back into the office." << std::endl;
			player1.setUserLocation(officePtr);
		}

		std::cout << "Your inventory currently contains:" << std::endl;

		player1.printInventory();
	}
	
	int winner = patioPtr->interact();

	if (totalSteps >= 50)
	{
		std::cout << "You have taken too many steps and lost the game.";
	}
	else if (winner == 1)
	{
		std::cout << "Thank you for playing, better luck next time." << std::endl;
	}
	else if (winner == 2)
	{
		std::cout << "CONGRATS YOU WIN!!!" << std::endl;
	}

}


