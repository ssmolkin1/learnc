#include <stdio.h>
#include "getinput.h"

#define MAXLEN 20

void squeeze_alt(char s1[], char s2[]);
int in_string(char c, char s[]);

int main(void) {
    char string1[MAXLEN + 1], string2[MAXLEN + 1];

    get_word(string1, MAXLEN + 1);
    get_word(string2, MAXLEN + 1);
    
    squeeze_alt(string1, string2);

    printf("%s\n", string1);
}

/* Alternative squeeze() which deletes all chars in s1 which are in s2 */
void squeeze_alt(char s1[], char s2[]) {
    int i, j;

    for (i = j = 0; s1[i] != '\0'; i++) {
        if (!in_string(s1[i], s2)) {
            s1[j++] = s1[i];
        }
    }

    s1[j] = '\0';
}

/* in_string: returns 1 if char c is in string s, otherwise 0 */
int in_string(char c, char s[]) {
    int i = 0, result = 0;

    while (s[i] != '\0' && result == 0) {
        if (s[i++] == c) {
            result = 1; 
        }
    }

    return result;
}
