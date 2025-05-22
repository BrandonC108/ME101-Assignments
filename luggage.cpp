#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	double weight_l = 0;
	string unit = "";
	cout << "Enter weight in kg or lb (Enter kg or lb): ";
	cin >> weight_l >> unit;
	
	if (unit == "kg" || unit == "Kg" || unit == "KG")
	{
		
		if (weight_l > 23){
			cout << "luggage is too heavy";
		}
		else {
			cout <<"luggage weight is acceptable";
		}
		
		
	}
	if (unit == "lb" || unit == "Lb" || unit == "LB")
	{
		weight_l = weight_l*0.453;
		if (weight_l > 23){
			cout << "luggage is too heavy";
		}
		else {
			cout <<"luggage weight is acceptable";
		}
	}
	
	return EXIT_SUCCESS;
}