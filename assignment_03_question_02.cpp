/*
	Brandon Choi
	Stephanie Huang
*/

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(){
  
  double number1 = 0.0, number2 = 0.0;
  string operationStr = "";
  cout << "Enter two numbers and an operator (+, -, *, /, ^) " << endl;
  cin >> number1 >> number2 >> operationStr;
  
  	
  
  while (!(operationStr == "+" || operationStr == "-" || operationStr == "*"
  || operationStr == "/" || operationStr == "^")){
    cout << "Enter two numbers and an operator (+, -, *, /, ^) " << endl;
  	cin >> number1 >> number2 >> operationStr;
  	
  }
  double result = 0.0;
  if(operationStr == "+"){
    result = number1 + number2;
  }
  else if(operationStr == "-"){
    result = number1 - number2;
  }
  else if(operationStr == "*"){
    result = number1 * number2;
  }
  else if (operationStr == "/"){
    if(number2 == 0){
      cout << "invalid denominator!" << endl;
      return EXIT_FAILURE;
    }
    else{
      result = number1 / number2;
    }
  }
  else if(operationStr == "^"){
    result = pow(number1, number2);
  }
  
  cout << number1 << operationStr << number2 << "= " << result<<endl;
  
  return EXIT_SUCCESS;
}



/*
TEST CASE 01
--------------------------------
Enter two numbers and an operator (+, -, *, /, ^)
2.44
0.5
*
2.44*0.5= 1.22

--------------------------------
Process exited after 3.531 seconds with return value 0
Press any key to continue . . .


TEST CASE 02
-------------------------------------------------------------------------------
Enter two numbers and an operator (+, -, *, /, ^)
16
0.5
^
16^0.5= 4

--------------------------------
Process exited after 2.649 seconds with return value 0
Press any key to continue . . .


TEST CASE 03
Enter two numbers and an operator (+, -, *, /, ^)
12
13
+
12+13= 25

--------------------------------
Process exited after 2.116 seconds with return value 0
Press any key to continue . . .

TEST CASE 04
Enter two numbers and an operator (+, -, *, /, ^)
4
9999
-
4-9999= -9995

--------------------------------
Process exited after 3.095 seconds with return value 0
Press any key to continue . . .

TEST CASE 05
Enter two numbers and an operator (+, -, *, /, ^)
8.2
2.1
/
8.2/2.1= 3.90476

--------------------------------
Process exited after 2.621 seconds with return value 0
Press any key to continue . . .

TEST CASE 6
Enter two numbers and an operator (+, -, *, /, ^)
636292936
0
/
invalid denominator!

--------------------------------
Process exited after 1.895 seconds with return value 1
Press any key to continue . . .


TEST CASE 07
Enter two numbers and an operator (+, -, *, /, ^)
7
23825153
dog
Enter two numbers and an operator (+, -, *, /, ^)
6 3 2
Enter two numbers and an operator (+, -, *, /, ^)
6 3 _
Enter two numbers and an operator (+, -, *, /, ^)
5 3 =
Enter two numbers and an operator (+, -, *, /, ^)
4 2 ?
Enter two numbers and an operator (+, -, *, /, ^)
4 3 ?
Enter two numbers and an operator (+, -, *, /, ^)
4 3 >
Enter two numbers and an operator (+, -, *, /, ^)
3 4 /
3/4= 0.75

--------------------------------
Process exited after 29.7 seconds with return value 0
Press any key to continue . . .
*/

