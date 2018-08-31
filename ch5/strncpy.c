#include <stdio.h>

#define LEN 20

char *my_strncpy(char *s, char *ct, int n);
char *my_strncat(char *s, char *ct, int n);
int my_strncmp(char *s, char *ct, int n);

int main (void) {
    char str1[LEN] = "Hello, world!";
    char str2[LEN] = "Hello, world!";
    int n = 5;

    printf("%d\n", my_strncmp(str1, str2, n));

    return 0;
}

char *my_strncpy(char *s, char *ct, int n) {
    char *start = s;

    while ( *s  && (n-- > 0) && ( *s++ = *ct++ ));
    
    while ( *s  && (n-- > 0))
        *s++ = '\0';

    return start;
}

char *my_strncat(char *s, char *ct, int n) {
    char *start = s;

    while (*(++s));
    
    while ((n-- > 0) && (*s++ = *ct++));

    if (!n)
        *s = '\0';

    return start;
}

int my_strncmp(char *s, char *ct, int n) {
    int r;

    for (int i = 0; (i < n) && s[i]; i++) {
        if ((r = s[i] - ct[i]) != 0) {
            return r;
        }
    }

    return 0;
}
