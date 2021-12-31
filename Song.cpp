//
// Created by jense on 12/2/2021.
//

#include "Song.h"

Song::Song() {
    title = "Unknown";
    firstLine = "Unknown";
}

Song::Song(string userTitle, string userFirstLine){
    title = userTitle;
    firstLine = userFirstLine;
}

string Song::GetSongName() {
    return title;
}

string Song::GetFirstLine() {
    return firstLine;
}

void Song::AddTimesPlayed() {
    timesPlayed = timesPlayed + 1;
}

int Song::GetTimesPlayed() {
    return timesPlayed;
}
