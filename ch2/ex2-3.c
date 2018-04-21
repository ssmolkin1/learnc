#include <stdio.h> 
#include <ctype.h>

#define MAXLEN    10


int htoi(char s[]);

int main(void) {
    char c, hex_string[MAXLEN];
    int i;

    for (i = 0; i < MAXLEN - 1 && (c = getchar()) != EOF; i++) {
       hex_string[i] = c; 
    }

    hex_string[i] = '\0';

    printf("%d\n", htoi(hex_string));
}

int htoi(char s[]) {
    int start = 0, result = 0;

    /* Test if starts with '0x' or '0X' */
    if (tolower(s[1]) == 'x') {
        start = 2;
    }
    
    for (int i = start; isdigit(s[i]) || (tolower(s[i]) >= 'a' && tolower(s[i]) <= 'f'); i++) {
        char c = s[i];
        int n;
        
        if (isdigit(c)) {
            n = c - '0';
        } else {
            n = tolower(c) - 'a' + 10;
        }

        result = result * 16 + n;
    }

    return result;
}

