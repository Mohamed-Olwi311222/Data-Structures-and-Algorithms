#include "list.h"
int main(void)
{
    list_t *head = NULL;
    list_t *tmp, *tail;
    size_t count;
    tmp = create_new_node(10);
    insert_at_head(&head, tmp);  
    tmp = create_new_node(20);
    insert_at_head(&head, tmp);
    tail = traverseList(head);
    tmp = append(&tail, 30);
    tmp = append(&tail, 40);
    tmp = append(&tail, 50);
    tmp = append(&tail, 60);
    tmp = append(&tail, 70);
    tmp = insert(&head, &tail, 3, 35);
    /*----------------------------------------------------------------------------------------*/
    printf("test for freeHead ,append, insert, insert_at_head and find node\n\n\n");
    count = print_list(head);
    printf("length: %lu\n", length);
    list_t *what = find_node(head, 30);
    printf("what->value: %d\n", what->value);
    freeHead(&head);
    count = print_list(head);
    printf("length: %lu\n", length);
    /*----------------------------------------------------------------------------------------*/
    printf("\n\n\ntest for freeNode\n");
    count = print_list(head);
    printf("length: %lu\n", length);
    freeNode(&head, 3);
    count = print_list(head);
    printf("length: %lu\n", length);
    /*----------------------------------------------------------------------------------------*/
    /*printf("\n\n\ntest for freeList_t\n");
    count = print_list(head);
    printf("length: %lu\n", length);
    freeList_t(&head);
    count = print_list(head);
    printf("length: %lu\n", length);*/
    /*----------------------------------------------------------------------------------------*/
    printf("\n\n\ntest for reverseList\n");
    reverseList(&head, &tail);
    count = print_list(head);
    printf("length: %lu\n", length);
    return (0);
}
