#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	
	int num_pulley = 0;
	
	cout << "enter # of pulleys: ";
	cin >> num_pulley;
	const double load = 100, height = 1, pulley_eff = 1-0.11*num_pulley;
	double distance_p = height*num_pulley;
	double force = load*height/pulley_eff/distance_p ;
	
	cout << pulley_eff << endl << distance_p << endl
	<< force;
	
	
	
	
	
	return EXIT_SUCCESS;
}