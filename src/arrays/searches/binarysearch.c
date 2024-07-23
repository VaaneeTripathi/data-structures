#include <stdio.h>
#include <stdlib.h>
// Objective - perform binary search on a sorted array to find a given element
 
int binarySearch(int *arrayToBeSearched, int lowerEnd, int higherEnd, int elementToBeFound)
{
    // Check if search range is valid
    if (lowerEnd <= higherEnd)
    {
        // Find the middle element
        int middleOftheArray = (lowerEnd + higherEnd)/2;
        int middleElement = arrayToBeSearched[middleOftheArray];

        // Check if middleElement is equal to elementToBeFound
        if (middleElement == elementToBeFound)
        {
            return 0;
        }

        // If not, compare
        else
        {
            if (elementToBeFound < middleElement)
            {
                // Call the function on the left half 
                return binarySearch(arrayToBeSearched, lowerEnd, middleOftheArray - 1, elementToBeFound);
            }

            if (elementToBeFound > middleElement)
            {
                // Call the function on the right half
                return binarySearch(arrayToBeSearched, middleOftheArray + 1, higherEnd, elementToBeFound);
            }

        }
    
    }

    return -1;
    
}

// The arguments to this function are so, so that we can use command-line arguments to run the file
int main(int argc, char *argv[])
{
    // Check if the required arguments are there, if not exit
    // Exit status 1 - unsuccessful termination
    if (argc != 3)
    {
        printf("The program requires more arguments to proceed further.\nRequired Usage: %s <length of the array> <multiplication factor>\n", argv[0]);
        exit(1);
    }

    // Convert the user input from string to integers and store them in variables
    int lengthOfTheArray = atoi(argv[1]);
    int factor = atoi(argv[2]);

    // Allocate memory
    int *arr = (int *)malloc(lengthOfTheArray*sizeof(int));

    // Handle memory-allocation failure
    if (arr == NULL)
    {
        perror("Memory allocation failed");
        exit(1);
    }

    // Initialize a sorted array
    for (int i = 0; i < lengthOfTheArray; i++)
    {
        arr[i] = factor*i;
    }

    int elementToBeFound;
    printf("Enter the number you wish to search for: ");
    scanf("%d", &elementToBeFound);

    int resultOfSearch = binarySearch(arr, 0, lengthOfTheArray - 1, elementToBeFound);
    if (resultOfSearch == 0)
    {
        printf("Number found!\n");
    }

    else
    {
        printf("Number not found :(\n");
    }

    // Free allocated memory
    free(arr);
    return 0;

}
