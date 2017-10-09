#include "Student.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void fillVector(vector<Student>&);
// fill vector - fills student info
// @param vector<Student>& - students in class
// Passed by reference
void printVector(vector<Student>&);
// printVector - prints the information of all students
// @param const vector<Student>& students in class
// Passed by reference

int main () {
  //Creates a new vector of Students
  vector<Student> myClass;
  //Populates the vector
  fillVector(myClass);
  //Prints the contents of the vector
  printVector(myClass);

  return 0;
}

void fillVector(vector<Student>& newMyClass) {
  //Write this function
  //Needs to ask how many students
  //Gets first name, last name, and ID of a student
  //Uses the overloaded constructor for the Student
  //Needs to add student to the vector

}

void printVector(vector<Student>& newMyClass){
  //Needs to loop through the vector of Students and outputs the information
}
