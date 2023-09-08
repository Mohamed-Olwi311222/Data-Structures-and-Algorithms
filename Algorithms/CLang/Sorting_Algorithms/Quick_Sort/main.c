#include "quick.h"

int main(void)
{
    int a[] = {8, 2, 4, 7, 1, 3, 9, 6, 5};
    int size = sizeof(a) / sizeof(a[0]);
    print_arr(a, size);
    quick_sort(a, size);
    print_arr(a, size);
}