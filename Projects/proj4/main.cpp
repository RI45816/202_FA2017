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
    cout << argv[1] << " " << argv[2] << endl;
    Grid grid1(argv[1]);
    Grid grid2(argv[2]);
    cout << grid1.print(false);
    cout << grid2.print(false);
    return 0;
}

