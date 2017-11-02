/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*****************************************
 ** File:    CipherString.cpp
 ** Project: CMSC 202 proj3, Fall 2017
 ** Author:  Uzoma Uwanamodo
 ** Date:    11/02/2017
 ** Section: 02
 ** E-mail:  uu3@umbc.edu
 ** 
 ** This file contains the definition for the CipherString class.
 ** 
 ** 
 ** 
 ** 
 *********************************************/

#include <iostream>
#include "CipherString.h"

using namespace std;

CipherString::CipherString() {
}

//CipherString
//Constructor for CipherString, create a linked list from the character array

CipherString::CipherString(const char* filename) {
    ifstream file(filename);
    string text;
    getline(file, text);
    loadMessage(text.c_str());
}

// loadMessage
// Load message from the file 
void CipherString::loadMessage(const char* text) {
    m_head = new Node(text[0]);
    m_size++;
    for (m_size = 1; text[m_size]>='A'; m_size++)
        addCharacter(text[m_size]);
}


//CipherString::CipherString(const CipherString& orig) {
//}

//CipherString::~CipherString() {
//        Node * ptrNode = m_head;
//        while (ptrNode != NULL) {
//            ptrNode = m_head->getNext();
//            delete m_head;
//            m_head = ptrNode;
//        }
//    }

// addCharacter
// Add a character to the linked list

void CipherString::addCharacter(char c) {
    Node * curNode = m_head;
    while (curNode->getNext())
        curNode = curNode->getNext();
    curNode->setNext(new Node(c));
}

// getSize
// Accessor function for m_size
int CipherString::getSize() {
    return m_size;
}

// addIntToChar
// Process the addition of the key to the character
char CipherString::addIntToChar(char c, int key) {
    int i = c; // integer equivalent of the character
    bool lower = (c >= 'a'); // determine whether or not the character is lowercase
    i -= (lower ? 'a' : 'A'); // map A-Z or a-z character to 0-25 range integer
    i += key; //  Add the key to the mapped character integer
    i %= 26; // Map new character integer to 1-25 range
    if (i < 0) 
        i = 26 + i; // If the new character integer is negative, map it to 1-25 range
    i += (lower ? 'a' : 'A'); // Change the new character integer to ASCII (same case)
    c = i; // Change ASCII to letter character
    return c; // return the ciphered character
}



// decryptCeasar
// Take Ceaser key and decrypt the message
void CipherString::decryptCaesar(int key) {
    
    // Go through all the characters in the linkedlist and cipher them
    for (Node * curNode = m_head; curNode; curNode = curNode->getNext()) 
        curNode->setChar(addIntToChar(curNode->getChar(),-key));
       
}

// encryptCeasar
// Take Ceaser key and encrypt the message
void CipherString::encryptCaesar(int key) {
    
    // Go through all the characters in the linkedlist and cipher them
    for (Node * curNode = m_head; curNode; curNode = curNode->getNext())
        curNode->setChar(addIntToChar(curNode->getChar(),key));
    
}

// encryptVigenere
// Take the key and the text and encrypt it through vigenere square
void CipherString::encryptVigenere(string key) {
    
    // Create vignere square
    int keySize=key.length(),keys[keySize];
    for (int i=0;i<keySize;i++)
        keys[i]=tolower(key[i])-'a'+1;
    
    int i=0;
    for (Node * curNode = m_head; curNode; curNode = curNode->getNext(),i++)
        curNode->setChar(addIntToChar(curNode->getChar(),keys[i%keySize]));
}

// decryptVigenere
// Take the key and the text and decrypt it through vigenere square
void CipherString::decryptVigenere(string key) {
    
    // Create vignere square
    int keySize=key.length(),keys[keySize];
    for (int i=0;i<keySize;i++)
        keys[i]=tolower(key[i])-'a'+1;
    
    int i=0;
    for (Node * curNode = m_head; curNode; curNode = curNode->getNext(),i++)
        curNode->setChar(addIntToChar(curNode->getChar(),-keys[i%keySize]));
}


// ostream operator <<
// Print out characters of CipherString

ostream& operator<<(ostream& os, const CipherString& cs) {
    string text;
    
    // Go through all the characters in the linkedlist and print them out
    for (Node * curNode = cs.m_head; curNode; curNode = curNode->getNext())
        text += curNode->getChar();
    return os << text;
}
