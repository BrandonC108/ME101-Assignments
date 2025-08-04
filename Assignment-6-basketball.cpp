/*
	Brandon Choi
	Ivan Chen
	
	*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;


double distance(double x, double y){
	
	double distance = sqrt(pow(x,2)+pow(y,2));
	
	return distance;
	
	
}

void score(int & totalScore, double xThrow, double yThrow){
	
	if (distance(xThrow, yThrow) > 7.25){
		totalScore += 3;
	}
	else
		totalScore += 2;
	
}

int totalScore (string & name, ifstream & fin){
	
	int totalScore = 0;
	fin >> name;
	for (int i = 0; i< 10; i++)
	{
		double xThrow = 0, yThrow = 0, xLand = 0, yLand = 0;
		fin >> xThrow >> yThrow >> xLand >> yLand;
		
		if (distance(xLand, yLand) < 0.17)
		{
			score(totalScore, xThrow, yThrow);
		}
	}
	return totalScore;
}

int main(){
	
	ifstream fin("basketball.txt");
	
	if (!fin){
		
		cout << "Fail to open";
		return EXIT_FAILURE;
	}
	int lowestScore = 100;
	string lowName = "";
	
	for (int i = 0; i < 6; i++)	{
		string name = "";
		int Score = 0;
		Score = totalScore(name, fin);
		cout << name << ": " << Score << " points" << endl;
		if (Score < lowestScore){
			lowestScore = Score;
			lowName = name;
		}
	}
	cout << lowName << " has lowest score with "  
		<< lowestScore << " points";
	
	fin.close();

	return EXIT_SUCCESS;
}

/*

Kat: 15 points
Carol: 5 points
Ryan: 16 points
Pete: 9 points
Pervin: 14 points
Forrest: 14 points
Carol has lowest score with 5 points
--------------------------------
Process exited after 0.5633 seconds with return value 0
Press any key to continue . . .

*/