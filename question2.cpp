#include <iostream>
#include <cstdlib>
#include <cmath>
// cmath for math library//

using namespace std;

int main()
{
	double x1 = 0;
	cout << "enter x1" << endl;
	cin >> x1;
	double y1 = 0;
	cout << "enter y1" << endl;
	cin >> y1;
	double x2 = 0;
	cout << "enter x2" << endl;
	cin >> x2;
	double y2 = 0;
	cout << "enter y2" << endl;
	cin >> y2;
	double x3 = 0;
	cout << "enter x3" << endl;
	cin >> x3;
	double y3 = 0;
	cout << "enter y3" << endl;
	cin >> y3;
	//variables//
	
	// inputs for variable//
	//double ans = 0.5*(x1*abs(y2-y3)+x2*abs(y3-y1)+x3*abs(y1-y2));//
	double area = 0.5*abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
	//calculates area of triangle//
	
	
	cout << "The area is "<< area << endl;
	
	
	
	
	
	return EXIT_SUCCESS;
	
}