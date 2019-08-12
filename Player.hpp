#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Space.hpp"
#include "Attic.hpp"
#include "Bedroom.hpp"
#include "Game.hpp"
#include "Kitchen.hpp"
#include "LivingRoom.hpp"
#include "Office.hpp"
#include "Patio.hpp"

class Player
{
private:
	Space* userLocation;
public:
	void setUserLocation(Space*);
	Space* getUserLocation();
};

#endif
