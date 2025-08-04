#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void triangle (int size){
	
	for (int row = 1; row <= size; row++)
	{
		for(int star = 1; star <= row; star++)
		{
			cout << "*";
		}
		cout << endl;
	}
	
}

int main(){
	
	int size = 0;
	bool repeat = false;
	
	do {
		cout << "size of triangle: ";
		cin >> size;
		if (size < 1 || size > 10){
		
			cout << "triangle invalid. :(" << endl 
				 << "Try again? " << endl;
				 cin >> repeat;
		}
		else{
		
			triangle(size);
			cout << "Again (1/0)? ";
			cin >> repeat;
		}
	} while (repeat == true);
	
	cout << "bye bye";	
	
	
	return EXIT_SUCCESS;

}