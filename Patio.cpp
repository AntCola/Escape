#include "Patio.hpp"

Patio::Patio()
{
	goldPieces = 150;
	roomName = "Patio";
}

int Patio::interact()
{
	std::cout << "You've made it out of the mansion! Now you have to fight Voldemort to win the game!." << std::endl;
	std::cout << "You start with 50 HP and Voldemart starts with 25! You will be able to hit between 1 and 7 damage and voldemort can hit up to 2 -- good luck!." << std::endl;
	int voldemortDamage;
	int userDamage;
	int voldemortHP = 25;
	int userHP = 50;
	bool voldemortDead = false;
	bool userDead = false;

	while (!voldemortDead && !userDead)
	{
		if (userHP > 0)
		{
			voldemortDamage = rand() % 2 + 1;
			std::cout << "Voldemort hit you for " << voldemortDamage << " damage." << std::endl;
			userHP -= voldemortDamage;
		}
		else if (userHP <= 0)
		{
			std::cout << "You have died. Better luck next time. GAME OVER." << std::endl;
			userDead = true;
			return 1;
		}
		if (voldemortHP > 0 && !userDead)
		{
			userDamage = rand() % 7 + 1;
			std::cout << "You hit voldemort for " << userDamage << " damage." << std::endl;
			voldemortHP -= userDamage;
		}
		else if (voldemortHP <= 0)
		{
			std::cout << "You killed Voldemort! You win!." << std::endl;
			voldemortDead = true;
			return 2;
		}
		 
	}
}