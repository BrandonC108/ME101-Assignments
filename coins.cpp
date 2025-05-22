#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	const int dime = 10, nickel = 5, quarter = 25;
	int n_dime = 0, n_nickel = 0, n_quarter = 0, n_cent = 0;
	
	cout << "Enter amount in cents: ";
	cin >> n_cent;
	
	if (n_cent >= 0){
		n_quarter = n_cent/quarter;
		n_cent = n_cent%quarter;
		n_dime = n_cent/dime;
		n_cent = n_cent%dime;
		n_nickel = n_cent/nickel;
		n_cent = n_cent%nickel;
		if (n_cent < 2){
			n_nickel=n_nickel;
		}
		else{
			n_nickel += 1;
		}
		
	}
	cout << n_quarter << " Quarters, "<< n_dime << " Dimes, "
	<< n_nickel << " Nickels.";
	
	
	return EXIT_SUCCESS;
}