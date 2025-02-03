#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

#include "fct.h"

#define mu_assert(message, test) do {if(!test) return message;} while(0)

#define mu_run_test(test) do {char * message = test(); test_run++; if(message) return message;} while (0)

int test_run = 0;

int main() {
    float frequences[NB_NOTE] = {329.63f, 349.23f, 369.99f, 392.00f, 415.30f, 440.00f, 466.16f};
    
    struct Note ** piano = malloc(NB_NOTE*sizeof(struct Note *));
    for (int i = 0; i < NB_NOTE; i++) {
        piano[i] = creerNote(frequences[i], 1);
        printf("F = %f\n", piano[i]->freq);
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