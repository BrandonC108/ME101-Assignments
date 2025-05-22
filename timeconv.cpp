#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	int time_s = 0, time_m = 0, time_h = 0;
	
	cout << "input time in seconds: " ;
	cin >> time_s;
	
	if(time_s >=0)
	{
		
		time_m = time_s / 60;
		time_s = time_s % 60;
		time_h = time_m / 60;
		time_m = time_m % 60;
		
		cout << time_h << " hours "<< time_m << " minutes "
			 << time_s << " seconds.";
		
		
		
	}
	else
	cout << "error";
	
	
	return EXIT_SUCCESS;
}