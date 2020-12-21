
#include "Boat.h"

Boat::Boat()
{
	side = 0;
	numberOfTrips = 0;
}

Boat::Boat(int s, int numTrips)
{
	side = s;
	numberOfTrips = numTrips;
}

void Boat::incrementNumberOfTrips()
{
	numberOfTrips++;
	return;
}

void Boat::switchSides()
{
	if (!side)
	{
		side = 1;
	}
	else
	{
		side = 0;
	}
	return;
}

int Boat::getSide() const
{
	return side;
}

int Boat::getNumberOfTrips() const
{
	return numberOfTrips;
}

int Boat::isOutOfHand() const
{
	if(numberOfTrips > 11)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}