#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

#include "fct.h"

int main() {
    float frequences[NB_NOTE] =  {261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392.00, 415.30, 440.00, 466.16, 493.88};
    
    struct Note ** piano = malloc(NB_NOTE*sizeof(struct Note *));
    for (int i = 0; i < NB_NOTE; i++) {
        piano[i] = creerNote(frequences[i], 1);
    }

    initscr();
    noecho();

    simulerPiano(piano);

    endwin();

    if(!libNote(piano)) {
        printf("ERROR : libNote failed\n");
    }

    return 0;
}