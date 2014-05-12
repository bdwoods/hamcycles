#ifndef NODE2EDGE_H
#define NODE2EDGE_H
#include <iostream>
#include <vector>
#include "instance.h"
#include "tour_generator.h"
#include "triple_generator.h"

using namespace std;

void node2edge(Instance& inst, TourList& tList, TripleList& tripList, string fName);

#endif