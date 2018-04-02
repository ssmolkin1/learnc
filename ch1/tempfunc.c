#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float toCelsius(float fahrenheit);
float toFahr(float celsius);

/* Print conversion tables between Fahrenheit and Celsius */
int main()
{
    float fahr, celsius;
    
    printf("%s\t%s\n", "Fahrenheit", "Celsius");

    fahr = LOWER;
    while (fahr <= UPPER) {
        printf ("%10.0f\t%7.1f\n", fahr, toCelsius(fahr));
        fahr += STEP;
    }

    printf("\n%s\t%s\n", "Celsius", "Fahrenheit");

    celsius = LOWER;
    while (celsius <= UPPER) {
        printf ("%7.0f\t%10.1f\n", celsius, toFahr(celsius));
        celsius += STEP;
    }
  
}

/* Convert Fahrenheit to Celsius */
float toCelsius(float f) {
    return (5.0 / 9.0) * (f - 32.0);
}

/* Convert Celsius to Fahrenheit */
float toFahr(float c) {
    return c * (9.0 / 5.0) + 32.0;
}
