#include "merge.h"

int main(void)
{
    int a[] = {1, 4, 5, 3, 0, 6};
    int size = sizeof(a) / sizeof(a[0]);
    print_arr(a, size);
    merge_sort(a, size);
    print_arr(a, size);
}