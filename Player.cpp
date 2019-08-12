#include "Player.hpp"
#include <iostream>


void Player::setUserLocation(Space* obj)
{
	userLocation = obj;
}

Space* Player::getUserLocation()
{
	return userLocation;
}