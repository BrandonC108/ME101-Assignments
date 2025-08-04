#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

double f_to_c(double degree_f){
	
	double degree_c = (degree_f -32)*(5.0/9);
	
	return degree_c;
}

string classification (double degree_c){
	
	if (degree_c >= 10 && degree_c <= 25){
		
		return "warm";
	}
	else if (degree_c > 25){
		return "hot";
	}
	else{
		return "cold";
	}
	
}
int main(){
	double degree_f = 0;
	
	do{
		cout << "Enter the temeperature in F.";
		cin >> degree_f;
	} while (degree_f < -85 && degree_f > 125);
	
	cout << f_to_c(degree_f) << " degrees celsius. The temperature is " 
	     << classification(f_to_c(degree_f)) << ".";
	
	return EXIT_SUCCESS;
}