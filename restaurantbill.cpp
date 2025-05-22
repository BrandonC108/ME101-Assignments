#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
	
	double subTotal = 0, tipPercent = 0;
	
	cout << "Enter subtotal, tip (0.2 for 20%): ";
	
	cin >> subTotal >> tipPercent;
	
	subTotal = abs(subTotal);
	tipPercent = abs(tipPercent);
	
	cout << "Default tax 0.13, enter yes: ";
	string response = "";
	cin >> response;
	double taxPercent = 0;
	if (response == "yes" || response == "Yes"){
		taxPercent = 0.13;
	}
	else{
		cout << "Enter tax percent (0.1 for 10%)";
		cin >> taxPercent;
		taxPercent = abs(taxPercent);
		if (taxPercent < 0 || taxPercent > 100){
			cout << "Invalid tax" << endl;
			taxPercent = -1;
		}
		
	}
	double total = 0;
	double tip = 0;
	double tax = 0;
	if (taxPercent >= 0){
		tax = subTotal*taxPercent;
		tip = (subTotal+tax)*tipPercent;
		total = subTotal+tax+tip;
		cout << "Your tax amount is " << tax 
		<< ", your tip amount is " << tip
		<< ", and your total is " << total << "."<< endl;
	}
	
	return EXIT_SUCCESS;
}