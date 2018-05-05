#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../headers/calc.h"

/* getop: get next operator or numeric operand */
int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t') {
        ;
    }

    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c!= '+' && c != '-') {
        int j = 1;
        char d, fun[4];

        fun[0] = c;

        while ((fun[j++] = d = getch()) >= 'a' && d <= 'z' && j < 4) {
            ;
        }

        if (j == 4) {
            fun[j] = '\0';

            if (strcmp(fun, "sin")) {
                printf("got here");
                return SIN;
            }
            
            if (strcmp(fun, "cos")) {
                return COS;
            }
            
            if (strcmp(fun, "tan")) {
                return TAN;
            }
        } else {
            while (j > 1) {
                ungetch(fun[--j]);
            }

            return c; /* not a number or function */
        }
    }

    i = 0;

    if (c == '+' || c == '-' || isdigit(c)) { /* collect the integer part */
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }

    if (c == '.') { /* collect the fraction part */
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }

    s[i] = '\0';

    if (c != EOF) {
        ungetch(c);
    }

    if (s[i - 1] == '+'|| s[i - 1] == '-') {
        return s[i - 1];
    }

    return NUMBER;
}
