#include "Space.hpp"


Space::Space()
{
	up = nullptr;
	down = nullptr;
	right = nullptr;
	left = nullptr;
	goldPieces = 0;
}

int Space::getGP()
{
	return goldPieces;
}

void Space::setRight(Space* obj)
{
	right = obj;
}

void Space::setLeft(Space* obj)
{
	left = obj;
}

void Space::setUp(Space* obj)
{
	up = obj;
}

void Space::setDown(Space* obj)
{
	down = obj;
}

Space* Space::getDown(Space* obj)
{
	return obj->down;
}

Space* Space::getUp(Space* obj)
{
	return obj->up;
}

Space* Space::getRight(Space* obj)
{
	return obj->right;
}

Space* Space::getLeft(Space* obj)
{
	return obj->left;
}