/*********************************************************************
** Program name: getNum.cpp
** Author: Anthony Colannino
** Date: 8/13/2019
** Description: Input validation function that takes in three
** parameters to allow for reusability. The first is a string that
** will allow for a user chosen prompt message, the next two
** parameters are both ints so a range of allowed values can be
** implemented.
*********************************************************************/
#include <iostream>
#include <sstream>
#include <string>
#include "getNum.hpp"

/****************************************************
*				getNum								*
* Input validation function that will take in		*
* three parameters.  The first is a string of what	*
* the prompt should be displayed to the user for	*
* input, the second parameter is the minimum value	*
* we are allowing after, and the third is the max	*
* value we are allowing afte validation.			*
****************************************************/
int getNum(std::string prompt, int min, int max)
{
	std::string input;
	int choice;
	bool myBool = true;

	std::cout << prompt << std::endl;

	while (myBool) //Loop quits on myBool = false
	{
		std::getline(std::cin, input);
		if (!input.empty()) //Empty string?
		{
			std::stringstream ss(input);
			if (ss >> choice) //Can stringstream object be passed into int?
			{
				if (choice >= min && choice <= max) //In range of allowed values?
				{
					if (ss.eof()) //Is there anything left in the input file stream?
					{
						myBool = false;
					}
				}
			}

		}
		if (myBool == true) //If wrong input - reprompt and restart validation
		{
			std::cout << "Invalid input. Please try again." << std::endl;
			std::cout << prompt << std::endl;
		}
	}
	return choice;
}