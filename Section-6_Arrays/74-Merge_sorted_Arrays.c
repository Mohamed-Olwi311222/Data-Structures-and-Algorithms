#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * mergeArrays - merge sorted arrays of ints
 * @arr1: sorted array 1
 * @arr2: sorted array 2
 * @arr1Size: size of sorted array 1
 * @arr2Size: size of sorted array 2
 * Return: a pointer to the new malloced merged array
*/
int* mergeArrays(int* arr1, int* arr2, int arr1Size, int arr2Size)
{
    int totalSize = arr1Size + arr2Size, i = 0, j = 0, k = 0;
    int *mergedArr, *nonEmptyArr ;

    mergedArr = malloc(totalSize * sizeof(int));
    if (mergedArr == NULL)
            return (NULL);

    if (arr1Size == 0 || arr2Size == 0) 
    {
        nonEmptyArr = arr1Size == 0 ? arr2 : arr1;
        memcpy(mergedArr, nonEmptyArr, totalSize * sizeof(int));
        return (mergedArr);
    }

    /*
    each lteration
     we compare arr1[i] with arr2[j] each lteration
     if arr1[i] < arr2[j] || j is >= arr2size(thats mean that every element in arr2 is in mergedArr)
        we put arr1[i] into merged array
     else
        the arr2[j] < arr1[i] so we put the current element into mergedArr[k]
     k++
    */
    while (i < arr1Size || j < arr2Size) 
    {
        if (i < arr1Size && (j >= arr2Size || arr1[i] < arr2[j]))
        {
            mergedArr[k] = arr1[i];
            i++;
        } 
        else
        {
            mergedArr[k] = arr2[j];
            j++;
        }
        k++;
    }

    return (mergedArr);
}

void printArray(int *arr, int size)
{
    for(int i = 0; i < size; i++)
        printf("%i ", arr[i]);
    printf("\n");
}

int main(void)
{
    int arr1[] = {0, 3, 4, 31};
    int arr2[] = {1, 3, 5, 10, 15};
    int totalSize, arr1Size, arr2Size;
    int *mergedArr;

    arr1Size = sizeof(arr1) / sizeof(arr1[0]);
    arr2Size = sizeof(arr2) / sizeof(arr2[0]);
    totalSize = arr1Size + arr2Size;

    printf("arr1[]: ");
    printArray(arr1, arr1Size);
    
    printf("arr2[]: ");
    printArray(arr2, arr2Size);

    mergedArr = mergeArrays(arr1, arr2, arr1Size, arr2Size);
    printf("mergedArr[]: ");
    printArray(mergedArr, totalSize);

    free(mergedArr);
    return (0);
}