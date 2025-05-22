#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main ()
{
	double m = 0;
	double c = 4.2;
	double t1 = 0;
	double t2 = 0;
	//variables and constants//
	cout << "Input mass in Kg, start and end times" << endl;
	
	cin >> m >> t1 >> t2;
	//input for mass and time//
	double deltaT = t2-t1;
	//equation for change in time//
	cout << "The change in temperature is " << deltaT << " celsius." << endl;
	//output for change in time//
	double eout = m*c*deltaT;
	//equation for energy stored//
	cout << "The energy stored is "<< eout << " Kilojoules." << endl;
	//output for energy stored//
	
	
	
	return EXIT_SUCCESS;
}