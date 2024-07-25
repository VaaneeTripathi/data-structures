#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Objective - perform bubble sort on an array in ascending order


// Function to implement bubble sort on an unsorted array 
void bubbleSort(int *unsortedArray, int lengthOfTheArray)
{
    // First for loop to iterate over each element
    for (int idx = 0; idx <= (lengthOfTheArray - 1); idx++)
    {
        bool swapped = false;

        // Second for loop compare elements and exchange them
        for (int index = 0; index <= (lengthOfTheArray - idx - 2); index++)
        {
            // Compare with next element
            if (unsortedArray[index] > unsortedArray[index + 1])
            {
                // Swap the elements
                int temp = unsortedArray[index];
                unsortedArray[index] = unsortedArray[index + 1];
                unsortedArray[index + 1] = temp;
                swapped = true;
            }
        }

        // Iif no swaps in an iteration, break
        if (swapped == false)
        {
            break;
        }
    }
}

int main()
{
    // Declare an array
    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    // Calculate the size of the array - number of elements
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the function
    bubbleSort(arr, n);

    // Print the sorted array
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}