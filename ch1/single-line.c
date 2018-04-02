#include <stdio.h>

#define IN 0 /* Inside a word */
#define OUT 1 /* Whitespace */

/* Replace multiple whitespaces with single space */
int main()
{
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {
                putchar('\n');
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
