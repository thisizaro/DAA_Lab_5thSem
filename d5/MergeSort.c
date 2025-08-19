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
void merge(int arr[], int temp[], int l, int m, int r, int *c)
{
    int i = l, j = m + 1, k = l;

    while (i <= m && j <= r)
    {
        (*c)++;
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= m)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];

    for (i = l; i <= r; i++)
        arr[i] = temp[i];
}

void mergeSort(int arr[], int temp[], int l, int r, int *c)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, temp, l, m, c);
        mergeSort(arr, temp, m + 1, r, c);
        merge(arr, temp, l, m, r, c);
    }
}

void solve()
{
    int n = read_int();
    printf("n: %d\n", n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = read_int();
    }

    int comparisionCount = 0;

    // merge sort.
    int temp[n];
    mergeSort(arr, temp, 0, n - 1, &comparisionCount);

    printf("After sorting: ");
    for (int i = 0; i < n; i++)
    {
        // printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Number of comparisons: %d\n", comparisionCount);
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
