#include <stdio.h>

main()
{
  /* Just trying out a comment */
  int fahr;

  printf("%s\t%s\n", "Fahrenheit", "Celsius");

  for (fahr = 300; fahr >= 0; fahr -= 20) {
    printf ("%10d\t%7.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
  }
}
