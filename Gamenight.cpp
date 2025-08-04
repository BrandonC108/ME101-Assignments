/*
	Brandon Choi, Adamo Vannicola
*/

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	//variables
	int is_hungry = 0;
	string day = "";
	int time = 0;
	string is_game = "";
	//ask if hungry, time and day of week
	cout << "Enter whether hungry, day, and time: ";
	cin >> is_hungry >> day >> time;
	
	if (time >= 1 && time <= 11)//checks for valid time (1pm-11pm)
	{
		if (time > 9 && time <= 11)//checks for after 9pm to 11pm
		{
			is_game = "codenames";
		}
		else if (day == "Friday" || day == "Saturday" 
			   || day == "friday" || day == "saturday")//checks for (Fri,Sat)
		{
			if (time < 7)//checks before 7pm
			{
				is_game = "spirit island";
			}
			else//condition when between 7pm to 9pm
			{
				is_game = "ticket to ride";
			}
		}
		else // if before 9pm and not friday or saturday
		{
		
			if (day == "Sunday" || day == "sunday")//checks sunday
			{
				is_game = "mysterium";
			}
			else if (day == "monday" || day == "tuesday" || day == "wednesday" 
			|| day == "thursday" ||day == "Monday" || day == "Tuesday" 
			|| day == "Wednesday" || day == "Thursday")//Check for weekdays
				is_game = "catan";
			else//invalid day
			{
				cout << "INVALID DAY INPUT";
				return EXIT_FAILURE;
			}
		}
	}
	else //invalid time
	{
		cout << "INVALID TIME INPUT";
		return EXIT_FAILURE;
		//return EXIT_FAILURE;//ends code before checking hungry
	}
	if(is_hungry == 1)//checks for hungry 
	{
		cout << "Since hungry order pizza, on " << day <<" "<< time 
			 << " play " << is_game;
	}
	else if (is_hungry == 0)//checks for not hungry
	{
		cout << "Since not hungry only chips, on " << day <<" "<< time 
			 << " play " << is_game;
	}
	else//for invalid inputs
	{
		cout << "INVALID HUNGRY INPUT";
	}
	
	
	return EXIT_SUCCESS;
}

/*
test case 1: 1 monday 8, expected order pizza, catan

Enter whether hungry, day, and time: 1 monday 8
Since hungry order pizza, on monday 8 play catan
--------------------------------
Process exited after 1.213 seconds with return value 0
Press any key to continue . . .

test case 2: 0 sunday 10, expected chips, codenames

Enter whether hungry, day, and time: 0 sunday 10
Since not hungry only chips, on sunday 10 play codenames
--------------------------------
Process exited after 1.991 seconds with return value 0
Press any key to continue . . .

test case 3: 0 friday 6, expected chips, spirit island

Enter whether hungry, day, and time: 0 friday 6
Since not hungry only chips, on friday 6 play spirit island
--------------------------------
Process exited after 1.066 seconds with return value 0
Press any key to continue . . .


test case 4: 0 saturday 9, expected chips, ticket to ride

Enter whether hungry, day, and time: 0 saturday 9
Since not hungry only chips, on saturday 9 play ticket to ride
--------------------------------
Process exited after 1.559 seconds with return value 0
Press any key to continue . . .

test case 5: 0 sunday 3, expected chips, mysterium

Enter whether hungry, day, and time: 0 sunday 3
Since not hungry only chips, on sunday 3 play mysterium
--------------------------------
Process exited after 1.281 seconds with return value 0
Press any key to continue . . .

test case 6: 0 sunday 12, expected fail

Enter whether hungry, day, and time: 0 sunday 12
INVALID TIME INPUT
--------------------------------
Process exited after 1.247 seconds with return value 1
Press any key to continue . . .

test case 7: 2 monday 2, expected fail

Enter whether hungry, day, and time: 2 monday 2
INVALID HUNGRY INPUT
--------------------------------
Process exited after 1.316 seconds with return value 0
Press any key to continue . . .

test case 8: 1 notaday 3, expected fail

Enter whether hungry, day, and time: 1 notaday 3
INVALID DAY INPUT
--------------------------------
Process exited after 1.276 seconds with return value 1
Press any key to continue . . .

*/