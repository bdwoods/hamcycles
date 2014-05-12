#include "tour_generator.h"
#include "instance.h"
using namespace std;

vector<int> getnext(vector<int>& X, int& r, int sz, const Instance& inst);
bool Bound(const vector<int>& X, int l, int sz, const Instance& inst);
bool isEdge(int a, int b, const Instance& inst);
void tourTXT(const TourList& tList, string fName);
bool inList(const vector<int>& X, const TourList& tList);
bool Compare(const vector<int>& X, const vector<int>& Y);

//Backtracking algorithm to generate all tours.
//reference: http://www.seas.gwu.edu/~ayoussef/cs212/backtracking.html
TourList Backtrack(const Instance& inst)
{
	cout << "applying backtracking algorithm to generate tours... ";
	int sz = inst.numNodes;
	TourList tList;
	int r = 0;  //-- r is the tree level, or index of X
	vector<int> X(sz, -1);
	
	while( r > -1 )
	{
		X = getnext(X, r, sz, inst);		//-- assigns to X[r] its next 
						//-- C-compliant value, if available.
						//-- Otherwise, it re-initlizes X[r] 
						//-- to 0
		if (X[r] == -1)
		{
      		r--; //-- backtrack to the previous level
			if (r==0) //-- We have explored all tours starting with 0
				break; //-- Stop here.
		}
		else if (r==sz-1)
		{
			//if(X[1] >= sz/2) //-- We have all tours (no need to reverse directions)
			//	break;
			if(inList(X, tList) == false)
			{
				//for(int j=0; j<sz; j++)
				//{
				//	cout << X[j] << " "; //-- a new complete solution
				
				//}
				//cout << endl;
				tList.tourList.push_back(X);
			}
		}
		else
		{
			r = r+1; //-- move to the next level for X[r+1]
		}
	}
	cout << "done" << endl;
	return tList;
}

//Helper function which gets the next tour.
vector<int> getnext(vector<int>& X, int& r, int sz, const Instance& inst)
{
	X[r] = X[r] + 1;	//-- next tentative value
	while (X[r] < sz)
	{
		if (Bound(X, r, sz, inst) == true)
		{
			return X;
		}
		else
		{
			X[r]++;
		}
	}
	//-- if getnext has not returned,
	//-- that mean no C-compliant remaining
	//-- value was found. Re-initialize X[r]
	X[r] = -1;
	return X;
}

bool Bound(const vector<int>& X, int l, int sz, const Instance& inst)
{
	/* X[1:l-1] are assigned C-compliant 
	values. This function checks to 
	see if X[l] is C-compliant */
	for (int i=0; i<l-1; i++)
	{
		if(X[l] == X[i])
		{
			return false;
		}
	}

	if (l > 0 && (isEdge(X[l-1],X[l], inst) == false))
		return false;

	if (l == sz-1 && (isEdge(X[sz - 1],X[0], inst) == false))
      return false;
   
   return true;
}

//Takes a pair of nodes (a,b) and checks the instance for an edge
//in the adjacency list.  Returns true if there is an edge,
//false otherwise.
//Input: nodes a,b and the reference to the instance
bool isEdge(int a, int b, const Instance& inst)
{
	if((a >= inst.numNodes) || (a < 0) || (b >= inst.numNodes) || b < 0)
	{
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		cin.get();
		cout << "Invalid node selection. a= " << a << " b= " << b << endl;
		return false;
	}

	for(int i = 0; i < inst.adjacencyMatrix[a].size(); i++)
	{
		if( inst.adjacencyMatrix[a][i] == b )
			return true;
	}
	return false;
}

//Helper function which, given a vector address X and TourList address tList
//returns true if X is in tList.
bool inList(const vector<int>& X, const TourList& tList)
{
	vector<int> tempX = X;
	for (int i=0; i<tList.tourList.size(); i++)
	{
		if( Compare(tempX, tList.tourList[i]) )
		{
			return true;
		}
		tempX.erase(tempX.begin());
		std::reverse(tempX.begin(), tempX.end());
		tempX.insert(tempX.begin(), 0);
		if( Compare(tempX, tList.tourList[i]) )
		{
			return true;
		}
	}
	return false;
}

//Helper function which returns true if two vectors are equal
//in values.
bool Compare(const vector<int>& X, const vector<int>& Y)
{
	for (int i=0; i<X.size(); i++)
	{
		if (X[i] != Y[i])
		{
			return false;
		}
	}
	return true;
}