#include "tree.h"

int main(void)
{
    node *root = NULL;
    bool found = false;
    int value[9] = {9, 4, 20, 1, 6, 15, 170, INT_MAX, INT_MIN};
    int value2[9] = {9, 4, 20, 1, 6, 15, 170, INT_MAX, INT_MIN};
    insert_tree(&root, 9);
    insert_tree(&root, 4);
    insert_tree(&root, 20);
    insert_tree(&root, 1);
    insert_tree(&root, 6);
    insert_tree(&root, 15);
    insert_tree(&root, 170);
    for (int i = 0; i < 9; i++)
    {
        found = look_up_tree(root, value[i]);
        printf("%d is found: %s\n", value[i], found ? "true" : "false");
    }
    for (int i = 0; i < 9; i++)
    {
        found = remove_node(&root, value2[i]);
        printf("%d is deleted: %s\n", value[i], found ? "true" : "false");
    } 
    printf("remove node(400) is: %d\n", remove_node(&root, 400));
}