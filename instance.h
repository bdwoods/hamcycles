#ifndef INSTANCE_H
#define INSTANCE_H

#include <fstream>
#include <string>
#include <cmath>
#include <ctime>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>


struct Instance
{
	int numNodes;
	int numEdges;

	std::vector<std::vector<int>> adjacencyMatrix;
	std::vector<std::vector<int>> edgeList;
	std::vector<std::vector<int>>* triples;
	int revLookupTriple(int edge1, int edge2, int edge3);
	void fillEdgeList();
	bool isEdge(int a, int b);
};


#endif

