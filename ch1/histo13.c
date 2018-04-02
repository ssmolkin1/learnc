#include <stdio.h>

#define IN 0 /* Inside a word */
#define OUT 1 /* Whitespace */

int main() {
    int wordlenghts[11], i, c, state, nletters, j;

    nletters = 0;
    for (i = 0; i < 11; ++i) {
        wordlenghts[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {
                if (nletters < 11) {
                    ++wordlenghts[nletters - 1];
                } else {
                    ++wordlenghts[10];
                }
                nletters = 0;
                state = OUT;
            }
        }
        else {
            if (state == OUT) {
                state = IN;
            }
            ++nletters;
        }
    }

    printf("Word Lenghts:\n");

    for (i = 0; i < 10; ++i) {
        printf("%d:\t", i + 1);

        for (j =0; j < wordlenghts[i]; ++j) {
            printf("|");
        }

        printf("\n");
    }

    printf(">10:\t");

    for (i =0; i < wordlenghts[10]; ++i) {
        printf("|");
    }

    printf("\n");
}
