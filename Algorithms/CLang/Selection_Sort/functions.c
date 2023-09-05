#include "selection.h"

/**
 * selection_sort - sort the array using selection sort
 * @arr: array to sort
 * @size: size of the array
 * Return: true if success otherwise false
*/
bool selection_sort(int *arr, int size)
{
    /**
     * Start is the first index available to swap
     * min is the smallest value from start to end
    */
    int i, j, min, tmp, start;

    if (arr == NULL || size <= 0)
    {
        perror("Arguments invaild\n");
        exit(1);
    }
    start = 0;
    for (i = 0; i < size; i++)
    {
        min = start;
        for (j = i; j < size; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        tmp = arr[start];
        arr[start] = arr[min];
        arr[min] = tmp;
        start++;
    }
    return (true);
}
/**
 * print_arr - prints an array
 * @arr: array to print
 * @size: size of the array
*/
void print_arr(int *arr, int size)
{
    int i;

    if (arr == NULL || size <= 0)
    {
        perror("Arguments invaild\n");
        exit(1);
    }
    for (i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}
