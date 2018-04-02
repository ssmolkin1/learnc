#include <stdio.h>

#define IN 0 /* Inside a word */
#define OUT 1 /* Whitespace */

int main() {
    int characters[128], i, c, j;

    for (i = 0; i < 128; ++i) {
        characters[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        ++characters[c];
    }

    printf("Character Frequencies:\n");

    for (i = 0; i < 128; ++i) {
        printf("%c:\t", i);

        for (j =0; j < characters[i]; ++j) {
            printf("|");
        }

        printf("\n");
    }
}
