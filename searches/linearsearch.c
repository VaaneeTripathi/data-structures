#include <stdio.h>
#include <stdlib.h>
// Objective - linearly search through an array to find an element

int linearSearch(int *arrayToBeSearched, int elementToBeFound, int lengthOfArray) 
{

    // Iterate through array to find the element
    for (int iter = 0; iter < lengthOfArray; iter++)
    {
        // If empty array, return 0
        if (arrayToBeSearched == NULL)
        {
            return 0;
        }

        // If element found, return 1
        if (arrayToBeSearched[iter] == elementToBeFound)
        {
            return 1;
        }
    }
    
    // else, return -1
    return -1;
}

// The arguments to this function are so, so that we can use command-line arguments to run the file
int main(int argc, char *argv[])
{
    // Check if there is a seed, if not exit
    // Exit status 1 - unsuccessful termination
    if (argc != 2)
    {
        printf("The program requires a seed to proceed further.\nRequired Usage: %s <seed>\n", argv[0]);
        exit(1);
    }
    
    // Initialize a random integer array.

    // Initialize numberOfElements and allocate memory for sampleArray
    int numberOfElements = 10;
    int *sampleArray = (int *)malloc(numberOfElements * sizeof(int));
    
    // Handle memory-allocation failure
    if (sampleArray == NULL)
    {
        perror("Memory allocation failed");
        exit(1);
    }

    // Store user-entered seed in a variable seed and set some contsants for random number generation
    int seed = atoi(argv[1]);
    int a = 32;
    int c = 19;

    // Generate a random integer array
    // (the function used here might not be the most robust way to do this but is sufficient for this use-case)
    for (int itr = 0; itr < numberOfElements; itr++)
    {
        sampleArray[itr] = (a*seed + c) % 100;
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

    // perror prints error messages
    if (resultOfSearch == 0)
    {
        perror("Empty Array. Cannot perform search operation");
        exit(1);
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

