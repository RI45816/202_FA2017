/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Helicopter.h"
#include <iostream>
#include <string>

void Helicopter::Display() {
    cout << endl << "Displaying Helicopter names." << endl;
    for (int i = 0; i < m_num; i++)
        cout << "Helicopter name " << i + 1 << ": " << m_ptr[i] << endl;
}

Helicopter::Helicopter() {
    cout << "Enter amount of Helicopters in your fleet: ";
    cin >> m_num;
    m_ptr = new string[m_num];
    cout << "Enter the name of Helicopter:" << endl;
    for (int i = 0; i < m_num; i++) {
        cout << "Helicopter name " << i + 1 << ": ";
        cin >> m_ptr[i];
    }
}

Helicopter::~Helicopter() {
    delete [] m_ptr;
}

