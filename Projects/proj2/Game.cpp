/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*********************************************
 ** File:    Game.cpp
 ** Project: CMSC 202 proj2, Fall 2017
 ** Author:  Uzoma Uwanamodo
 ** Date:    10/19/2017
 ** Section: 02
 ** E-mail:  uu3@umbc.edu
 ** 
 ** This file contains the definition for the Game class.
 ** 
 ** 
 ** 
 ** 
 *************************************************/

#include <iostream>
#include <fstream>
#include <cmath>
//#include <cstd>
#include "Game.h"

using namespace std;

// Game
// Begin new game

Game::Game() {


    cout << "Welcome to Clash UMBC" << endl; // Welcome user

    // Get User Name
    cout << "What is your name?" << endl;
    getline(cin, m_name);

    // Get maximum number of troops
    do {
        cout << "How many troops would you like? (2-5)" << endl;
        cin >>m_max;
    } while (m_max > 5 || m_max < 2);

    LoadTroops();
    RandomizeTeam();
    m_curTroop = 1; // Set the default troop in case the player doesn't
    m_curPlayer = 1; // Player gets to go first
    StartGame();
}

// LoadTroops
// Load troops from a file

void Game::LoadTroops() {
    ifstream file(PROJ2_TROOPS);

    //Holder variables
    string name, target;
    int health, damage, flying;

    // Read and parse troops file
    while (!file.eof()) {
        file >> name >> health >> damage >> target >> flying;
        m_troop.push_back(Troop(name, health, damage, target, !!flying));
    }
}

// RandomizeTeam
// Choose troops from Troop array at random

void Game::RandomizeTeam() {


    srand(time(NULL)); // Randomize
    int troopReserveSize = m_troop.size(); //  Holder variable
    //    Troop currentTroop;

    // Populate the teams
    for (int i = 0; i < m_max; i++) {
        m_player.push_back(m_troop[rand() % troopReserveSize]);
        m_computer.push_back(m_troop[rand() % troopReserveSize]);
    }
    cout << "Both teams have been populated." << endl;
}

// StartGame
// Start the Game

void Game::StartGame() {
    DisplayTeams(); // Begin the game by displaying the teams
    MainMenu();
}

void Game::DisplayTeams() {
    DisplayTeam(); // Display player's team

    cout << "***************************" << endl;
    cout << "Computer's Team" << endl;

    // Loop through all of the computer's troops and display their name and health
    for (int i = 0; i < m_computer.size(); i++) {
        cout << left << setw(20) << m_computer[i].GetName() << m_computer[i].GetHealth() << endl;
    }

}

// DisplayTeam
// Display the player's team

void Game::DisplayTeam() {
    cout << "***************************" << endl;
    cout << m_name << "'s Team" << endl;

    // Loop through all of the player's troops and display their name and health
    for (int i = 0; i < m_player.size(); i++) {
        cout << left << setw(20) << m_player[i].GetName() << m_player[i].GetHealth() << endl;
    }
}

// ChangeTroop
// Change the player's current troop

void Game::ChangeTroop() {
    do {
        cout << "Which troop do you want to use?" << endl;
        cin >> m_curTroop;
    } while (m_curTroop > m_player.size() || m_curTroop < 1);
}

//Attack
//Players attack each other

void Game::Attack() {
    vector <Troop> * troopBarracks[] = {&m_computer, &m_player}; // Troop vectors in player order
    Troop * troopTeams[] = {&m_computer[0], &m_player[m_curTroop - 1]}; // Troop pointers in player order
    int troopNumber[] = {0, m_curTroop - 1}; // Troop number in player order


    // Generalized Attack Code
    troopTeams[m_curPlayer]->AttackTroop(*troopTeams[m_curPlayer ^1]);

    // If the attack kills an enemy troop, end attack phase, delete dead enemy troop
    if (troopTeams[m_curPlayer ^ 1]->GetHealth() <= 0) {
        troopBarracks[m_curPlayer^1]->erase(troopBarracks[m_curPlayer^1]->begin() + troopNumber[m_curPlayer^1]);

        if (!troopBarracks[m_curPlayer^1]->size()) {
            if (m_curPlayer)
                cout << "You win!" << endl;
            else
                cout << "You lose" << endl;
            return;
        }

        // If the player's troop died, make them change to another troop
        if (!m_curPlayer)
            // If the player has multiple remaining troops, make them choose
            if (m_player.size() != 1) {
                cout << m_name << ", your troop died, choose another one, also, your turn is over" << endl;
                DisplayTeam();
                ChangeTroop();
            }// Otherwise, use the sole remaining
            else
                m_curTroop = 1;

    } else {
        troopTeams[m_curPlayer^1]->AttackTroop(*troopTeams[m_curPlayer]);
        // If the attack kills an enemy troop, delete dead enemy troop
        if (troopTeams[m_curPlayer]->GetHealth() <= 0) {
            troopBarracks[m_curPlayer]->erase(troopBarracks[m_curPlayer]->begin() + troopNumber[m_curPlayer]);

            if (!troopBarracks[m_curPlayer]->size()) {
                if (!m_curPlayer)
                    cout << "You win!" << endl;
                else
                    cout << "You lose" << endl;
                return;
            }

            // If the player's troop died, make them change to another troop
            if (m_curPlayer)

                // If the player has multiple remaining troops, make them choose
                if (m_player.size() != 1) {

                    cout << m_name << ", your troop died, choose another one" << endl;
                    DisplayTeam();
                    ChangeTroop();
                }                    // Otherwise, use the sole remaining
                else
                    m_curTroop = 1;

        }
    }


    m_curPlayer ^= 1; // Change player turn
}


//MainMenu
// Display and manage the menu

void Game::MainMenu() {
    int menuChoice, numChoices = 4;

    while (true) {
        do {
            // Display menu options
            cout << "***************************" << endl;
            cout << "What would you like to do?" << endl;
            cout << "1. Display Team" << endl;
            cout << "2. Change Current Troop" << endl;
            cout << "3. Attack!" << endl;
            cout << "4. Quit" << endl;
            cin >> menuChoice;
        } while (menuChoice > numChoices || menuChoice < 1);

        // Process menu choice
        switch (menuChoice) {
            case 1: // Display team
                DisplayTeam();
                break;
            case 2: // Change Current Troop
                ChangeTroop();
                break;
            case 3: // Attack
                Attack();

                // If both players still have troops, continue the game
                if (m_computer.size() && m_player.size())
                    DisplayTeams();

                    // Else, end the game, we have a winner
                else
                    return;
                break;
                break;
            case 4:
                return;
                break;
        }
    }
}



//Game::~Game() {
//}

