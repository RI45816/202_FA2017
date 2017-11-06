/*Title: lab9.cpp
Author: Jeremy Dixon
Date: 7/25/2017
Description: This is a templated example that rotates three variables
*/
#include <iostream>
#include <string>
using namespace std;

/*
Below is a templated function named rotate() that rotates 
the three items passed to it. The template is designed to accept an int, char, 
double, float, or string. The parameters are value1, value2, and value3. 
The variable value1 moves to value2. The variable value 2 moves to value3. 
The variable value3 moves to value1.

Your job is to implement an overloaded version of printThree and an overloaded version of rotate
that works with example 3 which is a char*

Step 1: Write overloaded printThree for char pointers
Step 2: Write overloaded rotate function for char pointers

*/

//Function Definitions here!

template <class T>
void rotate(T &value1, T &value2, T &value3){
  T temp;
  T temp2;
  temp = value2;
  temp2 = value3;
  value2 = value1;
  value3 = temp;
  value1 = temp2;
}
//Write overloaded rotate function so that example 3 works correctly



template <class T>
void printThree(T value1, T value2, T value3){
  cout << "value1=" << value1 << " value2=" << value2 << " value3=" << value3 << endl;
}

//Write overloaded printThree function so that example 3 works correctly.




int main () {
  char a1 = 'A';
  char b1 = 'F';
  char c1 = 'B';
  double a2 = 5.3;
  double b2 = 15.1;
  double c2 = 1.2;
  char* a3 = &a1;
  char* b3 = &b1;
  char* c3 = &c1;

  cout << "Example 1 - Characters" << endl;
  printThree(a1,b1,c1);
  rotate(a1,b1,c1);
  printThree(a1,b1,c1);
  cout << endl;

  cout << "Example 2 - Doubles" << endl;
  printThree(a2,b2,c2);
  rotate(a2,b2,c2);
  printThree(a2,b2,c2);
  cout << endl;

  cout << "Example 3 - Char Pointer" << endl;
  printThree(a3,b3,c3);
  rotate(a3,b3,c3);
  printThree(a3,b3,c3);
  cout << endl;

  cout << "Check for our characters from example 1" << endl;
  printThree(a1,b1,c1);

  return 0;
}
