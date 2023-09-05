#include "merge.h"
/**
 * merge_sort - merge sort the unsorted array
 * @arr: array to sort
 * @size: size of the array to sort
 * Return: 1 if success otherwise exit the program
*/
int merge_sort(int *arr, int size)
{
    if (size < 0 || arr == NULL)
    {
        perror("Invalid Arguments");
        exit(1);
    }
    msort(arr, size);
    return (1);
}



/**
 * msort - sort the array using merge sort
 * @arr: array to sort
 * @size: size of the array
 * Return: true if success otherwise false
*/
void msort(int *arr, int size)
{
    int middle, i, j;

    if (size == 1)
    {
        return;
    }
    middle = size / 2;
    int left_arr[middle];
    int right_arr[size - middle];

    j = 0;
    for (i  = 0; i < size; i++)
    {
        if (i < middle)
        {
            left_arr[i] = arr[i];
        }
        else
        {
            right_arr[j] = arr[i];
            j++;
        }
    }
    merge_sort(left_arr, middle);
    merge_sort(right_arr, size - middle);
    merge(left_arr, middle, right_arr, size - middle, arr, size);
}
/**
 * merge - merge the arrays
 * @left_arr: left array
 * @left_l: left array length
 * @right_arr: right arr
 * @right_l: right array length
 * @arr: the original array
 * @size: length of the original array
*/
void merge(int *left_arr, int left_l, int *right_arr, int right_l, int *arr, int size)
{
    int i = 0, l = 0, r = 0;

    while (l < left_l && r < right_l)
    {
        if (right_arr[r] > left_arr[l])
        {
            arr[i] = left_arr[l];
            l++;
        }
        else
        {
            arr[i] = right_arr[r];
            r++;
        }
        i++;
    }
    while (l < left_l)
    {
        arr[i] = left_arr[l];
        l++;
        i++;
    }
    while (r < right_l)
    {
        arr[i] = right_arr[r];
        r++;
        i++;
    }
    
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
