#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#include <time.h>

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

// ---------------------------
// Solve function
// ---------------------------

double myPow(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }

    if (n < 0)
        return 1 / myPow(a, -n);

    return a * myPow(a, n - 1);
}

void solve()
{
    int a, n;
    a = read_int();
    n = read_int();

    double k;

    // power using recursion.
    k = myPow(a, n);
    printf("Power of %d^%d = %lf\n", a, n, k);
}

// ---------------------------
// Main function
// ---------------------------

int main()
{
    fastio();
    LOCAL_IO_SETUP;

    int t = 1;
    scanf("%d", &t);
    int k = t;
    while (t--)
    {
        clock_t start = clock();
        printf("Test Case %d:\n", k - t);
        solve();

        clock_t end = clock();
        double time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Time Spent: %f\n", time);
        printf("\n\n");
    }

    return 0;
}
