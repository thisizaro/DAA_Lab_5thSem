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

// ---------------------------
// Solve function
// ---------------------------

int to_binary(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return (n % 2) + 10 * to_binary(n / 2);
    }
}

void solve()
{
    int a = read_int();
    int b = read_int();

    int g = gcd(a, b);
    printf("GCD of %d and %d is: %d\n", a, b, g);
}

int main()
{
    fastio();

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int t = 1;
    scanf("%d", &t);

    while (t--)
    {
        solve();
    }

    return 0;
}
