#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

void totalbalance(double & balance, double cost){
	
	balance -= cost;
}

int main(){
	
	cout << "input balance and # of transactions";
	double balance = 0;
	int transactions = 0;
	cin >> balance >> transactions;
	
	for (int i = 1; i <= transactions; i++){
		double cost = 0;
		cout << "input cost per transaction";
		cin >> cost;
		totalbalance(balance, cost);
		
	}
	cout << balance;
	


	
	
	return EXIT_SUCCESS;
}