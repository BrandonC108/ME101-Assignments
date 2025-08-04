#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

double totalDist (ifstream & fin){
	double dist = 0;
	double x = 0, y = 0, last_x = 0, last_y = 0;
	while (fin >> x >> y){
		dist += sqrt(pow(last_x-x,2)+pow(last_y-y,2));
		last_x = x;
		last_y = y;
	}
	return dist;
}

int main(){
	
	ifstream fin("errands.txt");
	
	if (!fin){
		cout << "bomboclat";
		
		return EXIT_FAILURE;
		
	}	

	
	cout << totalDist(fin) << endl;

	fin.close();
	
	return EXIT_SUCCESS;
}