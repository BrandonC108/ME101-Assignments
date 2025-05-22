/*
  Brandon Choi
  
*/

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
	double force = 0;
	double area = 0;
	// variables for entry
	
	cout << "Enter force in Newtons and area in m^2" << endl;
	// prompt
	cin >> force >> area;
	//input
	
	double stress = force/area;
	double magstress = abs(stress);
	//equation
	cout << "The stress is " << stress 
		 << " and the magnitude of the stress is " << magstress << endl;
	//output
	return EXIT_SUCCESS;
	
	
}

/*
Verified test case with Jay Sanchala

First test case: Force = 10.0 N, Area = 25.8 m^2

Enter force in Newtons and area in m^2
10
25.8
The stress is 0.387597 and the magnitude of the stress is 0.387597

--------------------------------
Process exited after 3.717 seconds with return value 0
Press any key to continue . . .

Second test case: Force = -4.5 N, Area = 12.2 m^2

Enter force in Newtons and area in m^2
-4.5
12.2
The stress is -0.368852 and the magnitude of the stress is 0.368852

--------------------------------
Process exited after 9.108 seconds with return value 0
Press any key to continue . . .

*/