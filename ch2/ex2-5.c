#include <stdio.h>
#include "my_string.h"

#define MAXLEN 20

int any(char s1[], char s2[]);

int main(void) {
    char string1[MAXLEN + 1], string2[MAXLEN + 1];

    get_word(string1, MAXLEN + 1);
    get_word(string2, MAXLEN + 1);
    
    printf("%d\n", any(string1, string2));
}

/* Returns location of first char in s1 also in s2, or else -1 */
int any(char s1[], char s2[]) {
    int result = -1;

    for (int i = 0; s1[i] != '\0' && result == -1; i++) {
       if (in_string(s1[i], s2)) {
           result = i; 
       } 
    }

    return result;
}

