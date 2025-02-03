#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

#include "fct.h"

#define mu_assert(message, test) do {if(!test) return message;} while(0)

#define mu_run_test(test) do {char * message = test(); test_run++; if(message) return message;} while (0)

int test_run = 0;

static char * test_creerNote_freq() {
    struct Note * result = creerNote(100, 1);
    mu_assert("ERR : 11\n", result->freq == 100);
    return 0;
}

static char * test_creerNote_duree() {
    struct Note * result = creerNote(100, 1);
    mu_assert("ERR : 12\n", result->duree == 1);
    return 0;
}

static char * test_libNote() {
    struct Note ** result = malloc(NB_NOTE*sizeof(struct Note *));
    for (int i = 0; i < NB_NOTE; i++) {
        result[i] = creerNote(0, 0);
    }
    mu_assert("ERR : 21\n", libNote(result) == NULL);
    return 0;
}

static char * all_test() {
    mu_run_test(test_creerNote_freq);
    mu_run_test(test_creerNote_duree);
    mu_run_test(test_libNote);
    return 0;
}

int main() {
    char *result = all_test();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("All tests passed.\n");
    }
    printf("Tests run: %d \n", test_run);
    return result != 0;
}