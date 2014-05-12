#ifndef TRIPLE_GENERATOR_H
#define TRIPLE_GENERATOR_H
#include "tour_generator.h"
#include <vector>

using namespace std;

struct TripleList
{
	vector<vector<int>> tripleList;
};

TripleList generateList(TourList tourList);


void tripleTXT(TripleList tpList, string fName);
TripleList tripleTXT_reader(string fName);
#endif