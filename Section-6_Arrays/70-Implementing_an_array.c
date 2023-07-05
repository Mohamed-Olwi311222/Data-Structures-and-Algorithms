#include <stdio.h>
#include <stdlib.h>

/**
 * struct Array - a struct to define an array of ints
 * @int: a pointer of type int to determine the data to put
 * @size: size of the array
*/
typedef struct Array
{
    int* data;
    int size;
}Array;

/**
 * createArray - create array
 * @size: size of the array
 * Return: Array of ints
*/
Array createArray(int size)
{
    Array array;
    array.data = (int *) malloc(size * sizeof(int));
    if (array.data == NULL)
        exit(0);
    array.size = size;
    return (array);
}

/**
 * setElement - set element of array of index with value
 * @array: pointer of type array
 * @index: index of the element to set
 * @value: value to set
 * O(1)
*/
void setElement(Array *array, int index,int value)
{
    if (index < 0 || index >= array->size)
        return;
    array->data[index] = value;
}

/**
 * getElement - get element of array of index with value
 * @array: pointer of type array
 * @index: index of the element to get its value
 * Return: the required value of @index
 * O(1)
*/
int getElement(Array *array, int index)
{
    if (index < 0 || index >= array->size)
        return (0);
    return (array->data[index]);
}

/**
 * freeArray - free an array
 * @array: pointer of type array
*/
void freeArray(Array *array)
{
    free(array->data);
    array->size = 0;
}

/**
 * printArray - print the given array
 * @array: the array to print
 * O(n)
*/
void printArray(Array array)
{
        for (int i = 0; i < array.size; i++)
        {
            printf("%i", getElement(&array, i));
            if(i == array.size - 1)
                return;
            printf(",");
        }
}

int main (void)
{
    Array arr = createArray(10);
    for (int i = 0; i < arr.size; i++)
        setElement(&arr, i, i);
    printArray(arr);
    printf("\n");
    freeArray(&arr);
}
