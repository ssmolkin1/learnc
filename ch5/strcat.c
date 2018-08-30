#include <stdio.h>
#include <string.h>
#include "../include/my_string.h"

#define SIZE 10

char *stringcat(char *s, char *t);

int main(void) {
    char s1[SIZE], s2[SIZE];
    char *p;

    get_word(s1, SIZE);

    p = s1 + (sizeof s1) * SIZE;
    *p = 'x'; 

    get_word(s2, SIZE);

    printf("%c\n", *p);
    printf("%s\n", stringcat(s1, s2));
    printf("%c\n", *p);
}

char *stringcat(char *s, char *t) {
    char *p = &s[strlen(s)];

    while ((*p++ = *t++)) {
        ;
    }

    return s;
}

