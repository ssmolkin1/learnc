#include <stdio.h>

#define MAXSIZE  200000
#define USE_BIN2 1
#define NTESTS 10000000
#define TESTX -10

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main(void) {
    int testv[MAXSIZE], index;

    /* create the test search array */
    for (int i = 0; i < MAXSIZE; i++) {
        testv[i] = i;
    }

    /* Pick version of binsearch to use based on switch  and run it NTESTS */
    if (USE_BIN2) {
        for (int i = 0; i < NTESTS; i++) {
            index = binsearch2(TESTX, testv, MAXSIZE);
        }
    } else {
        for (int i = 0; i < NTESTS; i++) {
            index = binsearch(TESTX, testv, MAXSIZE);
        }
    }

    if (index > -1) {
        printf("Number %d was found at index %d\n", TESTX, index);
    } else {
        printf("Nnumber %d was not found\n", TESTX);
    }
}

int binsearch(int x, int v[], int n) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (x < v[mid]) {
            high = mid - 1;
        } else if (x > v[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int binsearch2(int x, int v[], int n) {
    int low = 0, high = n - 1, mid = (high + low) / 2;

    while (low <= high && v[mid] != x) {
        if (x < v[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }

        mid = (low + high) / 2;
    }

    if (v[mid] == x) {
        return mid;
    }

    return -1;
}
