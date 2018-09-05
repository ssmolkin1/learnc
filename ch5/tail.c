#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000   // max #lines to be sorted
#define MAXLEN 1000   // max length of any input line

char *lineptr[MAXLINES];  // pointers to text lines
char buffer[MAXLEN * MAXLINES];  // pointers to text lines
char *pbfr = buffer;

int main(int argc, char *argv[]) {
    int i, n = 10;
    FILE *file = NULL;

    if (argc < 1) {
        printf("%s\n", "Usage: tail -n <file>, where n is number of lines to print.");
        return 1;
    }

    if (argv[1][0] == '-') {
        n = atoi(++argv[1]);
        file = fopen(argv[2], "r");
    } else {
        file = fopen(argv[1], "r");
    }
    
    if (n <= 0) {
        printf("%s\n", "Invalvid number of lines to print.");
        return 1;
    }

    if (file == NULL) {
        printf("%s\n", "No file to read.");
        return 1;
    }

    for (i = 0; ; i++) {
        if (fgets(pbfr, MAXLEN, file) != NULL) {
            lineptr[i] = pbfr;
            pbfr += (strlen(pbfr) + 1);
        }
        else
            break;
    }

    while(n-- > 0 && i > 0)
        printf("%s", lineptr[--i]);

    return 0;
}
