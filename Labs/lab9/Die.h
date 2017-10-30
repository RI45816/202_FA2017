//Name: Die.cpp
//Author: Jeremy Dixon
//Date: 10/29/2017
//Description: This is a parent class of a Die (as in one small plastic cube that has
// some number of sides with a number on each side
#ifndef DIE_H
#define DIE_H
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Die{
 public:
  Die(); //Default constructor
  Die(int); //Overloaded constructor
  int getSides(); //Returns m_numSides
  void setSides(int); //Sets m_numSides
  virtual int rollDie(); //Returns a number between 1 and m_numSides
 protected:
  int m_numSides;
};

#endif
