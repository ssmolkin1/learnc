#include <stdio.h>

#define swap(x, y) {typeof(x) tmp = x; x = y; y = tmp;}
#define dprint(x) {printf(#x " equals %.5g\n", x);}
#define passthru(x) x

int main(void)
{
   double x = 13.24234;
   double y = 312.43214;

   dprint(passthru(x));
   
   swap(x, y);

   dprint(x);
   dprint(y);
}
