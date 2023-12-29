#include <stdio.h>
#include <stdlib.h>
// Objective: perform binary search on a sorted array to find a given element
 
 int binarySearch(int *arrayToBeSearched, int elementToBeFound, int arrayLength)
 {
    
    // Check the middle element
    int middleElement = arrayToBeSearched[arrayLength/2];
    
    if (elementToBeFound == middleElement)
    {
        return 1;
    }
    
    else 
    {
        // If less than the middle element, call function on left half of array
        if (elementToBeFound < middleElement)
        {
                int *newArray;
                for (int i = 0; i < arrayLength/2; i++)
                {
                    newArray[i] = arrayToBeSearched[i];
                }
                binarySearch(newArray, elementToBeFound, arrayLength/2 - 1);
        }
    
        // If more than the middle element, call function right half of array
        else 
        {
                int *newArray;
                for (int i = arrayLength/2 + 1; i <= arrayLength; i++)
                {
                    newArray[i] = arrayToBeSearched[i];
                }
                binarySearch(newArray, elementToBeFound, arrayLength/2 - 1);
        }

    }

    return -1;

 }

 int main(int argc, char *argv[]) 
 {
    // Check if the required user inputs are present, if not exit
    // Exit status 1 - unsuccessful termination
    if (argc != 3)
    {
        printf("The program requires a seed to proceed further.\nRequired Usage: %s <first element> <increment factor>\n", argv[0]);
        exit(1);
    }
    
    // Initialize a random integer array.

    // Allocate memory for sampleArray worst case scenario
    int *sampleArray = (int *)malloc(101 * sizeof(int));
    
    // Handle memory-allocation failure
    if (sampleArray == NULL)
    {
        perror("Memory allocation failed");
        exit(1);
    }

    // Store user-entered seed in a variable seed and set some contsants for random number generation
    int firstElement = atoi(argv[1]);
    int incrementFactor = atoi(argv[2]);

    // Generate an integer array by adding the increment factor to the firstElement repeatedly till it is less than 100
    for (int itr = 0; sampleArray[itr] < 100; itr++)
    {
        sampleArray[itr] = firstElement + incrementFactor;
        firstElement = sampleArray[itr];
    }

    // Calculate arrayLength
    int arrayLength = sizeof(sampleArray)/sizeof(int);

    // Print the integer-array
    printf("Array: ");
    for (int itr = 0; itr < arrayLength; itr++)
    {
        printf("%d ", sampleArray[itr]);
    }
    printf("\n");

    // Ask user for an integer to search for
    int numberToBeSearched;
    printf("Number to search for: ");
    scanf("%d", &numberToBeSearched);


    // Call linearSearch
    int resultOfSearch = binarySearch(sampleArray, numberToBeSearched, arrayLength);

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


