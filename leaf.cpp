#include <iostream>
// input and output to console library //
#include <cstdlib>
//standard library//

using namespace std;
//uses standard version for functions//

int main()
{
// start code to be executed//
// { opens a block//
	
	cout <<"Enter year";
// cout is screen, << is the insertion operator//
//" " is output exactly specified, and ; is end of statement//
	// Declare a variable, type name = initial value//
	int year = 0; // where int is for integer(no decimals) and year is its assigned name//
	/* double is a floating point, includes decimals */
	cin >> year;
	// extracts input from user to replace the variable//
	cout << year - 2002 << " years ago the Leafs reached the Conference finals" << endl;
	/* the endl signals the end line
	   
	*/
	cout << "The Leafs won the cup " << year - 1967 << " years ago!" << endl;
	
	return EXIT_SUCCESS;
	// to end program//
}
