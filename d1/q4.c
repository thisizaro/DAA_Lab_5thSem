#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define fastio()                     \
    setvbuf(stdin, NULL, _IONBF, 0); \
    setvbuf(stdout, NULL, _IONBF, 0);

#ifndef ONLINE_JUDGE
#define LOCAL_IO_SETUP                \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#else
#define LOCAL_IO_SETUP
#endif

// ---------------------------
// Input helper functions
// ---------------------------

int read_int()
{
    int x;
    scanf("%d", &x);
    return x;
}

long long read_long()
{
    long long x;
    scanf("%lld", &x);
    return x;
}

float read_float()
{
    float x;
    scanf("%f", &x);
    return x;
}

double read_double()
{
    double x;
    scanf("%lf", &x);
    return x;
}

char read_char()
{
    char x;
    scanf(" %c", &x); // space before %c to skip whitespace
    return x;
}

void read_string(char *str)
{
    scanf("%s", str);
}

// ---------------------------
// Utility math functions
// ---------------------------

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}

void rotate_right(int *arr, int n)
{
    if (n <= 1)
        return; // No rotation needed for arrays of size 0 or 1

    int last = arr[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = last;
}

int main()
{
    fastio();
    LOCAL_IO_SETUP;

    int t = 0;
    scanf("%d", &t);

    int arr[t];
    for (int i = 0; i < t; i++)
    {
        arr[i] = read_int();
    }

    rotate_right(arr, t);

    printf("Rotated array: ");

    for (int i = 0; i < t; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
