#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int strindex(char source[], char searchfor[]);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main(void) {
    char line[MAXLINE];
    int found = 0, index;

    while (fgets(line, MAXLINE, stdin)) {
        if ((index = strrindex(line, pattern)) >= 0) {
            printf("%s (%d)\n", line, index);
            found++;
        } 
    }
    
    return found;
}

/* strindex: return index of rightmost occurence of t in s, -1 if none */
int strrindex(char s[], char t[]) {
    int i, j, k, rindex = -1;

    for (i = 0; strlen(s) - i - strlen(t) > 0; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
            ;
        }
        if (k > 0 && t[k] == '\0') {
            rindex = i;
        }
    }

    return rindex;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[]) {
    int i, j, k;

    for (i = 0; strlen(s) - i - strlen(t) > 0; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
            ;
        }
        if (k > 0 && t[k] == '\0') {
            return i;
        }
    }

    return -1;
}
