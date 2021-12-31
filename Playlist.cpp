//
// Created by jense on 12/2/2021.
//

#include "Playlist.h"

Playlist::Playlist() {
    playlistName = "Unknown";
}

Playlist::Playlist(string userPlaylistName) {
    playlistName = userPlaylistName;
}

string Playlist::GetPlaylistName() {
    return playlistName;
}

void Playlist::AddSong(Song* userSong) {
    playlistSongs.push_back(userSong);
}

void Playlist::PrintFirstLines() {
    for(int i = 0; i < playlistSongs.size();++i){
        cout << playlistSongs.at(i)->GetFirstLine() << endl;
    }
}
Song *Playlist::GetSong(int index){
    return playlistSongs.at(index);
}

int Playlist::PlaylistSize() {
    return playlistSongs.size();
}

void Playlist::DeleteSong(int index) {
    playlistSongs.erase(playlistSongs.begin()+ index);
}
