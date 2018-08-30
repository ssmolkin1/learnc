#include <stdio.h>
#include <string.h>
#include "../include/my_string.h"

#define SIZE 1000

int strend(char *s, char *t);

int main(void) {
    char s1[SIZE], s2[SIZE];

    get_word(s1, SIZE);
    get_word(s2, SIZE);

    printf("%d\n", strend(s1, s2));
}

int strend(char *s, char *t) {
    char *p = &s[strlen(s) - strlen(t)];

    while (*p++ == *t++ && p < &s[strlen(s)]) {
        ;
    }

    if (*p) {
        return 0; /* did not end on '\0', so false */
    }

    return 1; /* otherwise, it did end on '\0', so true */
}
