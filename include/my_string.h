#ifndef _MY_STRING_H_
#define _MY_STRING_H_

#include <stdio.h>
#include <string.h>

/* get_str: Takes stdin and stores it in an array */
void get_str(char output[], int size_limit) {
    char c;
    int i;

    for (i = 0; i < size_limit && (c = getchar()) != EOF; i++) {
       output[i] = c; 
    }

    output[i] = '\0';
}

/* Takes the first word (string separated by a single space, tab or newline character) from input and stores it in output array */
void get_word(char output[], int size_limit) {
    char c;
    int i;

    for (i = 0; i < size_limit && (c = getchar()) != EOF && c != ' ' && c!= '\n' && c!= '\t'; i++) {
       output[i] = c; 
    }

    output[i] = '\0';

    /* Progresses c to start of next word in case truncated due to size_limit */
    while (c != ' ' && c != '\n' && c != '\t' && c != EOF) {
        c = getchar();
    }
}

/* Takes the first line (string separated by a newline character) from input and stores it in output array */
void get_line(char output[], int size_limit) {
    char c;
    int i;

    for (i = 0; i < size_limit && (c = getchar()) != EOF && c!= '\n'; i++) {
       output[i] = c; 
    }

    output[i] = '\0';

    /* Progresses c to start of next line in case truncated due to size_limit */
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
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

/* reverse: reverse string s in place */
void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
#endif
