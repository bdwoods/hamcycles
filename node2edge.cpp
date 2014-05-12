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

	cout << inst.nodeTriples->size();

	fout << "TripleSize" << endl << inst.nodeTriples->size() << endl << endl;
	
	fout << "CutConstraintSize" << endl;

	//cout << fName;

	// FOR EACH EXAMPLE, ADD CUT CONSTRAINT NUMBER
	if(fName == "data\\example2")
	{
		fout << "2" << endl << endl;
	}
	
	fout << "IncidenceMatrix" << endl;
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
	for (int k = 0; k < inst.edgeTriples->size(); k++ )
	{
		fout << inst.edgeTriples->at(k)[0] << " " << inst.edgeTriples->at(k)[1] << " "
			<< inst.edgeTriples->at(k)[2] << endl;
	}
	//for ( int k = 0; k < inst.nodeTriples->size(); k++ )
	//{
	//	//cin.get();
	//	for ( int m = 0; m < 3; m++)
	//	{
	//		fout << inst.edgeNumLookup(inst.nodeTriples->at(k)[m], inst.nodeTriples->at(k)[m+1]) << " ";
	//		//fout << inst.triples->at(k)[m] << " ";
	//	}
	//	fout << endl;
	//}
}

