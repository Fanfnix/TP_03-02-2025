#include <stdlib.h>
#include <stdio.h>
#include "fct.h"

#define mu_assert(message, test) do {if(!test) return message;} while(0)

#define mu_run_test(test) do {char * message = test(); test_run++; if(message) return message;} while (0)

int carre(a) {
    return a * a;
}

char * test_carre() {
    mu_assert("ERR : carre(3) != 9\n", carre(3) == 9);
    mu_assert("ERR : carre(-1) != 1\n", carre(-1) == 1);
    mu_assert("ERR : carre(-5) != 1\n", carre(-5) == 25);
}

int main() {

    return 0;
}