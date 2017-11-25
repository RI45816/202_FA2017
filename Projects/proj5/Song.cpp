/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*****************************************
 ** File:    Song.cpp
 ** Project: CMSC 202 Project 5, Fall 2017
 ** Author:  Uzoma Uwanamodo
 ** Date:    11/24/2017
 ** Section: 02
 ** E-mail:  uu3@umbc.edu
 ** 
 ** This file contains the definition for the Song class.
 ** 
 ** 
 ** 
 ** 
 *********************************************/

#include <iostream>
#include "Song.h"

using namespace std;

// Song
// Constructor for Song class
Song::Song() {
}

// Song
// Overrided constructor for Song class
Song::Song(string title, string artist, int year, int rank) : m_title(title), m_artist(artist), m_year(year), m_rank(rank)
{
}

// SetRank
// Mutator function for m_rank
void Song::SetRank(int rank) {
    m_rank = rank;
}

// GetRank
// Accessor function for m_rank
int Song::GetRank() const {
    return m_rank;
}

// SetYear
// Mutator function for m_year
void Song::SetYear(int year) {
    m_year = year;
}

// GetYear
// Accessor function for m_year
int Song::GetYear() const {
    return m_year;
}

// SetArtist
// Mutator function for m_artist
void Song::SetArtist(string artist) {
    m_artist = artist;
}

// GetArtist
// Accessor function for m_artist
string Song::GetArtist() const {
    return m_artist;
}

// SetTitle
// Mutator function for m_title
void Song::SetTitle(string title) {
    m_title = title;
}

// GetTitle
// Accessor function for m_title
string Song::GetTitle() const {
    return m_title;
}


