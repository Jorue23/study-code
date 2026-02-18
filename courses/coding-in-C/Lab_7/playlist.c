#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song
{
    char *title;
    char *artist;

    struct Song *p_next;
} Song;

typedef struct Playlist
{
    Song *p_first;
} Playlist;

void init_playlist(Playlist *p_playlist) {
    p_playlist->p_first = NULL;
    return;
}

void addSong(Playlist *p_playlist, char *p_title, char *p_artist) {

    Song *newSong = malloc(sizeof *newSong);

    if(!newSong) {
        printf("Memory failed to allocate");
        return;
        //nothing to free because nothing has been allocated
    }

    newSong->title = malloc(strlen(p_title)+1);
    newSong->artist = malloc(strlen(p_artist)+1);

    if(!newSong->artist || !newSong->title) {
        printf("Failed to allocated memory!");
        free(newSong->artist);
        free(newSong->title);
        free(newSong);
        return;
        //if this fails, also free newSong struct because it has to have been initialized by now
    }
    strcpy(newSong->title, p_title);
    strcpy(newSong->artist, p_artist);

    newSong->p_next = NULL;

    if(!p_playlist->p_first) {
        p_playlist->p_first = newSong;
        return;
    }

    //cycle to the last song and append our song to the end of the list
    Song *p_lastSong = p_playlist->p_first;
    while(p_lastSong->p_next) {
        p_lastSong = p_lastSong->p_next;
    }
    p_lastSong->p_next = newSong;
}

void print_playlist(Playlist *p_playlist) {
    Song *p_currentSong = p_playlist->p_first;
    while (p_currentSong->p_next)
    {
        printf("%s - %s\n", p_currentSong->artist, p_currentSong->title);
        p_currentSong = p_currentSong->p_next;
    }
    printf("%s - %s\n", p_currentSong->artist, p_currentSong->title);
    
}

void delete_first(Playlist *p_playlist) {
    if(p_playlist->p_first == NULL) {
        return;
    }
    Song *currentFirst = p_playlist->p_first;
    p_playlist->p_first = currentFirst->p_next;
    free(currentFirst->artist);
    free(currentFirst->title);
    free(currentFirst);
    return;
}

void delete_playlist(Playlist *p_playlist) {
    while(p_playlist->p_first) {
        delete_first(p_playlist);
    }
    return;
}

int main() {

    Playlist newPlaylist;
    init_playlist(&newPlaylist);
    addSong(&newPlaylist, "Crawling", "Linkin Park");
    addSong(&newPlaylist, "Layla", "Eric Clapton");
    addSong(&newPlaylist, "Esperanto", "Max Herre");

    print_playlist(&newPlaylist);

    delete_first(&newPlaylist);

    print_playlist(&newPlaylist);



    return 0;
}
