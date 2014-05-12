#ifndef TOUR_GENERATOR_H
#define TOUR_GENERATOR_H
#include <iostream>
#include <vector>
#include "instance.h"

using namespace std;

struct TourList
{
	vector<vector<int>> tourList;
};

//TourList generateTours(Instance inst);
TourList Backtrack(const Instance& inst);
void tourTXT(TourList tList, string fName);
bool isEdge(int a, int b, const Instance& inst);
//PartialTour augment(PartialTour part);

#endif