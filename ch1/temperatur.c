#include <stdio.h>

main()
{
  /* Just trying out a comment */
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  printf("%s\t%s\n", "Fahrenheit", "Celsius");

  fahr = lower;
  while (fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf ("%10.0f\t%7.1f\n", fahr, celsius);
    fahr += step;
  }

  printf("\n%s\t%s\n", "Celsius", "Fahrenheit");

  celsius = lower;
  while (celsius <= upper) {
    fahr = celsius * (9.0 / 5.0) + 32.0;
    printf ("%7.0f\t%10.1f\n", celsius, fahr);
    celsius += step;
  }
  
}
