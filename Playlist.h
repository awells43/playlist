//
// Created by jense on 12/2/2021.
//

#ifndef MAINLAB8_PLAYLIST_H
#define MAINLAB8_PLAYLIST_H
#include "Song.h"

class Playlist {
private:
    string playlistName;
    vector<Song*>playlistSongs;
public:
    Playlist();
    Playlist(string userPlaylistName);
    string GetPlaylistName();
    void AddSong(Song* userSong);
    void PrintFirstLines();
    Song* GetSong(int index);
    int PlaylistSize();
    void DeleteSong(int index);


};

#endif //MAINLAB8_PLAYLIST_H
