#include <stdio.h>
#include "../my_string.h"

#define MAXINSTR 30
#define MAXOUTSTR 60
#define REV 0

void escape(char s[], char t[]);
void escape_rev(char s[], char t[]);

int main(void) {
    char input[MAXINSTR + 1], output[MAXOUTSTR + 1];

    /* get stdin as string and store in input[] */
    get_str(input, MAXINSTR);

    if (REV) {
        escape_rev(input, output);
    } else {
        escape(input, output);
    }

    printf("%s\n", output);

    return 0;
}


void escape(char s[], char t[]) {
    int i, j;
    char c;

    for (i = 0, j = 0; (c = s[i]) != '\0'; i++, j++) {
        switch (c) {
        case '\n':
            t[j++] = '\\';
            t[j] = 'n';
            break;
        case '\a':
            t[j++] = '\\';
            t[j] = 'a';
            break;
        case '\b':
            t[j++] = '\\';
            t[j] = 'b';
            break;
        case '\f':
            t[j++] = '\\';
            t[j] = 'f';
            break;
        case '\r':
            t[j++] = '\\';
            t[j] = 'r';
            break;
        case '\t':
            t[j++] = '\\';
            t[j] = 't';
            break;
        case '\v':
            t[j++] = '\\';
            t[j] = 'v';
            break;
        case '\\':
            t[j++] = '\\';
            t[j] = '\\';
            break;
        case '\'':
            t[j++] = '\\';
            t[j] = '\'';
            break;
        case '\"':
            t[j++] = '\\';
            t[j] = '\"';
            break;
        case '\?':
            t[j++] = '\\';
            t[j] = '\?';
            break;
        case '\e':
            t[j++] = '\\';
            t[j] = 'e';
            break;
        default:
            t[j] = c;
            break;
        }
    }

    t[j] = '\0';
}

void escape_rev(char s[], char t[]) {
    int i, j;
    char c;

    for (i = 0, j = 0; (c = s[i]) != '\0'; i++, j++) {
        if (c == '\\') {
            switch (c = s[++i]) {
            case 'n':
                t[j] = '\n';
                break;
            case 'a':
                t[j] = '\a';
                break;
            case 'b':
                t[j] = '\b';
                break;
            case 'f':
                t[j] = '\f';
                break;
            case 'r':
                t[j] = '\r';
                break;
            case 't':
                t[j] = '\t';
                break;
            case 'v':
                t[j] = '\v';
                break;
            case '\\':
            case '\'':
            case '\"':
            case '\?':
                t[j] = c;
                break;
            case '\e':
                t[j] = '\e';
                break;
            case '\0':
                t[j] = '\\';
                i--;
                break;
            default:
                t[j++] = '\\';
                t[j] = c;
                break;
            }
        } else {
            t[j] = s[i];
        }
    }

    t[j] = '\0';
}
