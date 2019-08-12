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
	int goldPieces;
	std::string roomName;
	std::vector<std::string> inventory;
	int numSteps;
	bool hasLivingKey;
	bool hasAtticKey;
	bool hasOfficeKey;
	bool hasBedroomKey;
	bool hasPatioKey;
public:
	Space();
	int getGP();
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

