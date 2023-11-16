#include <stdio.h>
#include <stdlib.h>
// Objective - linearly search through an array to find an element

int linearSearch(int *arrayToBeSearched, int elementToBeFound, int lengthOfArray) 
{

    // Iterate through array to find the element
    for (int iter = 0; iter < lengthOfArray; iter++)
    {
        if (arrayToBeSearched == NULL)
        {
            return 0;
        }

        if (arrayToBeSearched[iter] == elementToBeFound)
        {
            return 1;
        }
    }

    return -1;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("The program requires a seed to proceed further.\nRequired Usage: %s <seed>\n", argv[0]);
        exit(1);
    }
    // Initialize an integer array
    int numberOfElements = 10;
    int *sampleArray = (int *)malloc(numberOfElements * sizeof(int));
    int seed = atoi(argv[1]);

    for (int itr = 0; itr < numberOfElements; itr++)
    {
        sampleArray[itr] = 3*(seed/2) + 5;
        seed = seed + seed/2;
    }

    // Print the integer-array
    printf("Array: ");
    for (int itr = 0; itr < numberOfElements; itr++)
    {
        printf("%d ", sampleArray[itr]);
    }
    printf("\n");

    // Ask user for an integer to search for
    int numberToBeSearched;
    printf("Number to search for: ");
    scanf("%d", &numberToBeSearched);


    // Call linearSearch
    int resultOfSearch = linearSearch(sampleArray, numberToBeSearched, numberOfElements);

    if (resultOfSearch == 0)
    {
        printf("Empty Array!");
    }
    if (resultOfSearch == 1)
    {
        printf("Number Found!\n");
    }
    else
    {
        printf("Number not Found :(\n");
    }


}
// TODO: print errors (error handling)
// TODO: deal with memory allocation failure 
