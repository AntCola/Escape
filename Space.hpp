/*********************************************************************
** Program name: Space.hpp
** Author: Anthony Colannino
** Date: 8/13/2019
** Description: Header file for Space.hpp.
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
#include <vector>
#include "getNum.hpp"

class Space
{
protected:
	Space* up;
	Space* down;
	Space* right;
	Space* left;
	std::string roomName;
	int numSteps;
	bool hasLivingKey;
	bool hasAtticKey;
	bool hasOfficeKey;
	bool hasBedroomKey;
	bool hasPatioKey;
public:
	Space();
	void setRight(Space*);
	void setLeft(Space*);
	void setUp(Space*);
	void setDown(Space*);
	Space* getUp(Space*);
	Space* getDown(Space*);
	Space* getLeft(Space*);
	Space* getRight(Space*);
	virtual std::string getRoom();
	virtual int interact() = 0;
	int getNumSteps();
	bool getLivingKey();
	bool getAtticKey();
	bool getOfficeKey();
	bool getBedroomKey();
	bool getPatioKey();

};

#endif

