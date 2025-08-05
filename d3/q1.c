/*
 Write a menu driven program to sort list of array elements using Insertion Sort, Selection Sort, Bubble Sort, Merge Sort, Quick Sort and Heap Sort.
 Sort technique and calculate the execution time only to sort the elements. Count the number of
 comparisons
*/

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

void SelectionSort_start_function()
{
}

void InsertionSort_start_function()
{
    int n;
    n = read_int();
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        // printf("arr[%d]: ", i);
        arr[i] = read_int();
    }

    // Insertion Sort. with time count. and steps count.
    // long long steps = 0;
    long long c = 0;
    clock_t start = clock();

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        // steps++; // key assign holo

        while (j >= 0)
        {
            c++; // comparision count korlam
            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
                // steps++; // shift gulo count hocche
            }
            else
            {
                break;
            }
        }

        arr[j + 1] = key;
        // steps++; // key insert count hocche.
    }

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    // printf("Sorted array: ");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", arr[i]);
    // }
    printf("n: %d", n);
    printf("\ncomparisions: %d\n", c);
    printf("Time taken: %lf seconds\n", time_spent);
    printf("\n\n");
}

// ---------------------------
// Main function
// ---------------------------

int main()
{
    fastio();
    LOCAL_IO_SETUP;

    int t;
    scanf("%d", &t);

    while (t--)
        InsertionSort_start_function();

    return 0;
}
