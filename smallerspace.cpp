#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(){
	
	bool check_drive = false;
	string check_drivestr = "";
	
	do{
		cout << "Check your OneDrive space!" << endl
			 << "Have you checked Y/N? ";
		cin >> check_drivestr ;
		if (check_drivestr == "Y" || check_drivestr == "y")
		{
			check_drive = true;
		}
		else
			check_drive = false;
	}while(check_drive == false);
	
	return EXIT_SUCCESS;
}
