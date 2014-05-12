#include "triple_generator.h"
#include "triple_generator.h"
#include "tour_generator.h"
#include <vector>

using namespace std;

vector<vector<int>> extractTriples(vector<int> tour);
void addTriples(vector<vector<int>> triples, TripleList& tripList);

//Input: tours, which contains a list of all the tours.
//Output: tripleList, a list of all triples in the given tours,
//		sorted lexicographically.
TripleList generateList(TourList tours)
{
	cout << "generating list of triples... ";
	TripleList tpList;
	vector<vector<int>> tempTriples;

	for (int i=0; i<tours.tourList.size(); i++)
	{
		//cout << endl << "start tour " << i << endl;
		tempTriples = extractTriples(tours.tourList[i]);
		addTriples(tempTriples, tpList);
		
	}
	sort(tpList.tripleList.begin(), tpList.tripleList.end());
	cout << "done" << endl;
	return tpList;
}




//---------------- HELPER FUNCTIONS --------------------------


//Input: vector containing a tour
//Output: vector of triples contained in the tour, where triples
//		are each written in their lexicographic direction.
vector<vector<int>> extractTriples(vector<int> tour)
{
	vector<vector<int>> trips(tour.size(), vector<int>(4));
	vector<int> tempTour = tour;

	tempTour.push_back(tour[0]);
	tempTour.push_back(tour[1]);
	tempTour.push_back(tour[2]);

	for(int i=0; i<tour.size(); i++)
	{
		for(int j=0; j<4; j++)
		{
			trips[i][j] = tempTour[i + j];
			//cout << trips[i][j] << " ";
		}
		//cout << endl;
	}
	// to keep lexicographic order
	for(int i=0; i<trips.size(); i++)
	{
		int tempNum1, tempNum2;
		if(trips[i][0] > trips[i][3])
		{
			tempNum1 = trips[i][0];
			tempNum2 = trips[i][1];
			trips[i][0] = trips[i][3];
			trips[i][3] = tempNum1;
			trips[i][1] = trips[i][2];
			trips[i][2] = tempNum2;
		}
	}
	return trips;
}

//Input: a reference to the list of triples and the triples to be added.
//Output: none.
// This function adds the given triples to the list, ignoring duplicates.
void addTriples(vector<vector<int>> triples, TripleList& tripList)
{	
	bool inList = false;
	for(int i=0; i<triples.size(); i++)
	{
		inList = false;
		for(int j=0; j<tripList.tripleList.size(); j++)
		{
			if(triples[i][0] == tripList.tripleList[j][0])
			{
				if(triples[i][1] == tripList.tripleList[j][1])
				{
					if(triples[i][2] == tripList.tripleList[j][2])
					{
						if(triples[i][3] == tripList.tripleList[j][3])
						{
							//cout << " " << triples[i][0] << " " << triples[i][1] << " " << triples[i][2] << " " <<triples[i][3]
							//	<< " is the same as " << tripList.tripleList[j][0] << " " << tripList.tripleList[j][1] << " "
							//	<< tripList.tripleList[j][2] << " " << tripList.tripleList[j][3] << endl;
							inList = true;
							break;
						}
					}
				}
			}
		}
		if(inList == false)
		{
			//cout << "adding ";
			//cout << triples[i][0] << " " << triples[i][1] << " " << triples[i][2] << " " << triples[i][3] << " " << endl;
			tripList.tripleList.push_back(triples[i]);
		}

	}
}