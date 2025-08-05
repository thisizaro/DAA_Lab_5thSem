#include <stdio.h>

struct ElementCount
{
    int element;
    int count;
};

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

    // Finding total number of times each element appears in the array
    struct ElementCount elementCounts[n];
    int uniqueCount = 0;
    for (int i = 0; i < n; i++)
    {
        int found = 0;
        for (int j = 0; j < uniqueCount; j++)
        {
            if (elementCounts[j].element == arr[i])
            {
                elementCounts[j].count++;
                found = 1;
                break;
            }
        }
        if (!found)
        {
            elementCounts[uniqueCount].element = arr[i];
            elementCounts[uniqueCount].count = 1;
            uniqueCount++;
        }
    }

    // write in output file
    FILE *out = fopen("output.txt", "w");
    if (out == NULL)
    {
        perror("Error opening output file");
        return 1;
    }

    // Ouput all dupplicate elements in output.txt
    fprintf(out, "Duplicate elements and their counts:\n");
    for (int i = 0; i < uniqueCount; i++)
    {
        if (elementCounts[i].count > 1)
        {
            fprintf(out, "Element: %d, Count: %d\n", elementCounts[i].element, elementCounts[i].count);
        }
    }

    // Output the most repeated element in the output.txt
    fprintf(out, "Most repeated element:\n");
    int maxCount = 0;
    int mostRepeatedElement = -1;
    for (int i = 0; i < uniqueCount; i++)
    {
        if (elementCounts[i].count > maxCount)
        {
            maxCount = elementCounts[i].count;
            mostRepeatedElement = elementCounts[i].element;
        }
    }
    if (mostRepeatedElement != -1)
    {
        fprintf(stdout, "Element: %d, Count: %d\n", mostRepeatedElement, maxCount);
    }
    else
    {
        fprintf(stdout, "No repeated elements found.\n");
    }

    fclose(out);
    fclose(sc);
    return 0;
}