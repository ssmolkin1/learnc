#include <stdio.h>

#define MAXLINE 1000    /*Max input line size*/
#define MINLINE 80    /* Min line length for printing */

int mygetline(char line[], int maxline);

/* print lines >80 chars */
int main() {
    int len;    /* current line length */
    char line[MAXLINE];    /* current input line */

    while ((len = mygetline(line, MAXLINE)) > 0) {
        if (len > MINLINE) {
            printf("%s", line);
        }
    }

    return 0;
}

/* mygetline: read a line into s, return length */
int mygetline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    /* handle lines that terminate because they are oversized */
    if (i == lim -1) {
        s[i - 1] = '\n';
        s[i] = '\0';
    } else if (c == '\n') {    /* handle lines that terminate in newline */
        s[i] = c;
        ++i;
        s[i] = '\0';
    } else {    /* handle lines that terminate because they hit EOF */
        s[i] = '\n';
        s[i + 1] = '\0';
    }

    return i;
}
