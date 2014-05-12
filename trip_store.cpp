#include <sstream>
#include <vector>

#include "ConsoleColor.h"
#include "triple_generator.h"

using namespace std;

string &trim(std::string &s);
vector<int> strToVec(string str, int size);
bool isBlankLine(string s);

//Input: A TourList and a string which will be used in the 
//	filename for the data to be stored.
//Output: none.  A file is created with the tours listed by node,
//	one per line.
void tripleTXT(TripleList tpList, string fName)
{
	ofstream fout;
	fName.resize(fName.size()-4);
	string file = fName + "_triples.txt";
	fout.open(file);
	if (fout.fail())
	{
		cout << red << "Fail to open the file " << file << white << endl;
		exit(0);
	}
	
	for(int i = 0; i < tpList.tripleList.size(); i++)
	{
		for(int j = 0; j < tpList.tripleList[i].size(); j++)
		{
			fout << tpList.tripleList[i][j] << " ";
		}
		fout << endl;
	}
	fout.close();
}

//******** Not working.
TripleList tripleTXT_reader(string fName)
{
	fName.resize(fName.size()-4);
	string file = fName + "_triples.txt";
	cout << "start reading file " << white << file << endl;

	//open file
	ifstream fin;
	fin.open(file);

	if (!fin.is_open())
	{
		cout << "Failed to read tourList file " << file << endl;
		//cin.get();
		exit(0);
	}


	vector<vector<int>> tpList;
	while ( fin.good() )
	{
		string nodeListString;
		getline(fin, nodeListString);
		tpList.push_back (strToVec(nodeListString, 0));
		cout << "Read " << nodeListString << endl;
	}
	cin.get();
	fin.close();

	//checking
	cout << "Triple list is " << endl;
	for (int i = 0; i < tpList.size(); i++)
	{
		for (int j = 0; j < tpList[i].size(); j++)
			cout << tpList[i][j] << " ";
	
		cout << endl;
	}
	
	
	
	cout << "done reading" << endl;


	//return instance
	TripleList tripList;
	tripList.tripleList = tpList;

	return tripList;

}