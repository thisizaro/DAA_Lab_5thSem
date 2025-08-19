// random number generator
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef ONLINE_JUDGE
#define LOCAL_IO_SETUP                \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#else
#define LOCAL_IO_SETUP
#endif

void generate_random_numbers(int n)
{

    // srand(time(0));
    for (int i = 0; i < n; i++)
    {
        int k = rand() % n; // generate random numbers between 0 and 99
        k++;
        printf("%d", k);
        printf(" ");
    }
    printf("\n");
}
void generate_sortedAsc_numbers(int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
}

void generate_sortedDesc_numbers(int n)
{
    for (int i = n; i >= 1; i--)
    {
        printf("%d ", i);
    }
    printf("\n");
}

int main()
{
    LOCAL_IO_SETUP;
    int k = 0;

    for (int i = 100; i <= 1000; i += 100)
    {
        printf("%d\n", i);
        generate_sortedAsc_numbers(i);
        k++;
        printf("%d\n", i);
        generate_sortedDesc_numbers(i);
        k++;
        printf("%d\n", i);
        generate_random_numbers(i);
        k++;
    }

    printf("%d\n", k);

    return 0;

    // generate_random_numbers(100);
}
