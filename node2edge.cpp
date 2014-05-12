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

	cout << inst.triples->size();

	fout << "TripleSize" << endl << inst.triples->size() << endl << endl;
	
	fout << "CutConstraintSize" << endl;

	cout << fName;

	if(fName == "data\example2")
	{
		fout << "2" << endl << endl;
	}
	
	
}