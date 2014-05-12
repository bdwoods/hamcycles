#include <sstream>
#include <functional> 
#include <cctype>
#include <locale>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include "instance.h"

using namespace std;


void ReadHeader(ifstream& reader, string text);
string &trim(std::string &s);
vector<int> strToVec(string str, int size);
bool isBlankLine(string s);

//READ THE INCIDENCE
Instance read_instance(string fName)
{
	cout << "reading file " << fName << "... ";

	//open file
	ifstream fin;
	fin.open(fName);

	if (!fin.is_open())
	{
		cout << "Failed to read instance file " << fName << endl;

		exit(0);
	}

	int nodeSize = 0;

	vector<vector<int>> adjacencyMatrix;
	while ( fin.good() )
	{
		string nodeListString;
		getline(fin, nodeListString);
		adjacencyMatrix.push_back (strToVec(nodeListString, 0));
		nodeSize++;
	}

	fin.close();

	//checking
	//cout << "adjacencyMatrix is " << endl;
	//for (int i = 0; i < adjacencyMatrix.size(); i++)
	//{
	//	for (int j = 0; j < adjacencyMatrix[i].size(); j++)
	//		cout << adjacencyMatrix[i][j] << " ";
	//
	//	cout << endl;
	//}
	//
	//
	//
	//cout << "done reading" << endl;


	//return instance
	Instance inst ={0, 0};
	//cout << "numNodes= " << inst.numNodes << endl;
	inst.numNodes = nodeSize;
	//cout << "numNodes= " << inst.numNodes << endl;

	inst.adjacencyMatrix = adjacencyMatrix;
	inst.fillEdgeList();

	cout << "done" << endl;
	return inst;

}

////////////////////////////////////HELPER FUNCTIONS//////////////////////////////////////////
void ReadHeader(ifstream& reader, string text)
{
	string line;

	while (1)
	{
		getline(reader, line);
		line = trim(line);
		if (!isBlankLine(line))
			break;
	}

	if (text.compare(line) != 0)
	{
		cout << "Failed to read " << text << endl;
		cout << "get " << line << endl;
		exit(0);
	}
	
}

 vector<int> strToVec(string str, int size)
 {
	 if (isBlankLine(str))
	 {
		 cout << "Empty string." << endl;
		 exit(0);
	 }

	 str = trim(str);
	 str += " ";
	 vector<int> vec;

	 int count = 0;
	 string split = "";
	 for (int k = 0; k < str.size(); k++)
	 {
		 if (str[k] != ' ' && str[k] != '\t' && str[k] != '\n')
			 split += str[k];
		 else
		 {
			 vec.push_back(atoi(split.c_str()));
			 split.clear();
		 }
	 }
	 
	 //if (size > 0 && vec.size() != size)
	 //{
	//	 cout << "Error dimension when transform string to vector." << endl;
	//	 exit(0);
	 //}
	 return vec;
 }

 bool isBlankLine(string s)
 {
	 if (s.size() == 0)
		 return true;

	 for (int k = 0; k < s.size(); k++)
	 {
		 if (s[k] != ' ' && s[k] != '\t' && s[k] != '\n')
			 return false;
	 }

	 return false;
 }

 // trim from start
string &ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}

// trim from end
string &rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
}

// trim from both ends
string &trim(std::string &s) {
        return ltrim(rtrim(s));
}