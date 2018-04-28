#include <stdio.h>
#include <limits.h>
#include "../my_string.h"

#define MAXSTRSIZE  33

void itoa2(int number, char string[], int width);
void itoa(int number, char string[]);
void itob(int number, char string[], int base);

int main(void) {
    int largest_negative = INT_MIN, easy_num = 23, test_case = -1;
    char string[MAXSTRSIZE];

    itoa2(INT_MIN, string, 14);
    
    printf("%s\n", string);
}

void itoa2(int n, char s[], int w) {
    int i, is_negative = ((n < 0) ? 1: 0);
    unsigned int num;

    if (is_negative) {
        num = -n;
    } else {
        num = n;
    }

    i = 0;
    do {
        s[i++] = num % 10 + '0';
    } while ((num /= 10) > 0);

    while (i < w - is_negative) {
        s[i++] = ' ';
    }

    if (is_negative) {
        s[i++] = '-';
    }

    s[i] = '\0';

    reverse(s);
}

void itoa(int n, char s[]) {
    int i, sign;
    unsigned int num;

    if ((sign = n) < 0) {
        num = -n;
    } else {
        num = n;
    }

    i = 0;
    do {
        s[i++] = num % 10 + '0';
    } while ((num /= 10) > 0);

    if (sign < 0) {
        s[i++] = '-';
    }

    s[i] = '\0';

    reverse(s);
}

void itob(int n, char s[], int b) {
    if (b == 10) {
        itoa(n, s);
    } else {
        int i, mod, offset;
        unsigned num = ((n >= 0) ? n : (UINT_MAX + n + 1)); 
    
        i = 0;
        do {
            mod = num % b;
            offset = ((mod > 9) ? 7 : 0);
            s[i++] = mod + offset + '0';
        } while ((num /= b) > 0);

        s[i] = '\0';

        reverse(s);
    }
}
