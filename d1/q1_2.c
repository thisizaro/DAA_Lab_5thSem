#include <stdio.h>

int main()
{
    // accept input stream from input.txt
    FILE *sc = fopen("input.txt", "r");
    int n;
    // read an integer from the file
    fscanf(sc, "%d", &n);
    int arr[n];

    // read n integers from the file
    for (int i = 0; i < n; i++)
    {
        fscanf(sc, "%d", &arr[i]);
    }

    int prefixSum[n];

    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    // write in output file
    FILE *out = fopen("output.txt", "w");
    if (out == NULL)
    {
        perror("Error opening output file");
        return 1;
    }
    fprintf(out, "Prefix Sum Array:\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(out, "%d ", prefixSum[i]);
    }
    fclose(out);
    fclose(sc);
    return 0;
}