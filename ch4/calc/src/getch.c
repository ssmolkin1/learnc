#include <stdio.h>
#include <string.h> /* for ungets() */
#include "../headers/calc.h"

int strp = 0; /* next read position in input string */

/* get a (possible pushed back) character */
int getch(char input[]) {
    return input[strp++];
}

/* push character back on input */
void ungetch(void) {
    strp--;
}

/* ungets: unget a string */
void ungets(char s[]) {
    size_t len = strlen(s);

    strp -= len;
}
