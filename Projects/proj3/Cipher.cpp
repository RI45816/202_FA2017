/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*****************************************
 ** File:    Cipher.cpp
 ** Project: CMSC 202 proj3, Fall 2017
 ** Author:  Uzoma Uwanamodo
 ** Date:    11/02/2017
 ** Section: 02
 ** E-mail:  uu3@umbc.edu
 ** 
 ** This file contains the definition for the Cipher class.
 ** 
 ** 
 ** 
 ** 
 *********************************************/

#include <iostream>
#include "Cipher.h"

using namespace std;

// Cipher
// Constructor for Cipher, sets encryption mode to ong

Cipher::Cipher() {
    m_mode = ONG;
}

// Cipher
// Constructor for Cipher, takes encryption key, sets encryption mode to vigenere

Cipher::Cipher(string key) : m_vig_key(key) {
    m_mode = VIGENERE;
}

// Cipher
// Constructor for Cipher, takes encryption key, sets encryption mode to caesar

Cipher::Cipher(char key) : m_caesar_key(key) {
    m_mode = CAESAR;
}

// setPlainText
// Stores the text to be encrypted in the CipherString variable

void Cipher::setPlainText(string text) {
    // Create new CipherString from file
    m_cipherString = new CipherString(text.c_str());
}

// printString
// Prints the value of the CipherString
void Cipher::printString() {
    cout << *m_cipherString;
}

// changeKey
// Change the key
void Cipher::changeKey(string key) {
    switch (m_mode) {
        case CAESAR:
            m_caesar_key = key[0];
            break;
        case VIGENERE:
            m_vig_key =key;
            break;
        case ONG:
            break;
    }
}

// decrypt
// Take decrypted CipherString and decrypt
void Cipher::decrypt() {
    switch (m_mode) {
        case CAESAR:
            m_cipherString->decryptCaesar(m_caesar_key%26);
            break;
//        case ONG:
//            m_cipherString->decryptOng();
//            break;
        case VIGENERE:
            m_cipherString->decryptVigenere(m_vig_key);
            break;
    }
    printString(); // print decrypted string
}

// encrypt
// Use encryption code to encrypt CipherString
void Cipher::encrypt() {
    switch (m_mode) {
        case CAESAR:
            m_cipherString->encryptCaesar(m_caesar_key%26);
            break;
//        case ONG:
//            m_cipherString->encryptOng();
//            break;
        case VIGENERE:
            m_cipherString->encryptVigenere(m_vig_key);
            break;
    }
    printString();// print encrypted string
}





//Cipher::Cipher(const Cipher& orig) {
//}
//
//Cipher::~Cipher() {
//}

