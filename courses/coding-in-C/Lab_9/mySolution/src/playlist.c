/*
 * File: playlist.c
 * Description: Includes the code/logic for functions of playlist.h
 */
#include "../include/playlist.h"

/**
 * @brief Initialize a new playlist
 *
 * @param p_playlist pointer the playlist
 */
void init_playlist(Playlist *p_playlist)
{
    p_playlist->p_head = NULL;
    p_playlist->size = 0;
}

/**
 * @brief add a new song to the end of the playlist
 *
 * @param playlist pointer to playlist
 * @param title    title of the new song
 * @param artist   artist of the new song
 */
void add_song(Playlist *playlist, const char *title, const char *artist)
{
    if (playlist->size >= MAX_SONGS)
    {
        printf("Warning: Playlist reached maximum size (%d songs). New song discarded.\n", MAX_SONGS);
        return;
    }

    Song *newSong = malloc(sizeof(*newSong));
    if (!newSong)
        return;

    newSong->title = malloc(strlen(title) + 1);
    newSong->artist = malloc(strlen(artist) + 1);

    if (!newSong->title || !newSong->artist)
    {
        free(newSong->title);
        free(newSong->artist);
        free(newSong);
        return;
    }

    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->p_nextSong = NULL;

    if (!playlist->p_head)
    {
        playlist->p_head = newSong;
    }
    else
    {
        Song *last = playlist->p_head;
        while (last->p_nextSong)
            last = last->p_nextSong;
        last->p_nextSong = newSong;
    }

    playlist->size++;
}

/**
 * @brief print out all songs of the playlist
 *
 * @param playlist pointer to playlist
 */
void print_playlist(const Playlist *playlist)
{
    printf("Playlist contains %d song(s):\n", playlist->size);
    Song *current = playlist->p_head;
    while (current)
    {
        printf("Title: %s, Artist: %s\n", current->title, current->artist);
        current = current->p_nextSong;
    }
}

/**
 * @brief delete the first song of the playlist
 *
 * @param playlist pointer to playlist
 */
void delete_firstSong(Playlist *playlist)
{
    if (!playlist->p_head)
        return;

    Song *tmp = playlist->p_head;
    playlist->p_head = tmp->p_nextSong;

    free(tmp->title);
    free(tmp->artist);
    free(tmp);

    playlist->size--;
}

/**
 * @brief delete playlist and free up memory
 *
 * @param playlist pointer to playlist
 */
void delete_playlist(Playlist *playlist)
{
    while (playlist->p_head)
        delete_firstSong(playlist);
}

Song* find_song_by_title(Playlist *p_playlist, const char *p_title)
{
    Song *current_song = malloc(sizeof(p_playlist->p_head));
    current_song = p_playlist->p_head;
    while (current_song != NULL)
    {
        if(strcmp(current_song->title, *p_title)) {
            return current_song;
        }
        current_song = current_song->p_nextSong;
    }
    return NULL;
}

int count_songs_recursive(const Song *p_current) {
    if(p_current == NULL) {
        return NULL;
    }
    return 1 + count_songs_recursive(p_current->p_nextSong);
}

void sort_playlist_by_title(Playlist *playlist) {
    Song *pivot = playlist->p_head;
    Song *pre = playlist->p_head;
    Song *curr = playlist->p_head;

    while(curr != getTail(playlist->p_head)->p_nextSong) {
        if(strcmp(curr->title, pivot->title) )
    }
}

Song *getTail(Song *p_cur) {
    while(p_cur != NULL && p_cur->p_nextSong != NULL) {
        p_cur = p_cur->p_nextSong;
    }
    return p_cur;
}