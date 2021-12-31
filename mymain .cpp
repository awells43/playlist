//
// Created by jense on 12/6/2021.
//

//A Note regarding 'using namespace std':
// The author of this code prefers to not have the line 'using namespace std;'
// Instead, you will see 'std::' in front of string, cout, and other identifiers
// You could put 'using namespace std;' at the top of your code and not need 'std::' in front of these words,
// but many people consider it better practice to not have 'using namespace std;'


#include <iostream>
#include <string>
#include <vector>

//TODO: Include your class files here
#include "Song.h"
#include "Playlist.h"

using namespace std;

// TODO: clean up memory when it is no longer used
//  (you need to find the appropriate places in the code to do this)

std::string GetUserString(const std::string& prompt);
int GetUserInt(const std::string& prompt);


int main() {
    std::cout << "Welcome to the Firstline Player!  Enter options to see menu options." << std::endl << std::endl;

    //TODO: Create vectors to hold the songs and playlists
    vector <Song*> songs;
    vector <Playlist*> playlists;

    std::string userMenuChoice = "none";
    bool continueMenuLoop = true;

    while (continueMenuLoop) {
        userMenuChoice = GetUserString("Enter your selection now: ");
        if (userMenuChoice == "add") {
            string userInput = "start";
            cout << "Enter songs' names and first lines (type \"DONE\" when done): " << endl;
            while(userInput != "DONE"){
                string userSong;
                userInput = GetUserString("Song name: ");
                userSong = userInput;
                if (userSong == "DONE") {
                    break;
                }
                string songFirstLine;
                userInput = GetUserString("Song's first line: ");
                songFirstLine = userInput;
                Song* newSong = new Song(userSong, songFirstLine);
                songs.push_back(newSong);
            }
        }
        else if (userMenuChoice == "list") {
            //TODO: Implement this menu option
            for(int i = 0; i < songs.size(); ++i){
                cout << songs.at(i)->GetSongName() << ": " << "\"" << songs.at(i)->GetFirstLine() << "\", " << songs.at(i)->GetTimesPlayed() << "play(s)." << endl; //FIXME

            }
        }
        else if (userMenuChoice == "addp") {
            //TODO: Implement this menu option
            string userInputPlaylist;
            userInputPlaylist = GetUserString("Playlist name: ");
            Playlist* newPlaylist = new Playlist(userInputPlaylist);
            playlists.push_back(newPlaylist);
        }
        else if (userMenuChoice == "addsp") {
            //TODO: Implement this menu option
            for(int i = 0; i < playlists.size(); ++i) {
                cout << i << ": " << playlists.at(i)->GetPlaylistName() << endl;
            }
            cout << "Pick a playlist index number: " << endl;
            int playlistIndex;
            cin >> playlistIndex;
            for(int i = 0; i < songs.size(); ++i){
                cout << i << ": " << songs.at(i)->GetSongName() << endl;
            }
            cout << "Pick a song index number: " << endl;
            int songIndex;
            cin >> songIndex;
            cin.ignore();
            playlists.at(playlistIndex)->AddSong(songs.at(songIndex));
        }

        else if (userMenuChoice == "listp") {
            //TODO: Implement this menu option
            for(int i = 0; i < playlists.size(); ++i){
                cout << i << ": " << playlists.at(i)->GetPlaylistName() << endl;
            }
        }
        else if (userMenuChoice == "play") {
            //TODO: Implement this menu option
            for(int i = 0; i < playlists.size(); ++i) {
                cout << i << ": " << playlists.at(i)->GetPlaylistName() << endl;
            }
            cout << "Pick a playlist index number: " << endl;
            int playlistIndex;
            cin >> playlistIndex;
            cin.ignore();
            cout << "Playing songs from playlist: " << playlists.at(playlistIndex)->GetPlaylistName();
            playlists.at(playlistIndex)->PrintFirstLines();
            for(int i=0; i < playlists.at(playlistIndex)->PlaylistSize();++i){
                playlists.at(playlistIndex)->GetSong(i)->AddTimesPlayed();
            }
        }
        else if (userMenuChoice == "remp") {
            //TODO: Implement this menu option
            for(int i = 0; i < playlists.size(); ++i) {
                cout << i << ": " << playlists.at(i)->GetPlaylistName() << endl;
            }
            cout << "Pick a playlist index number to remove: " << endl;
            int userRemove;
            cin >> userRemove;
            cin.ignore();
            delete playlists.at(userRemove);
            playlists.erase(playlists.begin() + userRemove);
        }
        else if (userMenuChoice == "remsp") {
            //TODO: Implement this menu option
            for(int i = 0; i < playlists.size(); ++i) {
                cout << i << ": " << playlists.at(i)->GetPlaylistName() << endl;
            }
            cout << "Pick a playlist index number: " << endl;
            int playlistIndex;
            cin >> playlistIndex;
            cin.ignore();
            for(int i = 0; i < playlists.at(playlistIndex)->PlaylistSize(); ++i){
                cout << i << ": " << playlists.at(playlistIndex)->GetSong(i)->GetSongName() << endl;
            }
            cout << "Pick a song index number to remove: " << endl;
            int songIndex;
            cin >> songIndex;
            cin.ignore();
            playlists.at(playlistIndex)->DeleteSong(songIndex);
        }
        else if (userMenuChoice == "remsl") {
            //TODO: Implement this menu option
            for(int i = 0; i < songs.size(); ++i){
                cout << i << ": " << songs.at(i)->GetSongName() << endl;
            }
            cout << "Pick a song index number to remove: " << endl;
            int songIndex;
            cin >> songIndex;
            cin.ignore();
            string songName;
            songName = songs.at(songIndex)->GetSongName();
            for(int i = 0;i < playlists.size(); ++i){
                for(int j = 0; j < playlists.at(i)->PlaylistSize();++j){
                    if(playlists.at(i)->GetSong(j)->GetSongName() == songName){
                        playlists.at(i)->DeleteSong(j);
                    }
                }
            }
            delete songs.at(songIndex);
            songs.erase(songs.begin() + songIndex);
        }

        else if (userMenuChoice == "options") {
            std::cout << "add      Adds a list of songs to the library" << std::endl
                      << "list     Lists all the songs in the library" << std::endl
                      << "addp     Adds a new playlist" << std::endl
                      << "addsp    Adds a song to a playlist" << std::endl
                      << "listp    Lists all the playlists" << std::endl
                      << "play     Plays a playlist" << std::endl
                      << "remp     Removes a playlist" << std::endl
                      << "remsp    Removes a song from a playlist" << std::endl
                      << "remsl    Removes a song from the library (and all playlists)" << std::endl
                      << "options  Prints this options menu" << std::endl
                      << "quit     Quits the program" << std::endl << std::endl;
        }
        else if (userMenuChoice == "quit") {
            std::cout << "Goodbye!" << std::endl;
            continueMenuLoop = false;
            for(int i =0; i < playlists.size(); ++i){
                delete playlists.at(i);
            }
            for(int i =0; i < songs.size(); ++i){
                delete songs.at(i);
            }
        }
        else {
            std::cout << "add      Adds a list of songs to the library" << std::endl
                      << "list     Lists all the songs in the library" << std::endl
                      << "addp     Adds a new playlist" << std::endl
                      << "addsp    Adds a song to a playlist" << std::endl
                      << "listp    Lists all the playlists" << std::endl
                      << "play     Plays a playlist" << std::endl
                      << "remp     Removes a playlist" << std::endl
                      << "remsp    Removes a song from a playlist" << std::endl
                      << "remsl    Removes a song from the library (and all playlists)" << std::endl
                      << "options  Prints this options menu" << std::endl
                      << "quit     Quits the program" << std::endl << std::endl;
        }
    }

    return 0;
}


std::string GetUserString(const std::string& prompt) {
    std::string userAnswer = "none";

    std::cout << prompt;
    std::getline(std::cin, userAnswer);
    std::cout << std::endl;
    return userAnswer;
}
int GetUserInt(const std::string& prompt) {
    int userAnswer = 0;

    std::cout << prompt;
    std::cin >> userAnswer;
    std::cin.ignore();
    std::cout << std::endl;
    return userAnswer;
}

