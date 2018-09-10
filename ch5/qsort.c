#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort2(void *lineptr[], int left, int right, int (*comp)(void *, void *), int rev);

int numcmp(char *, char *);
int numcmpi(char *, char *);
int strcmpi(char *, char *);

int main(int argc, char *argv[])
{
  int nlines;
  int numeric = 0;
  int reverse = 0;
  int fold = 0;
  char c;
    int (*fn)(void*, void*); 
 
  while (--argc > 0 && ( (*++argv)[0] == '-' )) {
    while (( c = *++argv[0] )) {
      switch (c)
	{
	case 'r':
	  reverse = 1;
	  break;
	case 'n':
	  numeric = 1;
	  break;
	case 'f':
	  fold = 1;
	  break;
	default:
	  printf("find: illegal option %c\n", c);
	  argc = 0;
	  break;
	}
    }
  }

  if (numeric) {
      if (fold) {
          fn = (int (*)(void*, void*)) numcmpi;
      } else {
          fn = (int (*)(void*, void*)) numcmp;
      }
  } else {
      if (fold) {
          fn = (int (*)(void*, void*)) strcmpi;
      } else {
          fn = (int (*)(void*, void*)) strcmp;
      }
  }

  if((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort2((void **) lineptr, 0, nlines-1, fn, reverse);
      writelines(lineptr, nlines);
      return 0;
    }
  else
    {
      printf("input too big to sort\n");
      return 1;
    }
}

void qsort2(void *v[], int left, int right, int(*comp)(void *, void *), int rev)
{
  int i, last;
  void swap(void *v[], int, int);

  if(left >= right)
    return;
  swap(v, left, (left + right) / 2);
  last = left;
  for(i = left + 1; i <= right; i++) 
    if(( (*comp)(v[i], v[left]) < 0 ) != rev)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort2(v, left, last - 1, comp, rev);
  qsort2(v, last + 1, right, comp, rev);
}

#include <stdlib.h>

int numcmp(char *s1, char *s2)
{
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
}

int numcmpi(char *s1, char *s2)
{
    char ls1[strlen(s1)];
    char ls2[strlen(s2)];
  double v1, v2;

  for (int i = 0; *(s1++) != '\0'; i++) {
      ls1[i] = tolower(*s1);
  }

  for (int i = 0; *(s2++) != '\0'; i++) {
      ls2[i] = tolower(*s2);
  }

  v1 = atof(ls1);
  v2 = atof(ls2);
  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
}

int strcmpi(char *s, char *t) {
    for ( ; tolower(*s) == tolower(*t); s++, t++) {
        if (*s == '\0')
            return 0;
    }
    
    return tolower(*s) - tolower(*t);
}

void swap(void *v[], int i, int j)
{
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}


#define MAXLEN 1000   // max length of any input line
int my_getline(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = my_getline(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else
      {
	line[len-1] = '\0';   // delete newline
	strcpy(p, line);
	lineptr[nlines++] = p;
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

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
  int i;

  for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}
