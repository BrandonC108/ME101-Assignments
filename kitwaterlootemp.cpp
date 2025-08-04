#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;
 
void readData (ifstream & fin, double & maxTemp, double & minTemp, double &maxPrecip){
	double temphigh = 0, templow = 0, precip = 0;
	while (fin >> temphigh >> templow >> precip){
		
		if (temphigh > maxTemp){
			maxTemp = temphigh;
		}
		
		if (templow < minTemp){
			minTemp = templow;
		}
		
		if (precip > maxPrecip){
			maxPrecip = precip;
		}
		
	}
	
}
	
	


int main(){
	
	ifstream fin1("Jan_Jun2024.txt");
	
	if (!fin1){
		cout << "bomboclat1";
		
		return EXIT_FAILURE;
		
	}	
	ifstream fin2("Jan_Jun2025.txt");
	
	if (!fin2){
		cout << "bomboclat2";
		
		return EXIT_FAILURE;
		
	}	
	
	double maxT25 = -1000, minT25 = 1000, maxP25 = -1000;
	double maxT24 = -1000, minT24 = 1000, maxP24 = -1000;
	
	
	readData(fin1, maxT24, minT24, maxP24);
	readData(fin2, maxT25, minT25, maxP25);
	
	cout << "2024: " << maxT24 << " "<< minT24 << " "<< maxP24 << endl;
	cout << "2025: " << maxT25 << " "<< minT25 << " "<< maxP25 << endl;
	
	fin1.close();
	fin2.close();
	return EXIT_SUCCESS;
}