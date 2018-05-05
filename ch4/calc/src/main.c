#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../headers/calc.h"

#define MAXOP 100

/* reverse Polish calculator */
int main(void) {
    int type;
    double op2, str;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case SIN:
            op2 = pop();
            str = sin(op2);
            push(str);
            break;
        case COS:
            op2 = pop();
            cos(op2);
            push(op2);
            break;
        case TAN:
            op2 = pop();
            tan(op2);
            push(op2);
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
