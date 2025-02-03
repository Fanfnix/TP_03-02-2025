#include <stdlib.h>
#include <stdio.h>
#include "fct.h"

#define mu_assert(message, test) do {if(!test) return message;} while(0)

#define mu_run_test(test) do {char * message = test(); test_run++; if(message) return message;} while (0)

int test_run = 0;

static const char * categorize_age(int age) {
    if (age < 0) {
        return "Invalid age";
    }
    else if (age < 13) {
        return "Child";
    }
    else if (age < 20) {
        return "Teenager";
    }
    else if (age < 65) {
        return "Adult";
    }
    else {
        return "Senior";
    }
}

static char * test_categorize_age_neg() {
    mu_assert("ERR : categorize(-1) != 'Invalid age'\n", categorize_age(-1) == "Invalid age");
    return 0;
}

static char * test_categorize_age_child() {
    mu_assert("ERR : categorize(10) != 'Child'\n", categorize_age(10) == "Child");
    return 0;
}

static char * test_categorize_age_teen() {
    mu_assert("ERR : categorize(18) != 'Teenager'\n", categorize_age(18) == "Teenager");
    return 0;
}

static char * test_categorize_age_adult() {
    mu_assert("ERR : categorize(40) != 'Adult'\n", categorize_age(40) == "Adult");
    return 0;
}

static char * test_categorize_age_senior() {
    mu_assert("ERR : categorize(90) != 'Senior'\n", categorize_age(90) == "Senior");
    return 0;
}

static char * all_test() {
    mu_run_test(test_categorize_age_neg);
    mu_run_test(test_categorize_age_child);
    mu_run_test(test_categorize_age_teen);
    mu_run_test(test_categorize_age_adult);
    mu_run_test(test_categorize_age_senior);
    return 0;
}

int main() {
    char * result = all_test();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("All_test passé\n");
    }
    printf("TEST_RUN = %d\n", test_run);

    return 0;
}