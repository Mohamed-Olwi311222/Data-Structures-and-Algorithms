#include "insertion.h"

/**
 * insertion_sort - sort the array using insertion sort
 * @arr: array to sort
 * @size: size of the array
 * Return: true if success otherwise false
*/
bool insertion_sort(int *arr, int size)
{
    int i, j, *tmp;

    if (arr == NULL || size <= 0)
    {
        perror("Arguments invaild\n");
        exit(1);
    }
    /*Start from index 1 and make tmp equal index 1 - 1 which is 0 and compare them and repeat with i++*/
    for (i = 1; i < size; i++)
    {
        tmp = &(arr[i]);
        j = i - 1;
        while (j >= 0 && arr[j] > *tmp)
        {
            /*Keep swaping until it breaks*/
            swap(tmp, &(arr[j]));
            tmp = &(arr[j]);
            j--;
        }
    }
    return (true);
}
/**
 * swap - swap two numbers
 * @num1: number one
 * @num2: number two
*/
void swap(int *num1, int *num2)
{
    int tmp;

    if (num1 == NULL || num2 == NULL)
    {
        return;
    }
    tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
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
