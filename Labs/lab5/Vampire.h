/*Title: Vampire.h
  Author: Jeremy Dixon
  Date: 9/29/2017
  Description: This is the class declaration for a Vampire for lab5
*/
#ifndef VAMPIRE_H //Header guards
#define VAMPIRE_H //Header guards

#include <iostream>
#include <string>
using namespace std;

class Vampire{
 public: //Access Modifier
  //Name: SetValues
  //Precondition: Age is positive
  //Postcondition: name and age are updated
  void SetValues(string name, int age);
  //Name: SuckBlood
  //Precondition: m_fangs is true
  //Postcondition: victim is fed upon
  void SuckBlood(string victimName);
  //Name: ActivateTeeth
  //Precondition: m_fangs
  //Postcondition: m_fangs are negated (true to false) or (false to true)
  void ActivateTeeth();
  //Name: GetName
  //Precondition: None
  //Postcondition: Returns name
  string GetName();
  //Name: GetAge
  //Precondition: None
  //Postcondition: Returns age
  int GetAge();
  //Name: Fly
  //Precondition: Age is checked
  //Postcondition: If age > 30 then vampire can fly
  void Fly();
 private:
  string m_name; //Name of Vampire
  int m_age; //Age of Vampire (in years)
  bool m_fangs; //Fangs position (true = open) (false = closed)
};

#endif
