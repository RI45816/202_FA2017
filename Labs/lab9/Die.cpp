//Name: Die.cpp
//Author: Jeremy Dixon
//Date: 10/29/2017
//Description: This is a parent class of a Die (as in one small plastic cube that has
// some number of sides with a number on each side
#include "Die.h"

Die::Die(){
  m_numSides = 1;
}

Die::Die(int numSides){
  m_numSides = numSides;
}

int Die::getSides(){
  return m_numSides;
}

void Die::setSides(int numSides){
  m_numSides = numSides;
}

int Die::rollDie(){
  return (rand()% m_numSides + 1);
}
