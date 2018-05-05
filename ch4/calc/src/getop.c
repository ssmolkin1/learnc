#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../headers/calc.h"

/* getop: get next operator or numeric operand */
int getop(char input[], char s[]) {
    int i, c;

    while ((s[0] = c = getch(input)) == ' ' || c == '\t') {
        ;
    }

    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c!= '+' && c != '-') {
        int j = 1;
        char d, fun[4];

        fun[0] = c;

        while ((fun[j++] = d = getch(input)) >= 'a' && d <= 'z' && j < 3) {
            ;
        }

        if (j == 3) {
            fun[j] = '\0';

            if (strcmp(fun, "sin") == 0) {
                return SIN;
            }
            
            if (strcmp(fun, "cos") == 0) {
                return COS;
            }
            
            if (strcmp(fun, "tan") == 0) {
                return TAN;
            }

            if (strcmp(fun, "str") == 0) {
                return STR;
            }

            if (strcmp(fun, "cal") == 0) {
                return CAL;
            }

            if (strcmp(fun, "sho") == 0) {
                return SHO;
            }

        } else {
            while (j > 1) {
                if (fun[--j] != EOF) {
                    ungetch();
                };
            }

            return c; /* not a number or function */
        }
    }

    i = 0;

    if (c == '+' || c == '-' || isdigit(c)) { /* collect the integer part */
        while (isdigit(s[++i] = c = getch(input))) {
            ;
        }
    }

    if (c == '.') { /* collect the fraction part */
        while (isdigit(s[++i] = c = getch(input))) {
            ;
        }
    }

    s[i] = '\0';

    if (c != EOF) {
        ungetch();
    }

    if (s[i - 1] == '+'|| s[i - 1] == '-') {
        return s[i - 1];
    }

    return NUMBER;
}
