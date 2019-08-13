/*********************************************************************
** Program name: Space.cpp
** Author: Anthony Colannino
** Date: 8/13/2019
** Description: Space is an abstract class that will have multiple
** derived classes off of it to create the game map in a linked
** list.
*********************************************************************/

#include "Space.hpp"
#include <vector>
#include <iostream>

/****************************************************
*				Space::Space
* Space constructor to initialize member variables.
****************************************************/
Space::Space()
{
	up = nullptr;
	down = nullptr;
	right = nullptr;
	left = nullptr;
	roomName = "";
	hasLivingKey = false;
	hasBedroomKey = false;
	hasAtticKey = false;
	hasOfficeKey = false;
	hasPatioKey = false;
	numSteps = 0;
}

/****************************************************
*				Space::setRight
* Setter for the right space pointer.
****************************************************/
void Space::setRight(Space* obj)
{
	right = obj;
}

/****************************************************
*				Space::setLeft
* Setter for the left space pointer.
****************************************************/
void Space::setLeft(Space* obj)
{
	left = obj;
}

/****************************************************
*				Space::setUp
* Setter for the up space pointer.
****************************************************/
void Space::setUp(Space* obj)
{
	up = obj;
}

/****************************************************
*				Space::setDown
* Setter for the down space pointer.
****************************************************/
void Space::setDown(Space* obj)
{
	down = obj;
}

/****************************************************
*				Space::getDown
* Getter for the down space pointer.
****************************************************/
Space* Space::getDown(Space* obj)
{
	return obj->down;
}

/****************************************************
*				Space::getUp
* Getter for the up space pointer.
****************************************************/
Space* Space::getUp(Space* obj)
{
	return obj->up;
}

/****************************************************
*				Space::getRight
* Getter for the right space pointer.
****************************************************/
Space* Space::getRight(Space* obj)
{
	return obj->right;
}

/****************************************************
*				Space::getLeft
* Getter for the left space pointer.
****************************************************/
Space* Space::getLeft(Space* obj)
{
	return obj->left;
}

/****************************************************
*				Space::getRoom
* Getter for the room name.
****************************************************/
std::string Space::getRoom()
{
	return roomName;
}

/****************************************************
*				Space::getNumSteps
* Getter for total numsteps in the room.
****************************************************/
int Space::getNumSteps()
{
	return numSteps;
}

/****************************************************
*				Space::getLivingKey
* Getter to return bool value to check if the user
* has the key or not.
****************************************************/
bool Space::getLivingKey()
{
	return hasLivingKey;
}

/****************************************************
*				Space::getAtticKey
* Getter to return bool value to check if the user
* has the key or not.
****************************************************/
bool Space::getAtticKey()
{
	return hasAtticKey;
}

/****************************************************
*				Space::getOfficeKey
* Getter to return bool value to check if the user
* has the key or not.
****************************************************/
bool Space::getOfficeKey()
{
	return hasOfficeKey;
}

/****************************************************
*				Space::getPatioKey
* Getter to return bool value to check if the user
* has the key or not.
****************************************************/
bool Space::getPatioKey()
{
	return hasPatioKey;
}

/****************************************************
*				Space::getBedroomKey
* Getter to return bool value to check if the user
* has the key or not.
****************************************************/
bool Space::getBedroomKey()
{
	return hasBedroomKey;
}