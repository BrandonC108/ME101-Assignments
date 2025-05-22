/*
	Brandon Choi, Adamo Vannicola
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	ifstream fin("test_1.txt");
	
	if(!fin)
	{
		cout << "INVALID";
		return EXIT_FAILURE;
	}
	
	int day_num = 0;
	double high_temp = -10000;
	double low_temp = 10000;
	double high_p = -10000;
	
	fin >> day_num;
	for(int count = 1; count <= day_num; count++)
	{
		double current_temp = 0, current_p = 0;
		fin >> current_temp >> current_p;
		
		if(current_temp > high_temp)
		{
			high_temp = current_temp;
		}
		if(current_temp < low_temp)
		{
			low_temp = current_temp;
		}
		if(current_p > high_p)
		{
			high_p = current_p;
		}
	}
	
	cout << "The highest daily mean temperature was " << high_temp << endl;
	cout << "The lowest daily mean temperature was " << low_temp << endl;
	cout << "The highest precipitation was " << high_p << endl;
	
	
	fin.close();
	
	return EXIT_SUCCESS;
}

/*

test case 1: using temp_rain_2024.txt
The highest daily mean temperature was 26.3
The lowest daily mean temperature was -15
The highest precipitation was 65.7

--------------------------------
Process exited after 0.5842 seconds with return value 0
Press any key to continue . . .

*/