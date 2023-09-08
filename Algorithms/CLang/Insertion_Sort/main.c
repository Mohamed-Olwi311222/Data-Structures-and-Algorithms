#include "insertion.h"

int main (void)
{
    int arr[11] = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    print_arr(arr, size);
    insertion_sort(arr, size);
    print_arr(arr, size);
}