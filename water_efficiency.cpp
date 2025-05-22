/*
  Brandon Choi
  
*/

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
	const double Cp = 4.2;
	// unit in kJ/(kg*celsius)
	const double HV = 45;
	// unit in Mj/kg
	
	double massW = 0;
	double massG = 0;
	double deltaT = 0;
	//variables for entry
	
	cout << "Enter mass of water in kg, change in temperature in celsius, " 
		 << "and mass of gas in kg." << endl;
	//prompt
	cin >> massW >> deltaT >> massG;
	//inputs
	
	double efficiency =  (massW*Cp*deltaT)/(massG*(1000*HV));
	//equation for efficiency
	
	cout << "The efficiency of the heater is " << efficiency << endl;
	//output
	
	return EXIT_SUCCESS;
	
}

/*
compared outputs with Jay Sanchala
First test case:

Enter mass of water in kg, change in temperature in celsius, and mass of gas in kg.
100
60
0.8
The efficiency of the heater is 0.7

--------------------------------
Process exited after 8.869 seconds with return value 0
Press any key to continue . . .

Second test case:

Enter mass of water in kg, change in temperature in celsius, and mass of gas in kg.
10.5
21.5
0.05
The efficiency of the heater is 0.4214

--------------------------------
Process exited after 9.333 seconds with return value 0
Press any key to continue . . .

*/
