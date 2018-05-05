#include <stdio.h>
#include "../headers/calc.h"

#define BUFSIZE 100

static char buf[BUFSIZE]; /* buffer for ungetch */
static int bufp = 0; /* next free position in buf */

/* get a (possible pushed back) character */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("error: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}
