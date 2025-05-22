/*
 Brandon Choi
 
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
    ofstream fileOut("square.txt");
    
    int number = 9;
    
    cout << "Enter value" << endl;
    cin >> number; 

    cout << "The square of " << number 
         << " is " << number*number << endl;

    cout << "& the cube of " << number 
         << " is " << pow(number, 3) << endl;
         
    fileOut << number << " squared is " << number*number << endl;
    
    return EXIT_SUCCESS;
}

/*
Enter value
5
The square of 5 is 25
& the cube of 5 is 125

--------------------------------
Process exited after 12.49 seconds with return value 0
Press any key to continue . . .
*/
