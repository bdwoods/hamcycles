#include <iostream>
#include <string>
#include <vector>
#include "instance.h"
#include "tour_generator.h"
#include "triple_generator.h"
#include "node2edge.h"

using namespace std;

Instance read_instance(string fName);



int main (int argc, char **argv)
{
	
	string fName = "data\\example2.dat";
	
	Instance inst = read_instance(fName);
	TourList tList = Backtrack(inst);
	tourTXT(tList, fName); //output tours to file.
	
	TripleList tripList = generateList(tList);
	//cout << "generated " << tripList.tripleList.size() << endl;

	//cout << "Sending the following list to the file writer." << endl;

	//for(int i=0; i<tripList.tripleList.size(); i++)
	//{
	//	for(int j=0; j<tripList.tripleList[i].size(); j++)
	//	{
	//		cout << tripList.tripleList[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	inst.nodeTriples = &tripList.tripleList;

	tripleTXT(tripList, fName); //output triples to file.

	//tripleTXT_reader(fName);

	node2edge(inst, tList, tripList, fName);

	cin.get();

	//system("pause");
	return 0;
}  // END main