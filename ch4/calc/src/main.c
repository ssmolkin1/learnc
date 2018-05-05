#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../headers/calc.h"

#define MAXOP 100

/* reverse Polish calculator */
int main(void) {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case SIN:
            push(sin(pop()));
            break;
        case COS:
            push(cos(pop()));
            break;
        case TAN:
            push(tan(pop()));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0) {
                push(pop() / op2);
            } else {
                printf("error: zero divisor");
            }
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0) {
                push((int) pop() % (int) op2);
            } else {
                printf("error: zero divisor");
            }
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        case 'p':
            print();
            break;
        case 'd':
            dup();
            break;
        case 's':
            swap();
            break;
        case 'c':
            clearall();
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }

    return 0;
}
