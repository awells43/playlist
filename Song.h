//
// Created by jense on 12/2/2021.
//

#ifndef MAINLAB8_SONG_H
#define MAINLAB8_SONG_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Song{
private:
    string title;
    string firstLine;
    int timesPlayed;
public:
    Song();
    Song(string userTitle, string userFirstLine);
    void AddSongs();
    string GetSongName();
    string GetFirstLine();
    void AddTimesPlayed();
    int GetTimesPlayed();
};

#endif //MAINLAB8_SONG_H
