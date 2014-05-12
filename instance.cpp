#include "instance.h"
#include <iostream>

using namespace std;

int Instance::revLookupTriple(int edge1, int edge2, int edge3)
{
	for (int i=0; i<nodeTriples->size(); i++)
	{
		if ((*nodeTriples)[i][0] == edge1)
		{
			if ((*nodeTriples)[i][1] == edge2)
			{
				if ((*nodeTriples)[i][2] == edge3)
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

int Instance::edgeNumLookup(int nodeA, int nodeB)
{
	for( int j = 0; j < numEdges; j++)
	{
		if(( edgeList[j][0] == nodeA && edgeList[j][1] == nodeB )
			|| ( edgeList[j][0] == nodeB && edgeList[j][1] == nodeA ))
		{
			return j;
		}
	}
}

void Instance::n2eTriples()
{
	//edgeTriples->clear();
	int edge[3];
	vector<int> tempTriple;
	for( int i = 0; i < nodeTriples->size(); i++)
	{
		edge[0] = edgeNumLookup(nodeTriples->at(i)[0], nodeTriples->at(i)[1]);
		edge[1] = edgeNumLookup(nodeTriples->at(i)[1], nodeTriples->at(i)[2]);
		edge[2] = edgeNumLookup(nodeTriples->at(i)[2], nodeTriples->at(i)[3]);
		tempTriple.push_back(edge[0]);
		tempTriple.push_back(edge[1]);
		tempTriple.push_back(edge[2]);
		edgeTriples->push_back(tempTriple);
	}
}