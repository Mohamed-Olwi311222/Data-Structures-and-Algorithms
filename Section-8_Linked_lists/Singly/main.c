#include "list.h"
int main(void)
{
    list_t *head = NULL;
    list_t *tmp;
    tmp = create_new_node(10);
    insert_at_head(&head, tmp);  
    tmp = create_new_node(20);
    insert_at_head(&head, tmp);
    tmp = append(&head, 30);
    tmp = append(&head, 40);
    tmp = append(&head, 50);
    tmp = append(&head, 60);
    tmp = append(&head, 70);
    tmp = insert(&head, 2, 35);
    /*----------------------------------------------------------------------------------------*/
    printf("test for freeHead ,append, insert, insert_at_head and find node\n");
    size_t count1 = print_list(head);
    list_t *what = find_node(head, 30);
    printf("what->value: %d\n", what->value);
    freeHead(&head);
    size_t count2 = print_list(head);
    printf("count1: %ld\n", count1);
    printf("count2: %ld\n", count2);
    /*----------------------------------------------------------------------------------------*/
    printf("test for freeNode\n");
    size_t count3 = print_list(head);
    freeNode(&head, 1);
    size_t count4 = print_list(head);
    printf("count3: %ld\n", count3);
    printf("count4: %ld\n", count4);
    /*----------------------------------------------------------------------------------------*/
    printf("test for freeList_t\n");
    freeList_t(&head);
    size_t count5 = print_list(head);
    printf("count5: %ld\n", count5);
    return (0);
}
