#include <stdio.h>
#include <string.h>

#define MAXLINES 5000   // max #lines to be sorted
#define MAXLEN 1000   // max length of any input line

char *lineptr[MAXLINES];  // pointers to text lines

int readlines(char *lineptr[], int nlines, char **bufptr);
void writelines(char *lineptr[], int nlines);
int my_getline(char *, int);


void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main(void)
{
    char buffer[MAXLEN * MAXLINES];
    char *bufptr = buffer;

  int nlines;    // number of input lines read

  if((nlines = readlines(lineptr, MAXLINES, &bufptr)) >= 0)
    {
      qsort(lineptr, 0, nlines-1);
      writelines(lineptr, nlines);
      return 0;
    }
  else
    {
      printf("error: input too big to sort\n");
      return 1;
    }
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char **bufptr)
{
  int len, nlines;
  char line[MAXLEN];

  nlines = 0;
  while ((len = my_getline(line, MAXLEN)) > 0)
    if (nlines >= maxlines)
      return -1;
    else
      {
	line[len-1] = '\0';   // delete newline
	strcpy(*bufptr, line);
	lineptr[nlines++] = *bufptr;
        *bufptr += len;
      }
  return nlines;
}

/* my_getline: read a line into s, return length */
int my_getline(char *s, int lim)
{
  int c, i;

  for (i = 0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; i++)
    s[i] = c;
  if (c == '\n')
    {
      s[i] = c;
      ++i;
    }
  s[i] = '\0';
  return i;
}

#define ALLOCSIZE 50000           // size of available space

static char allocbuf[ALLOCSIZE];  // storage for alloc 
static char *allocp = allocbuf;   // next free position

char *alloc(int n)
{
  if (allocbuf + ALLOCSIZE - allocp >= n)   // if it fits
    {
      allocp += n;
      return allocp - n;  
    }
  else
    return 0;
}

/* writelies: wtire output lines */
void writelines(char *lineptr[], int nlines)
{
  int i;

  for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
  int i, last;
  void swap(char *v[], int i, int j);

  if (left >= right)  // do nothing if array contains fewer than two elements
    return;
  swap(v, left, (left + right )/2);
  last = left;
  for (i = left+1; i <= right; i++)
    if (strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last-1);
  qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
