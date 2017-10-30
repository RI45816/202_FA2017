/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*****************************************
 ** File:    SpecialSix.h
 ** Project: CMSC 202 lab9, Spring 2017
 ** Author:  Uzoma Uwanamodo
 ** Date:    10/30/2017
 ** Section: 05
 ** E-mail:  uu3@umbc.edu
 ** 
 ** This file contains the header for the SpecialSix class.
 ** 
 ** 
 ** 
 ** 
 *********************************************/

#ifndef SPECIALSIX_H
#define SPECIALSIX_H

#include "Die.h"

class SpecialSix : public Die {
public:
    SpecialSix();
    SpecialSix(int, int);
    int rollDie(); //Returns a number between 1 and m_numSides

private:
    int m_multiplier;
};

#endif /* SPECIALSIX_H */

