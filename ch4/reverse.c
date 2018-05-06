/* Solution to 4.13: reverse a string in place using a recursive function. This simple solution uses a static internal variable to avoid the need to call reverse() with additional arguments or to write helper functions (as one might do in other languages, like Scheme), because you can't hide them in other functions in C.  */

#include <stdio.h>
#include <string.h>

#define MAXLEN 100
void reverse(char []);

int main(void)
{
    char input[MAXLEN];
    
    while (fgets(input, MAXLEN, stdin) != NULL) {
        if (input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0'; /* cut off terminating \n */
        }
    
        printf("\"%s\" in reverse is ", input);

        reverse(input);

        printf("\"%s\"\n", input);
    }

    return 0;
}

void reverse(char s[])
{
    size_t len = strlen(s);
    static int offset = 0;
    char tmp;

    if (offset < (int) len / 2) {
        tmp = s[offset];
        s[offset] = s[len - (offset + 1)];
        s[len - (++offset)] = tmp;
        reverse(s);
    } else {
        offset = 0; /* After last recursive call, reset for calls on new strings */
    }
    
}
