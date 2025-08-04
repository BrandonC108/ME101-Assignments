#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

double cube_weight(double a);
double potential_energy(double a, double b);

const double GRAVITY = 9.81;
const double DENSITY = 7980.0;
	
int main(){
	

	double side_length = 0, height = 0;
	do{
	
		cout << "enter side length of cube: ";
		cin >> side_length >> height;
	} while (side_length < 0 || height < 0);
	
	double weight = cube_weight(side_length);
	cout << potential_energy(weight, height);
	
	
	return EXIT_SUCCESS;
}

double cube_weight(double side_length){
	
	return DENSITY*pow(side_length,3);
}
double potential_energy(double mass, double height){
	
	return mass*GRAVITY*height;
}