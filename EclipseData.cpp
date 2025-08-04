#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

const int maxpeople = 10;
const int maxlocation = 60;

void readLocation (ifstream & fin, string Location[maxlocation])
{
	for (int i = 0; i < maxlocation; i++){
		fin >> Location[i];
	}
}

void eclipse (ifstream & fin, float rating[maxlocation][2]){
	int location;
	
	while (fin >> location){
	
		
		int people;
		
		fin >> people;
		
		rating[location][0] += people;
		
		for (int i = 0; i < people ; i++){
			int rate;
			fin >> rate;
			rating[location][1] += rate;
		}
	}
}

string mostPeople (string Location[maxlocation], float rating[maxlocation][2]){
	string MLocation = "";
	int mostpeople = 0;
	for (int i = 0; i < maxlocation; i++){
		
		if (rating[i][0] > mostpeople){
			mostpeople = rating[i][0];
			MLocation = Location[i];
		}
	}
	return MLocation;
}

