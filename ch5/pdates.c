#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(void)
{
  int y = 1984, m = 13, d = 12, yd = 494;
  int month, day;

  printf("Day: %d\n", day_of_year(y, m, d));
  month_day(y, yd, &month, &day);
  printf("Month: %d, Day: %d\n", month, day);
  return 0;
}

static char normal[] =  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char leap[] =  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static char *daytab[2] = {normal, leap};

/* day_of_year: set day of year form month & day */
int day_of_year(int year, int month, int day)
{
  int i, leap;

  if ((month < 1) || (month > 12)) {
      printf("%s\n", "Error: illegal month.");
      return 0;
  }

  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

  if ((day < 1) || (day > *(*(daytab + leap) + month))) {
      printf("%s\n", "Error: illegal day.");
      return 0;
  }
  
  for (i = 1; i < month; i++)
    day += *(*(daytab + leap) + i);
  return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i, leap;

  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

  if ((yearday < 1) || (yearday > 365 + leap)) {
      printf("%s\n", "Error: illegal day count.");
        *pmonth = 0;
        *pday = 0;
      return;
  }

  for (i = 1; yearday > *(*(daytab + leap) + i); i++)
    yearday -= *(*(daytab + leap) + i);
  *pmonth = i;
  *pday = yearday;
}
