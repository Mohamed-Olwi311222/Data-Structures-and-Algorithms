#include "binary.h"

/**
 * binary_search -  binary search through a sorted list
 * @arr: array to search through
 * @size: size of the array
 * @target: the target to look for
 * Return: the index if found otherwise -1
*/
int binary_search(int *arr, int size, int target)
{
    int low, high, mid;

    if (arr == NULL)
    {
        return (-1);
    }
    else if (size < 0)
    {
       return (-1);
    }
    low = 0;
    high = size - 1;
    mid = (low + high) / 2;
    while (low <= high)
    {
        if (arr[mid] == target)
        {
            return (mid);
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        mid = (low + high) / 2;
    }
    return (-1);
}