
#ifndef BoatHeaderFile
#define BoatHeaderFile

class Boat
{
	private:
	
		int side;
		int numberOfTrips;
		
	public:
	
		Boat();
		Boat(int s, int numTrips);
		void incrementNumberOfTrips();
		void switchSides();
		int getSide() const;
		int getNumberOfTrips() const;
		int isOutOfHand() const;
};

#endif