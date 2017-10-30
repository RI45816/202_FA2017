/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*****************************************
 ** File:    SpecialSix.cpp
 ** Project: CMSC 202 lab9, Fall 2017
 ** Author:  Uzoma Uwanamodo
 ** Date:    10/30/2017
 ** Section: 05
 ** E-mail:  uu3@umbc.edu
 ** 
 ** This file contains the definition for the SpecialSix class.
 ** 
 ** 
 ** 
 ** 
 *********************************************/
#include <iostream>
#include "SpecialSix.h"

using namespace std;

SpecialSix::SpecialSix() {
    m_numSides = 6;
    m_multiplier = 1;
}

SpecialSix::SpecialSix(int sides, int multiplier) :  m_multiplier(multiplier) {
    m_numSides = sides;
    
}

int SpecialSix::rollDie() {
      return (rand()% m_numSides + 1) * m_multiplier;
}

