#include <stdio.h>
#include <math.h>

double throwback(double x);

int main(void) {
    double x = M_PI;
    double s = sin(x), c = cos(x), t = tan(x);

    printf("sin(pi):\t%g, cos(pi):\t%g, tan(pi):\t%g\n", s, c, t);
    printf("sin(pi):\t%g, cos(pi):\t%g, tan(pi):\t%g\n", sin(x), cos(x), tan(x));
    printf("sin(pi):\t%g, cos(pi):\t%g, tan(pi):\t%g\n", sin(throwback(x)), cos(throwback(x)), tan(throwback(x)));
}

double throwback(double x) {
    return x;
}

