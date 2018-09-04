#include <stdio.h>
#include <stdlib.h>  // for atof()
#include <string.h>

void push (double);
double pop (void);

/* reverse Polish calculator */
int main(int argc, char *argv[])
{
  int n;
  double op2;

  while (--argc > 0)
    {
        char *arg = *++argv;

        if ((n = atof(arg)) != 0) {
                push(n);
        } else if (strlen(arg) == 1) {
            switch (arg[0])
                {
                case '0':
                push(0);
                break;
                case '+':
                push(pop() + pop());
                break;
                case '-':
                op2 = pop();
                push(pop() - op2);
                break;
                case '*':
                push (pop() * pop());
                break;
                case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push (pop() / op2);
                break;
                default:
                printf("error: unknown command %s\n", arg);
                break;
                }
        }  else {
                printf("error: unknown command %s\n", arg);
        }
        }
        

	  printf("\t%.8g\n", pop());
  return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

/* push: push f onto value stack */
void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, con't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else
    {
      printf("error: stack empty\n");
      return 0.0;
    }
}
