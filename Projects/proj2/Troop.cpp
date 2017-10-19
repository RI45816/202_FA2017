/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*****************************************
 ** File:    Troop.cpp
 ** Project: CMSC 202 Project 2, Fall 2017
 ** Author:  Uzoma Uwanamodo
 ** Date:    10/19/2017
 ** Section: 02
 ** E-mail:  uu3@umbc.edu
 ** 
 ** This file contains the definition for the Troop class.
 ** 
 ** 
 ** 
 ** 
 *********************************************/

#include <iostream>
#include "Troop.h"

using namespace std;


// Troop
// Constructor, creates a new troop

Troop::Troop(string name, int health, int damage, string target, bool isFlying) : m_name(name), m_health(health), m_damage(damage), m_target(target), m_isFlying(!!isFlying) {

}

// GetIsFlying
// Return whether or not the Troop is flying

bool Troop::GetIsFlying() {
    return m_isFlying;
}

// GetTarget
// Shows what kind of Troop the Troop can  attack

string Troop::GetTarget() {
    return m_target;
}

// GetDamage
// Return the damage taken by troop

int Troop::GetDamage() {
    return m_damage;
}

// SetHealth
// Set the health of the troop

void Troop::SetHealth(int health) {
    m_health -= health;
}

// GetHealth
// Return the health of the Troop

int Troop::GetHealth() {
    return m_health;
}

// SetName
// Set the name of the Troop

void Troop::SetName(string name) {
    m_name = name;
}

// GetName
// Return the name of the Troop

string Troop::GetName() {
    return m_name;
}

//AttackTroop
// Simulate this Troop attacking another

void Troop::AttackTroop(Troop& T) {
    // Determine if target is flying
    if (T.GetIsFlying())
        // If the target is flying, determine if troop can attack flying troops
        if (T.GetTarget() == "Both") {
            T.SetHealth(m_damage);
            cout << m_name << " attacks " << T.GetName() << " in the air!" << endl;
            cout << "Damage Occurring " << m_damage << endl;

        }            // If the troop can't attack flying targets, the attack misses
        else
            cout << T.GetName()<<" is a flying troop. " << m_name << " can't attack flying troops. The attack missed" << endl;
        // If the target is on the ground, then the troop can attack it, regardless
    else {
        T.SetHealth(m_damage);
        cout << m_name << " attacks " << T.GetName() << " on the ground!" << endl;
        cout << "Damage Occurring " << m_damage << endl;
    }
    
    // If attack killed target, display message
    if (T.GetHealth() <=0) {
        cout << T.GetName() << " dies" << endl;
    }
}




//Troop::Troop(const Troop& orig) : m_name(orig.name), m_health(orig.health), m_damage(orig.damage), m_target(orig.target) {
//    
//}

//Troop::~Troop() {
//}

