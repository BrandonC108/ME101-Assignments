#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(){
	
	ifstream fin ("test.txt");
	
	int test = 0;
	string word = "";
	while (fin >> word && fin)
		while (fin >> test){
			cout << "read integer";
		}
	cout << "fail to read";
	cin >> word >> test;
	cout << word << test;
	
	fin.close();
	
	return EXIT_SUCCESS;
}