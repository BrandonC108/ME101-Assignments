#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	const double Pi = M_PI;
	double x = 0, y = 0;
	cout << "input coordinates in (x, y)";
	cin >> x >> y;
	
	double r = sqrt(pow(x,2) + pow(y,2));
	double theta = atan(y/x);
	double deg_theta = theta*(180/Pi);
	
	if (x < 0 && y < 0){
		theta = (Pi - theta)*(-1);
		deg_theta = (180 - deg_theta)*(-1);
	}
	if (x < 0 && y > 0){
		theta = (-Pi - theta)*(-1);
		deg_theta = (-180 - deg_theta)*(-1);
	}
	
	cout << r << " Radius "<< theta << " Radians" << endl
		 << deg_theta << " Degrees";
	
	return EXIT_SUCCESS;
}