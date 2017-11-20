/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*****************************************
 ** File:    main.cpp
 ** Project: CMSC 202 proj4, Spring 2017
 ** Author:  Uzoma Uwanamodo
 ** Date:    00/12/2017
 ** Section: 05
 ** E-mail:  uu3@umbc.edu
 ** 
 ** This file contains the main driver program for proj4.
 ** 
 ** 
 ** 
 ** 
 *********************************************/

#include <cstdlib>
#include "Grid.h"
#include "Player.h"
#include "User.h"
#include "Computer.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    if (argv[1] > 0)
        cout << "Ships loaded" << endl;
    else {
        cout << "No text file loaded - try make run1" << endl;
        return 0;
    }

    Player * players[2] = {new Computer(argv[1]), new User(argv[2])}; // Array to store players, create user and computer
    Grid * grids[2] = {players[0]->getGrid(), players[1]->getGrid()}; // Store player grids

    // Print boards
    players[0]->printBoard();
    players[1]->printBoard();

    int turnIndicator = 0; // Indicates who turn it is, starts with Computer's turn
    
    // Play game
    while (true) {
        
        // Players switch off attacking
        players[turnIndicator]->makeMove(grids[turnIndicator^1]);
        players[turnIndicator^1]->printBoard();
        
        // If the other player lost, current player won
        if (players[turnIndicator^=1]->hasLost()) {
            cout << (!turnIndicator ? "You won!" : "Computer has won") << endl;
            delete &players[0];
            delete &players[1];
            return 0;
        }
        }
    return 0;
}