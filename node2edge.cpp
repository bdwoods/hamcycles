#include "node2edge.h"
#include "tour_generator.h"
#include "triple_generator.h"
#include "ConsoleColor.h"

#include <vector>
#include <iostream>

void node2edge(Instance& inst, TourList& tList, TripleList& tripList, string fName)
{
	ofstream fout;
	fName.resize(fName.size()-4);
	string file = fName + "_cplex.txt";
	fout.open(file);
	if (fout.fail())
	{
		cout << red << "Fail to open the file " << file << white << endl;
		exit(0);
	}
	fout << "NodeSize" << endl << inst.numNodes << endl << endl;
	fout << "EdgeSize" << endl << inst.numEdges << endl << endl;

	//cout << inst.nodeTriples->size();

	fout << "TripleSize" << endl << inst.nodeTriples->size() << endl << endl;
	
	fout << "CutConstraintSize" << endl;

	//cout << fName;

	// FOR EACH EXAMPLE, ADD CUT CONSTRAINT NUMBER
	if(fName == "data\\example2")
	{
		fout << "2" << endl;
	}
	else
	{
		fout << "0" << endl;
	}
	
	fout  << endl << "IncidentMatrix" << endl;
	for( int i = 0; i < inst.numNodes; i++)
	{
		for( int j = 0; j < inst.numEdges; j++)
		{
			if( inst.edgeList[j][0] == i || inst.edgeList[j][1] == i )
			{
				fout << j << " ";
			}
		}
		fout << endl;
	}
	fout << endl << "Triples" << endl;


	inst.n2eTriples();

	for ( int k = 0; k < inst.edgeTriples.size(); k++ )
	{
		for ( int m = 0; m < 3; m++ )
		{
			fout << inst.edgeTriples[k][m] << " ";
		}
		fout << endl;
	}

	fout << endl << "CutConstraints" << endl;

	//FOR EACH EXAMPLE ADD CUT CONSTRAINTS HERE.
	if(fName == "data\\example2")
	{
		fout << "0 10 11" << endl;
		fout << "1 12 15" << endl;
	}
	else
	{
	}
}

