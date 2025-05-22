/*
	Brandon Choi, Adamo Vannicola
*/

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	double angle = 0;
	double side_1 = 0;
	double side_2 = 0;
	
	cout <<"Enter two adjacent sides and a contained angle: ";
	cin >> side_1 >> side_2 >> angle;
	
	angle = abs(angle);
	side_1 = abs(side_1);
	side_2 = abs(side_2);
	
	if(angle > 0 && angle < 180)
	{
		if(angle <= 90.500 && angle >= 89.500)
		{
			if(abs(side_1-side_2) <= 0.1)
			{
				cout << "The paving stone is a square.";
			}
			else
				cout << "The paving stone is a rectangle.";
		}
		else
		{	
			cout << "The paving stone is a parallelogram. ";
		}
	}
	else
	{
		cout <<"Invalid data out of range";
		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
}

/*
test case 1:

Enter two adjacent sides and a contained angle: 8.3 6.4 180
Invalid data out of range
--------------------------------
Process exited after 2.052 seconds with return value 1
Press any key to continue . . .

test case 2:

Enter two adjacent sides and a contained angle: 2.5 2.401 89.501
The paving stone is a square.
--------------------------------
Process exited after 1.73 seconds with return value 0
Press any key to continue . . .

test case 3: 

Enter two adjacent sides and a contained angle: 3.1 3.1 90.501
The paving stone is a parallelogram.
--------------------------------
Process exited after 2.034 seconds with return value 0
Press any key to continue . . .

test case 4: 9.101 9 90.49

Enter two adjacent sides and a contained angle: 9.101 9 90.49
The paving stone is a rectangle.
--------------------------------
Process exited after 1.978 seconds with return value 0
Press any key to continue . . .

*/