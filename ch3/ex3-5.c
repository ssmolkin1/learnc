#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "../my_string.h"

#define MAXSTRSIZE  25

void itoa(int number, char string[]);
void itob(int number, char string[], int base);

int main(void) {
    int largest_negative = INT_MIN, easy_num = 23, test_case = -1;
    char string[MAXSTRSIZE];

    itob(test_case, string, 16);
    
    printf("%s\n", string);
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
