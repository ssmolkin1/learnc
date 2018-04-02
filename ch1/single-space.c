#include <stdio.h>

#define IN 0 /* Inside a word */
#define OUT 1 /* Whitespace */

/* Replace multiple whitespaces with single space */
main()
{
    int c, state;

    state = IN;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            if (state == IN) {
                putchar(' ');
                state = OUT;
            }
        }
        else {
            if (state == OUT) {
                state = IN;
            }
            putchar(c);
        }
    }
}
