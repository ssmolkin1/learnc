#include <stdio.h>

int main() {
    int i, lim = 1000, c;
    char s[lim];
    
    for (i = 0; i < lim - 1; i++) {
       if ((c = getchar()) != '\n') {
           if (c != EOF) {
               s[i] = c;
           }
       } 
    }
}
