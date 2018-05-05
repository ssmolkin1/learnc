#include <stdio.h>

static char bufchar = EOF;

/* get a (possible pushed back) character */
int getch(void) {
    if (bufchar != EOF) {
        char c = bufchar;
        bufchar = EOF;
        return c;
    }

    return getchar();
}

/* push character back on input */
void ungetch(int c) {
    bufchar = c;
}
