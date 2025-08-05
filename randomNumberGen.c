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
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        int k = rand() % n; // generate random numbers between 0 and 99
        k++;
        printf("%d", k);
        printf(" ");
    }
}

int main()
{
    LOCAL_IO_SETUP;
    int k = 0;

    for (int i = 10; i <= 10000; i *= 10)
    {
        for (int j = 0; j < 3; j++)
        {
            k++;
            printf("%d\n", i);
            generate_random_numbers(i);
            printf("\n");
        }
    }

    printf("%d\n", k);

    return 0;
}
