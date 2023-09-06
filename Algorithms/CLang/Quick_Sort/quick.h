#ifndef QUICk_H
#define QUICK_H

/*-----------------Include Files----------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*-----------------Function Prototypes----------------------*/
int quick_sort(int *arr, int size);
void q_sort(int *arr, int low, int high);
void swap(int *num1, int *num2);
int partition(int *arr, int low, int high);
void print_arr(int *arr, int size);
/*-----------------End File---------------------------------*/
#endif /*MERGE_H*/