#include <vector>
#include <iostream>
#include "thing.h"
#include "boat.h"
#include "riddle.h"

int main(void)
{
	Thing peasant(PEASANT_ID, 1, 0, 0);
	Thing wife(WIFE_ID, 1, 0, 0);
	Thing shepard(SHEPARD_ID, 1, 0, 0);
	Thing sheep(SHEEP_ID, 0, 0, 0);
	Thing cow(COW_ID, 0, 0, 0);
	Thing meat(MEAT_ID, 0, 0, 0);
	Thing vegetables(VEGETABLES_ID, 0, 0, 0);
	
	std::vector<Thing> leftSide;
	std::vector<Thing> rightSide;
	
	leftSide.push_back(peasant);
	leftSide.push_back(wife);
	leftSide.push_back(shepard);
	leftSide.push_back(sheep);
	leftSide.push_back(cow);
	leftSide.push_back(meat);
	leftSide.push_back(vegetables);
	
	Boat boat;
	
	move(-1, -1, boat, leftSide, rightSide);
	
	return 0;
}

void move(int captainID, int passengerID, Boat boat, std::vector<Thing> leftSide, std::vector<Thing> rightSide)
{
	int side = boat.getSide();
	
	if(captainID >= 0)
	{
		if(side)
		{
			int captainIndex = getLocationOfThingInVector(captainID, rightSide);
			rightSide[captainIndex].incrementNumTrips();
			leftSide.push_back(rightSide[captainIndex]);
			rightSide.erase(rightSide.begin() + captainIndex);
			
			if(passengerID != -1)
			{
				int passengerIndex = getLocationOfThingInVector(passengerID, rightSide);
			
				rightSide[passengerIndex].incrementNumTrips();
			
				leftSide.push_back(rightSide[passengerIndex]);
				rightSide.erase(rightSide.begin() + passengerIndex);
			}
		}
		else
		{
			int captainIndex = getLocationOfThingInVector(captainID, leftSide);
			leftSide[captainIndex].incrementNumTrips();
			rightSide.push_back(leftSide[captainIndex]);
			leftSide.erase(leftSide.begin() + captainIndex);
			
			if(passengerID != -1)
			{
				int passengerIndex = getLocationOfThingInVector(passengerID, leftSide);
			
				leftSide[passengerIndex].incrementNumTrips();
			
				rightSide.push_back(leftSide[passengerIndex]);
				leftSide.erase(leftSide.begin() + passengerIndex);
			}
		}
		
		boat.incrementNumberOfTrips();
		boat.switchSides();
		side = boat.getSide();
		
		if(boat.isOutOfHand() == 1)
		{
			return;
		}
	
		if((boat.getSide() == 1) && (rightSide.size() == 7))
		{
			if (boat.getNumberOfTrips() < 11)
			{
				std::cout<<boat.getNumberOfTrips()<<std::endl;
			}
			return;
		}
	
		if((wifeWithShepard(leftSide)) || (shepardWithMeat(leftSide)) || (sheepWithVegetables(leftSide)) || (cowWithVegetables(leftSide)))
		{
			return;
		}
	
	}
	
	int captain = -1;
	int passenger = -1;
	
	if(side)
	{
		for(int i = 0; i < rightSide.size(); i++)
		{
			passenger = -1;
			if(rightSide[i].isCaptain())
			{
				captain = rightSide[i].getID();
			}
			else
			{
				continue;
			}
		
			move(captain, passenger, boat, leftSide, rightSide); //no passenger
		
			for(int j = 0; j < rightSide.size(); j++)
			{
				if(i == j)
				{
					j++;
					continue;
				}	
			
			
				passenger = rightSide[j].getID();
			
				if((passengerID == MEAT_ID) && (passengerID != passenger))
				{
					rightSide[j].incrementUnloaded();
				}
				
				if((passenger == MEAT_ID) && (rightSide[j].getNumUnloaded() == 1))
				{
					continue;
				}
				if(passenger == VEGETABLES_ID)
				{
					continue;
				}

				move(captain, passenger, boat, leftSide, rightSide);
			}
		}
	}
	else
	{
		for(int i = 0; i < leftSide.size(); i++)
		{
			passenger = -1;
			if(leftSide[i].isCaptain())
			{
				captain = leftSide[i].getID();
			}
			else
			{
				continue;
			}
		
			move(captain, passenger, boat, leftSide, rightSide); //no passenger
		
			for(int j = 0; j < leftSide.size(); j++)
			{
				if(i == j)
				{
					continue;
				}	
			
				passenger = leftSide[j].getID();
			
				if((passengerID == MEAT_ID) && (passengerID != passenger))
				{
					continue;
				}
				
				move(captain, passenger, boat, leftSide, rightSide);
			}
		}
	}
			
	return;
}

int searchForThingByID(const int &id, const std::vector<Thing> &v)
{
	for(int i = 0; i < v.size(); i++)
	{
		if(v[i].getID() == id)
		{
			return 1;
		}
	}
	
	return 0;
	
}

int getLocationOfThingInVector(const int &id, const std::vector<Thing> &v)
{
	if(id == -1)
	{
		return -1;
	}
	for(int i = 0; i < v.size(); i++)
	{
		if(v[i].getID() == id)
		{
			return i;
		}
	}
	
	return -1;
	
}

//This returns 1 if there is a violation
int wifeWithShepard(const std::vector<Thing> &v)
{
	int wife = searchForThingByID(WIFE_ID, v);
	int shepard = searchForThingByID(SHEPARD_ID, v);
	int peasant = searchForThingByID(PEASANT_ID, v);
	
	if( (wife && shepard && (!peasant)) || ((!wife) && (!shepard) && peasant) )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//This returns 1 if there is a violation
int shepardWithMeat(const std::vector<Thing> &v)
{
	int wife = searchForThingByID(WIFE_ID, v);
	int shepard = searchForThingByID(SHEPARD_ID, v);
	int peasant = searchForThingByID(PEASANT_ID, v);
	int meat = searchForThingByID(MEAT_ID, v);
	
	if( (shepard && meat && (!wife || !peasant)) || (!shepard && !meat && (wife || shepard)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//This returns 1 if there is a violation
int sheepWithVegetables(const std::vector<Thing> &v)
{
	int shepard = searchForThingByID(SHEPARD_ID, v);
	int sheep = searchForThingByID(SHEEP_ID, v);
	int vegetables = searchForThingByID(VEGETABLES_ID, v);
	
	if( (sheep && vegetables && !shepard) || (!sheep && !vegetables && shepard))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//This returns 1 if there is a violation
int cowWithVegetables(const std::vector<Thing> &v)
{
	int shepard = searchForThingByID(SHEPARD_ID, v);
	int cow = searchForThingByID(COW_ID, v);
	int vegetables = searchForThingByID(VEGETABLES_ID, v);
	int wife = searchForThingByID(WIFE_ID, v);
	int peasant = searchForThingByID(PEASANT_ID, v);
	
	if(cow && vegetables && !wife && !shepard && !peasant)
	{
		return 1;
	}
	else if(!cow && !vegetables && wife && shepard && peasant)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
	
	
	
	
	
	
	