
#include "thing.h"

Thing::Thing()
{
	passengerID = -1;
	captain = 0;
	numberOfTrips = 0;
	numUnloaded = 0;
}

Thing::Thing(int id, int cap, int numTrips, int unloaded)
{
	passengerID = id;
	captain = cap;
	numberOfTrips = numTrips;
	numUnloaded = unloaded;
}

int Thing::getID() const
{
	return passengerID;
}

int Thing::isCaptain() const
{
	return captain;
}

int Thing::getNumTrips() const
{
	return numberOfTrips;
}

int Thing::getNumUnloaded() const
{
	return numUnloaded;
}

void Thing::incrementNumTrips()
{
	numberOfTrips++;
	return;
}

void Thing::incrementUnloaded()
{
	numUnloaded++;
	return;
}