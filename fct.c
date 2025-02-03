#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

#include "fct.h"

struct Note * creerNote(float freq, int duree) {
    struct Note * note = malloc(sizeof(struct Note));
    note->freq = freq;
    note->duree = duree;
    return note;
}

int libNote(struct Note ** note) {
    for (int i = 0; i < NB_NOTE; i++) {
        free(note[i]);
        note[i] = NULL;
    }
    free(note);
    note = NULL;
    if (note != NULL) {
        return 0;
    }
    return 1;
}

void simulerPiano(struct Note ** piano) {
    int pressed;
    while ((pressed = getch()) != 'q') {
        switch (pressed) {
            case 'c': printw("DO : %f\n", piano[0]->freq); break;
            case 'd': printw("RE : %f\n", piano[2]->freq); break;
            case 'e': printw("MI : %f\n", piano[4]->freq); break;
            case 'f': printw("FA : %f\n", piano[5]->freq); break;
            case 'g': printw("SOL : %f\n", piano[7]->freq); break;
            case 'a': printw("LA : %f\n", piano[9]->freq); break;
            case 'b': printw("SI : %f\n", piano[11]->freq); break;
            default: pressed = 'q'; break;
        }
    }
}