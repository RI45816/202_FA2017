/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*****************************************
 ** File:    MusicPlayer.cpp
 ** Project: CMSC 202 Project 5, Fall 2017
 ** Author:  Uzoma Uwanamodo
 ** Date:    11/24/2017
 ** Section: 02
 ** E-mail:  uu3@umbc.edu
 ** 
 ** This file contains the definition for the MusicPlayer class.
 ** 
 ** 
 ** 
 ** 
 *********************************************/

#include <iostream>
#include <fstream>
#include "MusicPlayer.h"

using namespace std;

int year; // Store user year choice


// MusicPlayer
// Constructor for MusicPlayer class
MusicPlayer::MusicPlayer() {
}

// ~MusicPlayer
// Destructor for MusicPlayer
MusicPlayer::~MusicPlayer() {
//    delete &m_songCatalog;
    m_songCatalog.erase();
    m_songCatalog.clear();
    vector<Song*>().swap(m_songCatalog);
//    delete m_playList;
}

// MusicPlayer
// Overriden constructor for MusicPlayer
MusicPlayer::MusicPlayer(string filename)
{
    LoadCatalog(filename); // Load the music catalog
}


// LoadCatalog
// Load the music catalog from the CSV file
void
MusicPlayer::LoadCatalog(string filename)
{
    ifstream file(filename.c_str());
    
    // Store song tag info
    string title, artist, rank;
    int year;

    // Loop through file, parse lines, and add to music catalog
    while (!file.eof()) {
//        file >> rank;
        getline(file,rank,',');
        getline(file,title,',');
        getline(file,artist,',');
        file >> year;
        m_songCatalog.push_back(new Song(title,artist,year,atoi(rank.c_str())+100*(year-1983)));
    }    
    cout << "Music Catalog Loaded" << endl;
}


// MainMenu
// Display the main menu and process user choice
void
MusicPlayer::MainMenu() {

    int menuOption; // Store user choice

    // Do until user quits
    while (true) {

        // Show menu and ask user for option, validating input in the process
        do {
            cout << "\nWhat would you like to do?" << endl;
            cout << "1. Display Songs by Year" << endl;
            cout << "2. Add Song" << endl;
            cout << "3. Display Playlist" << endl;
            cout << "4. Quit" << endl;
            cin >> menuOption;
        } while (menuOption < 1 || menuOption > 4);

        switch (menuOption) {
            case 1:
                DisplaySongs();
                break;
            case 2:
                AddSong();
                break;
            case 3:
                DisplayPlaylist();
                break;
            case 4:
                return;
                break;
        }
                year = 0;
    }

}


// DisplaySongs
// Display the top 100 songs of a particular year
void
MusicPlayer::DisplaySongs()
{
//    int year; // Store user year choice
    
    // Ask user for year, validating input
    do {
    cout << "Which year would you like to display? (1983-2013)" << endl;
    cin >> year;
    } while (year < 1983 || year > 2013);
    
    // Display top 100 songs from specified year, in order of popularity
    cout << "******"<<year<<"*****" << endl;
    for (int i,j=i=(year-1983)*100;i<j+100;i++) {
        cout << i+1 <<". " << m_songCatalog[i]->GetTitle() <<" by " << m_songCatalog[i]->GetArtist() << endl;
    }
}

// AddSong
// AddSong to the playlist
void
MusicPlayer::AddSong()
{
    cout << "***Current Playlist" << (m_playList.isEmpty() ? " is Empty" : m_playList.isFull() ? " is Full" : "") << "***" << endl;
    
    m_playList.isFull();
    // If the playlist is full, end the function
    if (m_playList.isFull())
        return;

        cout << "Choose the songs you would like to add to the playlist." << endl;
        DisplaySongs();
    
        int songRank; // Store rank of song user selected
        
        do {
        cout << "Enter the number of the song you would like to add:" << endl;
        cin >> songRank;
        } while ((songRank-1)/100 != year-1983);
        
        m_playList.enqueue(*m_songCatalog[songRank-1]);
        
}


// DisplayPlaylist
// Display the playlist
void
MusicPlayer::DisplayPlaylist()
{
    // Loop through playlist and print out all the songs
    for (int i=0;  i<m_playList.size(); i++) {
        cout << i+1 <<". " << m_playList[i].GetTitle() <<" by " << m_playList[i].GetArtist() << endl;
    }
}


