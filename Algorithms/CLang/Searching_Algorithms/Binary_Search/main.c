#include "binary.h"
#define ARRAY_SIZE 11
int main(void){
    int arr[ARRAY_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 10 , 15, 30};

    int index = 0; 
    
    for (register int i = 0; i < ARRAY_SIZE; i++)
    {
        index = binary_search(arr, ARRAY_SIZE, arr[i]);
        printf("index is %i\n", index);

    }

        index = binary_search(arr, ARRAY_SIZE, -312);
        printf("index is %i\n", index);
        
        index = binary_search(NULL, ARRAY_SIZE, 2);
        printf("index is %i\n", index);
    return (0);
}