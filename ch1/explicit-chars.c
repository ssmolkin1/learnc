#include <stdio.h>

/* Replace escaped characters with the escape sequence  */

main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("%s", "\\t");
        }
        else if (c == '\b') {
            printf("%s", "\\b");
        }
        else if (c == '\\') {
            printf("%s", "\\\\");
        }
        else {
            putchar(c);
        }
    }
}
