#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

bool world_cup(int year){
	
	if (year < 1930){
		
		return false;
	}
	else if (year <= 1938 && (year-1930)%4 == 0){
		return true;
	}
	else if (year >= 1950){
		if ((year-1950)%4 == 0){
			
			return true;
		}
		else{
			return false;
		}
	}
}

int main(){
	
	int year = 0;
	
	cout << "Enter year: ";
	cin >> year;
	
	if (world_cup(year) == false){
		cout << "There was no World Cup.";
	}
	else {
		if (year >= 2025){
			cout << "There will be a World Cup.";
		}
		else {
			cout << "There was a World Cup.";
		}
	}
	
	return EXIT_SUCCESS;
}