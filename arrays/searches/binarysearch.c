#include <stdio.h>
#include <stdlib.h>
// Objective: perform binary search on a sorted array to find a given element
 
int binarySearch(int *arrayToBeSearched, int lowerEnd, int higherEnd, int elementToBeFound)
{
    // Find the middle element
    if (lowerEnd <= higherEnd)
    {
    int middleOftheArray = (lowerEnd + higherEnd)/2;
    int middleElement = arrayToBeSearched[middleOftheArray];

    // Check if middleElement is equal to elementToBeFound
    if (middleElement == elementToBeFound)
    {
        return 1;
    }

    else
    {
        if (elementToBeFound < middleElement)
        {
            return binarySearch(arrayToBeSearched, lowerEnd, middleOftheArray - 1, elementToBeFound);
        }

        if (elementToBeFound > middleElement)
        {
            return binarySearch(arrayToBeSearched, middleOftheArray + 1, higherEnd, elementToBeFound);
        }

    }
    
    }

    return -1;
    
}


int main(void)
{
 int lengthOfTheArray = 15;

 int *arr = (int *)malloc(lengthOfTheArray*sizeof(int));
 for (int i = 0; i < lengthOfTheArray; i++)
 {
    arr[i] = 2*i;
 }

 int elementToBeFound = 9;

 int result = binarySearch(arr, 0, lengthOfTheArray - 1, elementToBeFound);
 if (result == 1)
 {
    printf("yay!\n");
 }

 else
 {
    printf("nay!\n");
 }

 free(arr);
 return 0;

}