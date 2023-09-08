#include "quick.h"

void q_sort(int *arr, int low, int high);
void swap(int *num1, int *num2);
int partition(int *arr, int low, int high);
/**
 * quick_sort - quick sort the unsorted array
 * @arr: array to sort
 * @size: size of the array to sort
 * Return: 0 if success otherwise exit the program
*/
int quick_sort(int *arr, int size)
{
    if (size < 0 || arr == NULL)
    {
        perror("Invalid Arguments");
        exit(1);
    }
    q_sort(arr, 0, size - 1);
    return (0);
}
/**
 * q_sort - sort the unsorted array with quick sort algorithm
 * @arr: array to sort
 * @start: starting index of the array
 * @end: ending index of the array
*/
void q_sort(int *arr, int start, int end)
{
    if (end <= start)
    {
        return;
    }
    int pivot = partition(arr, start, end);

    // Recursively sort the left and right partitions
    q_sort(arr, start, pivot - 1);
    q_sort(arr, pivot + 1, end);
}

/**
 * partition - partition the array for Quick Sort
 * @arr: array to partition
 * @start: starting index of the array
 * @end: ending index of the array
 * @return: index of the pivot element
 */
int partition(int *arr, int start, int end)
{
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j <= end - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[end]);
    return (i);
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
