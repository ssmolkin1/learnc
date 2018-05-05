#ifndef _CALC_
#define _CALC_

enum types {
    NUMBER = '\0', SIN, COS, TAN
};

/* from stack.c */
void push(double);
double pop(void);
void print(void);
void dup(void);
void swap(void);
void clearall(void);

/* from getop.c */
int getop(char []);

/* from getch.c */
int getch(void);
void ungetch(int);
              
#endif
