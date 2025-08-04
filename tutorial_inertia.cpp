#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
	double r_1 = 0, r_2 = 0, m = 0;
	cout << "Enter r_1, r_2, and m: ";
	cin >> r_1 >> r_2 >> m;
	
	while(r_2 <= r_1 || r_1 <= 0 || m <=0)
	{
		cout << "invalid input" << endl;
		if(r_1 < 0)
			cout << "r_1 must be greater than 0";
			cin >> r_1;
			continue;
		else if(m < 0)
			cout << "m must be greater than 0";
			cin >> m;
			continue;
		else if(r_2 < r_1)
			cout << "r_2 must be greater than " << r_1;
			cin >> r_2;
			continue;
	}
	
	double inertia = 2.0/5*m*((pow(r_2,5)-pow(r_1,5))/(pow(r_2,3)-pow(r_1,3)));
	cout << "Inertia is " << inertia;	
	
	return EXIT_SUCCESS;
	
}