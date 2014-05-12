#include "instance.h"
#include <iostream>

using namespace std;

int Instance::revLookupTriple(int edge1, int edge2, int edge3)
{
	for (int i=0; i<triples->size(); i++)
	{
		if ((*triples)[i][0] == edge1)
		{
			if ((*triples)[i][1] == edge2)
			{
				if ((*triples)[i][2] == edge3)
				{
					return i;
				}
			}
		}
	}
	cout << "No such triple is used in this problem." << endl;
	return 0;
}

void Instance::fillEdgeList()	{
	for (int i=0; i<numNodes; i++)	{
		for (int j = i + 1; j < numNodes; j++)	{
			if (isEdge(i, j))
			{
				vector<int> edge;
				edge.push_back(i);
				edge.push_back(j);
				edgeList.push_back(edge);
			}
		}
	}
	numEdges = edgeList.size();
	//cout << "There are " << numEdges << " Edges!" << endl;
}

bool Instance::isEdge(int a, int b)
{
	if((a >= numNodes) || (a < 0) || (b >= numNodes) || b < 0)
	{
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		cin.get();
		cout << "Invalid node selection. a= " << a << " b= " << b << endl;
		return false;
	}

	for(int i = 0; i < adjacencyMatrix[a].size(); i++)
	{
		if( adjacencyMatrix[a][i] == b )
			return true;
	}
	return false;
}