#include <stdio.h>

#define MAXSTRSIZE 1000

void expand(char input[], char output[]);

int main(void) {
    char input[MAXSTRSIZE], output[MAXSTRSIZE];

    /* get input str from stdin */
    fgets(input, MAXSTRSIZE, stdin);

    expand(input, output);
    
    puts(output);

    return 0;
}

void expand(char s1[], char s2[]) {
    int i = 0, j = 0, trigger = 0;
    char c;

    s2[j++] = s1[i++];
    
    while ((c = s1[i]) != '\0') {
        if (c == '-') {
            trigger = 1;
        }

        if (trigger && (s1[i + 1] != '\0') && (s1[i + 1] != '\n')) {
            c = s1[i - 1] + 1;
            while(c < s1[i + 1]) {
                s2[j++] = c++;
            }

            trigger = 0;
        } else {
            s2[j++] = c;
        }

        i++;
    }

    s2[j] = '\0';
}
