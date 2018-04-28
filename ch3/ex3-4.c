#include <stdio.h>
#include <math.h>
#include "../my_string.h"

#define MAXSTRSIZE  20

void itoa(int number, char string[]);

int main(void) {
    int largest_negative = -pow(2, 31), easy_num = 23423;
    char string[MAXSTRSIZE];

    itoa(largest_negative, string);
    
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
