#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 10
#define DEFAULT_VALUE (int)(0xFFFFFFFFFFFFFFFUL)
int hash_table[TABLE_SIZE] = {0};

void init_hash_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
            hash_table[i] = DEFAULT_VALUE;
     //table is empty
}


unsigned int hash(int key) {
    return (unsigned int)key % (unsigned int)TABLE_SIZE;
}
bool insert(int value)
{
    int index = hash(value);
    if (hash_table[index] == DEFAULT_VALUE)
    {
        hash_table[index] = value;
        return (true);
    }
    return (false);
}
int get(int index)
{
    int value = hash_table[index];
    return (value);
}

void test(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (insert(array[i]) == false)
        {
            printf("%i\n", array[i]);
            return;
        }
    }
    printf("No one\n");
}

int main (void)
{
    int arr1[] = {2,5,1,2,3,5,1,2,4}; //2
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2,1,1,2,3,5,1,2,4}; //1
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
 
    int arr3[] = {2,3,4,5}; //nothing
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    
    int arr4[] = {2,5,5,2,3,5,1,2,4}; //5
    int size4 = sizeof(arr4) / sizeof(arr4[0]);

    init_hash_table();
    // array 1
    // test(arr1, size1);
    
    //array 2
    // test(arr2, size2);
    
    //array 3
    // test(arr3, size3);

    //array 4
    test(arr4, size4);


    return (0);
}