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
        //if this fails also free newSong struct because it has to have been initialized by now
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

void delete_element(Song *p_song, Song *p_lastSong) {
    p_lastSong->p_next = p_song->p_next;
    free(p_song->artist);
    free(p_song->title);
    free(p_song);
}

void delete_song_by_title(Playlist *p_playlist, char *title) {

    if(p_playlist->p_first == NULL) {
        printf("Playlist is empty\n");
        return;
    }

    if(strcmp(p_playlist->p_first->title, title) == 0) {
        Song *tmp = p_playlist->p_first;
        p_playlist->p_first = p_playlist->p_first->p_next;
        free(tmp->artist);
        free(tmp->title);
        free(tmp);
        return;
    }

    Song *p_lastSong = p_playlist->p_first;
    while(p_lastSong->p_next != NULL) {
        if(strcmp(p_lastSong->p_next->title, title) == 0) {
            delete_element(p_lastSong->p_next, p_lastSong);
            return;
        }
        p_lastSong = p_lastSong->p_next;
    }

    printf("Failed to locate song with title: %s\n", title);
}

int count_songs(Playlist *p_playlist) {
    if(!p_playlist->p_first) {
        return 0;
    }
    int i = 1;
    Song *currentSong = p_playlist->p_first;
    while(currentSong->p_next != NULL) {
        i++;
        currentSong = currentSong->p_next;
    }
    return i;
}

void add_song_at_position(Playlist *p_playlist, char *p_title, char *p_artist, int position) {

    position -= 1;
    int total = count_songs(p_playlist);
    //print position+1 because we reduced to 0 based system at first
    if (position < 0) {
        printf("%s%i%s\n", "Position ", position+1, " is zero or less then zero. Please start at one!");
        return;
    }
    if (position > total) {
        printf("%s%i%s\n", "Position ", position+1, " is out of bounds!");
        return;
    }

    // Reuse addSong if inserting at the end
    if (position == total) {
        addSong(p_playlist, p_title, p_artist);
        return;
    }

    Song *newSong = malloc(sizeof *newSong);
    if (!newSong) { 
        printf("Memory allocation failed\n");
        return; 
    }

    newSong->title = malloc(strlen(p_title) + 1);
    newSong->artist = malloc(strlen(p_artist) + 1);
    if (!newSong->title || !newSong->artist) {
        printf("Memory allocation failed\n");
        free(newSong->title);
        free(newSong->artist);
        free(newSong);
        return;
    }
    strcpy(newSong->title, p_title);
    strcpy(newSong->artist, p_artist);

    if (position == 0) {
        newSong->p_next = p_playlist->p_first;
        p_playlist->p_first = newSong;
        return;
    }

    // Walk to the node just before the target position -2 because relative count starts with 1, but list starts with 0
    Song *current = p_playlist->p_first;
    for (int i = 0; i < position - 1; i++) {
        current = current->p_next;
    }


    newSong->p_next = current->p_next;
    current->p_next = newSong;
}

int main() {

    Playlist newPlaylist;
    init_playlist(&newPlaylist);
    addSong(&newPlaylist, "Crawling", "Linkin Park");
    addSong(&newPlaylist, "Layla", "Eric Clapton");
    addSong(&newPlaylist, "Esperanto", "Max Herre");
    addSong(&newPlaylist, "Burn it Down", "Linkin Park");
    addSong(&newPlaylist, "Thunderstruck", "ACDC");
    addSong(&newPlaylist, "Zombified", "Falling in Reverse");

    print_playlist(&newPlaylist);

    printf("--------------------------------------\n");

    delete_first(&newPlaylist);

    print_playlist(&newPlaylist);

    printf("--------------------------------------\n");

    delete_song_by_title(&newPlaylist, "Esperanto");

    print_playlist(&newPlaylist);

    printf("--------------------------------------\n");

    printf("%i\n", count_songs(&newPlaylist));

    printf("--------------------------------------\n");

    add_song_at_position(&newPlaylist, "Deutschland", "Rammstein", 3);

    printf("--------------------------------------\n");

    print_playlist(&newPlaylist);


    return 0;
}
