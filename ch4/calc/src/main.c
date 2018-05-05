#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../headers/calc.h"

#define MAXOP 100

/* register for storing which variable is being worked on */
char reg;

/* user defined variables */
double x, y, z;

/* variable for last printed item */
double r;

/* variable handling functions  */
void store(char var);
void call(char var);
void show(char var);

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
            r = pop();
            printf("\t%.8g\n", r);
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
        case SHO:
            show(reg);
            break;
        case CAL:
            call(reg);
            break;
        case STR:
            store(reg);
            break;
        case 'x':
        case 'y':
        case 'z':
        case 'r':
            reg = type;
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }

    return 0;
}

void store(char token) {
    switch (token) {
    case 'x':
        x = pop();
        break;
    case 'y':
        y = pop();
        break;
    case 'z':
        z = pop();
        break;
    default:
        printf("error: %c is not a variable", token);
    }
}

void call(char token) {
    switch (token) {
    case 'x':
        push(x);
        break;
    case 'y':
        push(y);
        break;
    case 'z':
        push(z);
        break;
    case 'r':
        push(r);
        break;
    default:
        printf("error: %c is not a variable", token);
    }
}

void show(char token) {
    switch (token) {
    case 'x':
        printf("\t%.8g\n"  , x);
        break;
    case 'y':
        printf("\t%.8g\n"  , y);
        break;
    case 'z':
        printf("\t%.8g\n"  , z);
        break;
    case 'r':
        printf("\t%.8g\n"  , r);
        break;
    default:
        printf("error: %c is not a variable", token);
    }
}
