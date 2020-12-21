
#include <vector>
#include <iostream>
#include "thing.h"
#include "boat.h"

#ifndef RiddleHeaderFile
#define RiddleHeaderFile


int main(void);

void move(int c, int p, Boat boat, std::vector<Thing> leftSide, std::vector<Thing> rightSide);

int searchForThingByID(const int &id, const std::vector<Thing> &v);

int getLocationOfThingInVector(const int &id, const std::vector<Thing> &v);

int wifeWithShepard(const std::vector<Thing> &v);

int shepardWithMeat(const std::vector<Thing> &v);

int sheepWithVegetables(const std::vector<Thing> &v);

int cowWithVegetables(const std::vector<Thing> &v);

#endif