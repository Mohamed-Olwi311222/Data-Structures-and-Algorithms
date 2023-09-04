#include "bubble.h"

/**
 * bubble_sort - sort the array using bubble sort
 * @arr: array to sort
 * @size: size of the array
 * Return: true if success otherwise false
*/
bool bubble_sort(int *arr, int size)
{
    int i, j, tmp;

    if (arr == NULL || size <= 0)
    {
        perror("Arguments invaild\n");
        exit(1);
    } 
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
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
