/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*****************************************
 ** File:    proj1.cpp
 ** Project: CMSC 202 Project 1, Fall 2017
 ** Author:  Uzoma Uwanamodo
 ** Date:    09/27/2017
 ** Section: 02
 ** E-mail:  uu3@umbc.edu
 ** 
 ** This file contains the main driver program for Project 1.
 ** 
 ** 
 ** 
 ** 
 *********************************************/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int NUM_ITEMS = 10; // Size of menu
const int MAX_ORDERS = 3; // Max number of order
const double MD_TAX_RATE = .06; // Maryland Tax rate (6%)


//-----------------------------------------------
// MainMenu
// PreCondition: User input is an integer, items and prices arrays already loaded
// PostCondition: Select menu option and run related function
//-----------------------------------------------
void MainMenu(string[], double[], int);

//-----------------------------------------------
// GenerateReceipts
// PreCondition: 2D arrays with orders, items and prices arrays already loaded
// PostCondition: Takes orders array and prints receipt
//-----------------------------------------------
void GenerateReceipts(string[], double[], int[][2], int);

//-----------------------------------------------
// ManageOrder
// PreCondition: items and prices arrays already loaded
// PostCondition: Prompt user for their order
//-----------------------------------------------
void ManageOrder(string[], double[], int);

//-----------------------------------------------
// LoadItems
// PreCondition: None
// PostCondition: Loads the items and prices arrays
//-----------------------------------------------
void LoadItems(string[], double[], int);

//-----------------------------------------------
// ReadReceipt
// PreCondition: None
// PostCondition: Parse receipt file into order array
//-----------------------------------------------
void ReadReceipt(string items[], double prices[]);

/*
 * GenerateReceipt
 * Take order data and generate a receipt
 */
void GenerateReceipts(string items[], double prices[], int orders[][2], int size) {
    ofstream file("proj1_receipt.txt"); // store receipt file

    // Show user their final order, write order to file
    cout << "Your Order:" << endl;
    cout << setw(6) << "Qnty" << setw(20) << "Item" << setw(14) << "Price" << endl;
    for (int j = 0; j < size; j++) {
        cout << setw(6) << orders[j][0] << setw(20) << items[orders[j][1] - 1] << setw(10) << "$" << fixed << setprecision(2) << prices[orders[j][1] - 1] << endl;
        file << orders[j][0] << " " << orders[j][1] << endl;
    }
    // Generate subtotal
    double subtotal = 0; // Keep track of subtotal
    for (int j = 0; j < size; j++)
        subtotal += prices[orders[j][1] - 1] * orders[j][0];

    // Print receipt
    cout << "Subtotal: " << subtotal << endl;
    cout << "Tax: " << subtotal * MD_TAX_RATE << endl;
    cout << "Total: " << subtotal * (1 + MD_TAX_RATE) << endl;
    cout << "Receipt Written" << endl;
}

/* 
 * ReadReceipt
 * Read receipt from file
 */
void ReadReceipt(string items[], double prices[]) {
    ifstream file("proj1_receipt.txt"); // read receipt file
    int orders[MAX_ORDERS][2]; // store orders
    int i = 0; // incrementer

    // Read and parse receipt file
    while (!file.eof())
        file >> orders[i - 1][0] >> orders[i++][1];
    file.close();

    GenerateReceipts(items, prices, orders, i - 1); // Show receipt
}

/*
 * ManageOrder
 * Keep track of user order
 */

void ManageOrder(string items[], double prices[], int size) {ggi
    int orders[MAX_ORDERS][2]; // Store all of the ordered items
    int i = 0; // Incrementer
    string goOn; // Store user answer for "Do you want to add more items"

    // Display order menu
    cout << setw(6) << "Number" << setw(21) << "Item" << setw(14) << "Price" << endl;
    for (int i = 0; i < size; i++)
        cout << setw(6) << i + 1 << "." << setw(20) << items[i] << setw(10) << "$" << fixed << setprecision(2) << prices[i] << endl;

    // Get user order
    do {
        do {
            cout << "What would you like to buy?:" << endl;
            cin >> orders[i][1];
        } while (orders[i][1] < 1 || orders[i][1] > size);
        cout << "How many would you like to buy?" << endl;
        cin >> orders[i][0];
        if (i < 2)
            do {
                cout << "Do you want to add more items? (y/n):" << endl;
                cin >> goOn;
            } while (goOn != "y" && goOn != "n" && goOn != "Y" && goOn != "N");
    } while (i++ < 2 && (goOn == "y" || goOn == "Y"));

    GenerateReceipts(items, prices, orders, i);
}

/*
 * LoadItems
 * Load list of menu items from items file
 */
void LoadItems(string items[], double prices[], int size) {
    string blank;
    ifstream file("proj1_items.txt"); // item file
    // Loop through file and read in item and price
    for (int i = 0; i < size; i++) {
        getline(file, items[i], ',');
        file >> prices[i];
        getline(file, blank);
    }
}

/*
 * MainMenu
 * Display main menu and ask user to pic an option
 */
void MainMenu(string items[], double prices[], int size) {
    int menuOption; // User menu option

    while (true) {
        // Ask user for menu input and validate it
        do {
            cout << "What would you like to do?:" << endl;
            cout << "1. New Order" << endl;
            cout << "2. View Receipts" << endl;
            cout << "3. Exit" << endl;
            cin >> menuOption;
        } while (menuOption < 1 || menuOption > 3);

        // Process user menu option
        switch (menuOption) {
            case 1:
                ManageOrder(items, prices, size);
                break;
            case 2:
                ReadReceipt(items, prices);
                break;
            case 3:
                cout << "Thank you for using True Grit Snack Bar" << endl;
                return;
                break;
        }
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    string items[NUM_ITEMS];
    double prices[NUM_ITEMS];
    LoadItems(items, prices, NUM_ITEMS);
    cout << "The item list was successfully loaded" << endl;
    cout << "Welcome to the True Grit Snack Bar" << endl;
    MainMenu(items, prices, NUM_ITEMS);
    return 0;
}

