/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*****************************************
 ** File:    Computer.cpp
 ** Project: CMSC 202 proj4, Fall 2017
 ** Author:  Uzoma Uwanamodo
 ** Date:    11/14/2017
 ** Section: 02
 ** E-mail:  uu3@umbc.edu
 ** 
 ** This file contains the definition for the Computer class.
 ** 
 ** 
 ** 
 ** 
 *********************************************/

#include <iostream>
#include <cmath>
#include "Computer.h"

using namespace std;

// Computer
// Default constructor
Computer::Computer() {
}

// Computer
// Constructor, inherit from parent Player class
Computer::Computer(string file) : Player(file), m_yCenter(-1), m_xCenter(-1){
}

// printBoard
// Print out the board
void Computer::printBoard() {
    cout << "******COMPUTER*******" << endl;
    cout << getGrid()->print(true);
}

void Computer::makeMove(Grid* grid) {
    int x, y, attackResult; // Store attack coordinates and result from attack
    // Random attack
    int quadrant = rand() % 4, repeat = 0; // Determine what quadrant the computer should try attacking and how many times computer has tried attacking in this quadrant
    do {
        // If the computer isn't actively sinking a ship, try a random attack
        if (!~m_xCenter) {
            //            if (!~m_xLast) {
            srand(time(NULL));

            // Generate random attack coordinates
            x = rand() % 10;
            y = rand() % 10;

            // Superimpose attack coordinates onto different quadrant
            switch (quadrant + 1) {
                case 2:
                    x += 5;
                    break;
                case 3:
                    y += 5;
                    break;
                case 4:
                    x += 5;
                    y += 5;
                    break;
            }
            //              x = 5;
            //              y =1;

        }            
        else {
        // Systematically try to sink ship by attack in a linear formation
            switch (m_direction) {
                case NORTH:
                    x = m_xLast;
                    if (m_yLast > 0)
                        y = m_yLast - 1;
                    else {
                        m_direction = SOUTH;
                        y = m_yLast + 1;
                    }
                    break;
                case EAST:
                    y = m_yLast;
                    if (m_xLast < Grid::SIZE)
                        x = m_xLast + 1;
                    else {
                        m_direction = WEST;
                        x = m_xLast - 1;
                    }
                    break;
                case SOUTH:
                    if (m_yLast < Grid::SIZE) {
                        y = m_yLast + 1;
                        x = m_xLast;
                    } else {
                        m_direction = EAST;
                        x = m_xLast + 1;
                        y = m_yLast;
                    }
                    break;
                case WEST:
                    if (m_xLast > 0) {
                        x = m_xLast - 1;
                        y = m_yLast;
                    }
                    break;

            }
        }
        
        // Once x and y have been calculated, attack
        attackResult = grid->attack(x, y);
        
        // Process attack
        switch (attackResult) {
            // If the attack missed
            case Grid::MISS:
                cout << "Computer missed" << endl;
                
                // If a previous attack landed
                if (~m_xCenter && ~m_yCenter) {
                    
                    // If the computer has sunk the ship, reset center, direction, and sinking variables
                    if ((m_direction == SOUTH || m_direction == WEST) && m_sinking) {
                        m_xCenter = m_yCenter = -1;
                        m_direction = NORTH;
                        m_sinking = !1;
                    }
                    
                    // If the computer is still trying to sink to ship, change direction and try again
                    if (abs(m_xCenter - x) + abs(m_yCenter - y)) {
                        m_direction = DIRECTION(((int) m_direction + 1) % 4);
                        m_xLast = m_xCenter;
                        m_yLast = m_yCenter;
                    }
                }
                break;
                
                // If the attack hits
            case Grid::HIT:
                cout << "Computer Hit Something!!!" << endl;
                
                // Save successful attack coordinates for future attack
                m_xLast = x;
                m_yLast = y;
                
                // If this is first contact with a ship, save the coordinates
                if (!~m_xCenter) {
                    m_xCenter = x;
                    m_yCenter = y;
                    m_direction = NORTH;
                    
                    // If this first contact with a ship, then this direction is where the ship is, indicate it
                } else {
                    if (abs(m_xCenter - x) + abs(m_yCenter - y)) m_sinking = !0;
                }
                
                // If the attack lands somewhere the computer already hit
            case 0:
                
                // If this is the 5th time an attack in this quadrant hit a target that was already hit, change quadrants and try again
                if (repeat++ == 5) {
                    
                    // Make sure the game doesn't freeze
                    if (~m_xCenter && grid->isMiss(x, y))
                        m_direction = DIRECTION(((int) m_direction + 1) % 4);
                    quadrant = rand() % 4;
                    srand(time(NULL));

                    repeat = 0;
                }

        }
    } while (!attackResult);
}
