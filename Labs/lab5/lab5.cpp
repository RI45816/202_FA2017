// File: lab5.cpp
//
// Demonstrates use of the vampire class.
// Compile together with vampire.cpp in a makefile
//

#include <iostream>
#include "Vampire.h"

using namespace std;

int main() {
    // Instantiate "Vampire" class twice
    // Create "vamp1" object and "vamp2" object
    Vampire vamp1, vamp2;

    //Part 1: Using setters to set data for vamp1 and vamp2
    // name and age
    vamp1.SetValues("Bill", 145);
    vamp2.SetValues("Lestat", 259);


    //Part 2: Using getters to get original info for vamp1 & vamp2:

    cout << "Vamp1's original data:" << endl;
    cout << "        Name is: " << vamp1.GetName() << endl;
    cout << "        Age is: " << vamp1.GetAge() << endl;
    cout << "Vamp2's original data:" << endl;
    cout << "        Name is: " << vamp2.GetName() << endl;
    cout << "        Age is: " << vamp2.GetAge() << endl;










    // MODIFY vamp1 and vamp2, BY USING THE VAMPIRE CLASS METHODS,
    // TO SET THE "type" FIELD TO SOMETHING NEW, GET THE FIELDS
    // BACK OUT AND PRINT

    //Part 3: Using the value setter to update private data members for vamp2
    // set new name and age for vamp2
    vamp2.SetValues("David",25);

    // Display vamp2's new name
    cout << "You changed your vamp2's name." << endl;
    cout << "Vamp2's new name is: " << vamp2.GetName() << endl;


    //Part 4: Feeding and Flying
    //If the vampire's teeth are visible then they can feed
    //If the vampire is at least 30 years old, they can change to a bat and fly
    vamp1.Fly();
    vamp2.Fly();
    vamp1.SuckBlood("Sookie");
    vamp2.SuckBlood("Sookie");




    // Part 5: Activate your teeth and try to suck blood again



    vamp1.ActivateTeeth();
    vamp2.ActivateTeeth();
    vamp1.SuckBlood("Sookie");
    vamp2.SuckBlood("Sookie");
    


    return 0;

}
