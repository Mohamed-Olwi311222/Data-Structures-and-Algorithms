#include "functions.h"

int main(void)
{
    node *root = NULL;
    int value[9] = {9, 4, 20, 1, 6, 15, 170, 0, INT_MIN};
    int value2[9] = {9, 4, 20, 1, 6, 15, 170, INT_MIN, INT_MAX};
    insert_tree(&root, 9);
    insert_tree(&root, 4);
    insert_tree(&root, 6);
    insert_tree(&root, 20);
    insert_tree(&root, 170);
    insert_tree(&root, 15);
    insert_tree(&root, 1);
    printf("Note the order is inversed as its a stack(no dynamic array in c)\n\n");
    printf("Pre-order: \n");
    DFS_preordered(root);
    printf("\n=========================================\n");
    printf("In-order: \n");
    DFS_ordered(root);
    printf("\n=========================================\n");
    printf("Post-order: \n");
    DFS_postordered(root);
    printf("\n=========================================\n");
    printf("Deleteing\n");
    for (int i = 0; i < 9; i++)
    {
        int done = remove_node(&root, value[i]);
        printf("%d is remove_node %d\n", value[i], done);
    }
    printf("Done\n");

}