#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){
	
	ifstream fin("allStudent.txt");
	
	if (!fin){
		
		cout << "file not opened";
		return EXIT_FAILURE;
	}
	
	string student = "";
	int student_grade = 0, last_grade = 0;
	
	
	while(fin >> student)
	{
		int test_improve = 0;
		for(int test = 1; test <= 5 ; test++)
		{
			fin >> student_grade;
			if(student_grade > last_grade)
			{
				if(test == 1)
				{
					
				}
				else{
				
					test_improve += 1;
				}
				
			}
			last_grade = student_grade;
			
		}
		cout << student << " improved on " << test_improve 
			 << " test" << endl;
	}
	
	fin.close();
	
	return EXIT_SUCCESS;
	
}