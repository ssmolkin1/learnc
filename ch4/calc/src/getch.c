#include <stdio.h>
#include <string.h> /* for ungets() */
#include "../headers/calc.h"

#define BUFSIZE 100
#define TRUE 1
#define FALSE 0

static int buf[BUFSIZE]; /* buffer for ungetch */
static int bufp = 0; /* next free position in buf */
static int out_of_space = FALSE; /* flag for ungetch() to communicate to ungets() that no space is left in buf */
static int end_reached = FALSE;

/* get a (possible pushed back) character */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        out_of_space = TRUE;
        printf("error: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

/* ungets: unget a string */
void ungets(char s[]) {
    size_t i = strlen(s);

    while (i && !out_of_space) {
        ungetch(s[--i]);
    }
}
