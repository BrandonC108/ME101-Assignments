#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){
	
	ifstream fin("premiers.txt");
	
	if (!fin){
		
		cout << "file not opened";
		return EXIT_FAILURE;
	}
	
	
	fin.close();
	return EXIT_SUCCESS;
}