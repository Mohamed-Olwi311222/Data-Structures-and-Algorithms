#include "insertion.h"

int main (void)
{
    int arr[6] = {1, 4, 2, 5 ,0, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    print_arr(arr, size);
    insertion_sort(arr, size);
    print_arr(arr, size);
}