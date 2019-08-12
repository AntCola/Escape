#include "Menu.hpp"
#include "Game.hpp"
#include "getNum.hpp"

void menu()
{
	int userChoice = getNum("Enter '1' to start Escape from Voldemort's Manor game or '2' to exit.", 1, 2);

	while (userChoice == 1)
	{
		Game game1;
		game1.gameFlow();
		userChoice = getNum("Etner '1' to play again or '2' to quit.", 1, 2);
	}
}