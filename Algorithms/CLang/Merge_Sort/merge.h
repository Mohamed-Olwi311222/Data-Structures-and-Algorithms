#ifndef MERGE_H
#define MERGE_H

/*-----------------Include Files----------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*-----------------Function Prototypes----------------------*/
int merge_sort(int *arr, int size);
void msort(int *arr, int size);
void merge(int *left_arr, int left_l, int *right_arr, int right_l, int *arr, int size);
void print_arr(int *arr, int size);
/*-----------------End File---------------------------------*/
#endif /*MERGE_H*/