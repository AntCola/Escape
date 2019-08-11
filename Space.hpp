#ifndef SPACE_HPP
#define SPACE_HPP

class Space
{
protected:
	Space* up;
	Space* down;
	Space* right;
	Space* left;
	int goldPieces;
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
};

#endif

