/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*****************************************
 ** File:    Grid.cpp
 ** Project: CMSC 202 proj4, Fall 2017
 ** Author:  Uzoma Uwanamodo
 ** Date:    11/12/2017
 ** Section: 02
 ** E-mail:  uu3@umbc.edu
 ** 
 ** This file contains the definition for the Grid class.
 ** 
 ** 
 ** 
 ** 
 *********************************************/

#include <iostream>
#include <fstream>
#include "Grid.h"

using namespace std;

// Grid
// Constructor for Grid

Grid::Grid() {
}

// Grid
// Overrided constructor for Grid that uses filename

Grid::Grid(string file) {

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            m_grid[i][j] = EMPTY;
    ifstream f(file.c_str());
    string buffer; // Store excess text when reading file
    int size, x, y; // Store size, coulumn and row numbers
    char HV; // Store the character that indictates whether ship if horizontal or vertical
    while (!f.eof()) {
        f >> size >> x >> y >> HV;
        for (int j = x, i = y, k = 0; k < size; k++, HV == HORIZONTAL ? j++ : i++)
            m_grid[i][j] = OCCUPIED;
    }
}

// print
// Print out the entire grid
string Grid::print(bool hideShips) {
    string grid = "";

    // Loop through grid array
    for (int i = -1; i < SIZE; i++) {
        for (int j = -1; j < SIZE; j++) {
            // Print out a period for an undefined square, a pound for a ship (only visible on your own grid), an O for a miss, and an X for a hit.
            if (!~j) {
                if (~i) 
                    grid += i+'0';
                else
                    grid += " ";
            } else {
                if (!~i)
                    grid += j+'0';
                else
                    switch (m_grid[i][j]) {
                        case EMPTY:
                            grid += ".";
                            break;
                        case HIT:
                            grid += "X";
                            break;
                        case MISS:
                            grid += "O";
                            break;
                        case OCCUPIED:
                            grid += hideShips ? "." : "#";
                            break;
                    }
            }
            grid += " ";
        }
        grid += "\n";
    }
    return grid + "\n";
}


// noOccupiedLeft
// Determine if there are any occupied spaces left
bool Grid::noOccupiedLeft() {
    
    // Go through every square
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (m_grid[i][j] == OCCUPIED) // If there is an occupied space, return false
                return false;
    return true; // If after going through the entire board, there isn't an occupied space, return true

}

// alreadyTried
// Return whether or not the user has already tried this space
bool Grid::alreadyTried(int x, int y) {
    return m_grid[y][x] == MISS || m_grid[y][x] == HIT;
}

// isMiss
// Return whether or not there's an occupied space where the user tried to target
bool Grid::isMiss(int x, int y) {
    return m_grid[y][x] != OCCUPIED;
}

// attack
// Process attack
int Grid::attack(int x, int y) {
    // If the player has already tried, let them know
    if (alreadyTried(x, y))
        return 0;

    // If the attack misses, return MISS, set space to MISS
    if (isMiss(x, y)) {
        m_grid[y][x] = MISS;
        return MISS;
    }
    
    // If the attack hit, return HIT, set space to HIT
    else {
        m_grid[y][x] = HIT;
        return HIT;
    }
}
