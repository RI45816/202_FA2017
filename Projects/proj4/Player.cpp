/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*****************************************
 ** File:    Player.cpp
 ** Project: CMSC 202 proj4, Fall 2017
 ** Author:  Uzoma Uwanamodo
 ** Date:    11/12/2017
 ** Section: 02
 ** E-mail:  uu3@umbc.edu
 ** 
 ** This file contains the definition for the Player class.
 ** 
 ** 
 ** 
 ** 
 *********************************************/

#include <iostream>
#include "Player.h"

using namespace std;

Player::Player() {
    m_grid = new Grid();
}

// Grid
// Constructor function for Player that creates a player with a new grid file
Player::Player(string file) : m_grid(new Grid(file)) {
}

// getGrid
// Accessor function for m_grid
Grid* Player::getGrid() {
    return m_grid;
}

Player::~Player() {
    delete m_grid;
}

// printBoard
// Print out the grid
void Player::printBoard() {
    cout << m_grid->print(false) << endl;
}

// hasLost
// If the player's grid has no occupied spaces left, then they've lost
bool Player::hasLost() {
    return m_grid->noOccupiedLeft();
}
