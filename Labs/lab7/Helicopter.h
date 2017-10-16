#ifndef HELICOPTER_H
#define HELICOPTER_H

#include <iostream>
#include <string>

using namespace std;

class Helicopter
{
 public:
  // Constructor should ask for user input and initialize array
  Helicopter();
  ~Helicopter();
  // Go through dynamically allocated array
  void Display();
 private:
  // number of helicopters in the fleet
  int m_num;
  // dynamically allocated array of helicopters
  string *m_ptr;
};

#endif
