/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*****************************************
 ** File:    User.cpp
 ** Project: CMSC 202 proj4, Fall 2017
 ** Author:  Uzoma Uwanamodo
 ** Date:    11/14/2017
 ** Section: 02
 ** E-mail:  uu3@umbc.edu
 ** 
 ** This file contains the definition for the User class.
 ** 
 ** 
 ** 
 ** 
 *********************************************/

#include <iostream>
#include "User.h"

using namespace std;

// User
// Default constructor
User::User() {
}

// User
// Constructor, inherit from parent Player class
User::User(string file):Player(file) {
}

void User::makeMove(Grid* grid) {
    int x, y, attackResult; // Stores users attack coordinates
    
    do {
    // Get attack coordinates
    cout << "Enter square to attack:" << endl;
    do {
        cout << "Enter x (column): " << endl;
        cin >> x;
    } while (x < 0 || x > Grid::SIZE);
    do {
        cout << "Enter y (row): " << endl;
        cin >> y;
    } while (y < 0 || y > Grid::SIZE);
    
    // Process attack, if user attacks area they already attacked, they can go again
    attackResult = grid->attack(x,y);
    switch (attackResult) {
        case Grid::MISS:
            cout << "You missed" << endl;
            break;
        case Grid::HIT:
            cout << "You Hit Something!!!" << endl;
            break;
        case 0:
            cout << "You already tried hitting here" << endl;
            break;
    }
    }while (!attackResult);
}

// printBoard
// Print out the board
void User::printBoard() {
    cout << "********USER*********" << endl;
    Player::printBoard();
}
