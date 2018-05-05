#include <stdio.h>
#include "../headers/calc.h"

#define MAXVAL 100 /* Maximum depth of val stack */
#define EEMPTY "error: stack empty\n" /* stack empty error message */

static int sp = 0; /* next free stack position */
static double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, cannot push %g\n", f);
    }
}

/* pop: pop and return top value from stack */
double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } 

    printf(EEMPTY);
    return 0.0;
}

/* print: print the top element of the stack */
void print(void) {
    if (sp > 0) {
        printf("\t%.8g\n", val[sp - 1]);
    } else {
        printf(EEMPTY);
    }
}

/* dup: duplicate top stack element */
void dup(void) {
    if (sp > 0) {
        push(val[sp - 1]);
    } else {
        printf(EEMPTY);
    }
}

/* swap: swap the top 2 elements of the stack */
void swap(void) {
    if (sp >= 2) {
        double tmp = val[sp -1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = tmp;
    } else {
        printf("error: less than 2 elements on stack\n");
    }
}

/* clearall: clear the entire stack */
void clearall(void) {
    sp = 0;
}
