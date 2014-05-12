#include <sstream>
#include <vector>

#include "ConsoleColor.h"
#include "tour_generator.h"

using namespace std;

string &trim(std::string &s);
vector<int> strToVec(string str, int size);
bool isBlankLine(string s);

//Input: A TourList and a string which will be used in the 
//	filename for the data to be stored.
//Output: none.  A file is created with the tours listed by node,
//	one per line.
void tourTXT(TourList tList, string fName)
{
	ofstream fout;
	fName.resize(fName.size()-4);
	string file = fName + "_tours.txt";
	fout.open(file);
	if (fout.fail())
	{
		cout << red << "Fail to open the file " << file << white << endl;
		exit(0);
	}
	
	for(int i = 0; i < tList.tourList.size(); i++)
	{
		for(int j = 0; j < tList.tourList[i].size(); j++)
		{
			fout << tList.tourList[i][j] << " ";
		}
		fout << endl;
	}
	fout.close();
}

TourList tourTXT_reader(string fName)
{
	cout << "start reading file " << white << fName << endl;

	//open file
	ifstream fin;
	fin.open(fName);

	if (!fin.is_open())
	{
		cout << "Failed to read tourList file " << fName << endl;

		exit(0);
	}

	int nodeSize = 0;

	vector<vector<int>> tourList;
	while ( fin.good() )
	{
		string nodeListString;
		getline(fin, nodeListString);
		tourList.push_back (strToVec(nodeListString, 0));
		nodeSize++;
	}

	fin.close();

	//checking
	cout << "Tour list is " << endl;
	for (int i = 0; i < tourList.size(); i++)
	{
		for (int j = 0; j < tourList[i].size(); j++)
			cout << tourList[i][j] << " ";
	
		cout << endl;
	}
	
	
	
	cout << "done reading" << endl;


	//return instance
	TourList tList;
	tList.tourList = tourList;

	return tList;

}