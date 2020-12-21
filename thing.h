
#ifndef ThingHeaderFile
#define ThingHeaderFile

#define PEASANT_ID 0
#define WIFE_ID 1
#define SHEPARD_ID 2
#define SHEEP_ID 3
#define COW_ID 4
#define MEAT_ID 5
#define VEGETABLES_ID 6

class Thing
{
	private:
		int passengerID;
		int captain;
		int numberOfTrips;
		int numUnloaded;
		
	public:

		Thing();
		Thing(int id, int cap, int numTrips, int unloaded);
		int getID() const;
		int isCaptain() const;
		int getNumTrips() const;
		int getNumUnloaded() const;
		void incrementNumTrips();
		void incrementUnloaded();

};

#endif