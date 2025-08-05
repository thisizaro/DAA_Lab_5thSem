#include <stdio.h>

int main()
{
    // accept input stream from input.txt
    FILE *sc = fopen("input.txt", "r");
    int n;

    fscanf(sc, "%d", &n);
    int arr[n];

    // read n integers from the file
    for (int i = 0; i < n; i++)
    {
        fscanf(sc, "%d", &arr[i]);
    }

    // find second largest element in the array
    int largest = arr[0];
    int second_largest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] > second_largest && arr[i] != largest)
        {
            second_largest = arr[i];
        }
    }

    // find second smallest element in the array
    int smallest = arr[0];
    int second_smallest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            second_smallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] < second_smallest && arr[i] != smallest)
        {
            second_smallest = arr[i];
        }
    }

    // ouput in output.txt
    FILE *out = fopen("output.txt", "w");
    if (out == NULL)
    {
        perror("Error opening output file");
        return 1;
    }
    fprintf(out, "Second largest element: %d\n", second_largest);
    fclose(out);

    return 0;
}