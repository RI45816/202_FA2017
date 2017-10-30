//Name: driver.cpp
//Author: Jeremy Dixon
//Date: 10/29/2017
//Description: This is the driver to test die and the child class

#include "Die.h"
#include "SpecialSix.h"

int main () {
  srand(time(NULL));

  Die sixSided(6); //Calls overloaded Die constructor
  SpecialSix special1(6, 3); //Calls overloaded SpecialSix constructor
  
  cout << "Using Inheritance" << endl;
  cout << sixSided.rollDie() << endl; //Should roll 1-6
  cout << special1.rollDie() << endl; //Should roll 3-18 (by 3s)

  Die *die1 = &sixSided; //Creates die pointer to sixSided
  Die *die2 = &special1; //Creates die pointer to special1

  cout << "Using Polymorphism" << endl;
  cout << die1->rollDie() << endl; //Should roll 1-6
  cout << die2->Die::rollDie() << endl; //Should roll 1-6
  cout << die2->rollDie() << endl; //Should roll 3-18 (by 3s)
  
  return 0;
}
