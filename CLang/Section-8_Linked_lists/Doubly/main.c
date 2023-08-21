#include "listd.h"
int main(void)
{
    list_d *head = NULL, *tail = NULL;
    list_d *tmp;
    size_t count;     
    tmp = create_new_node(10);
    insert_at_head(&head, tmp);
    tmp = create_new_node(20);
    insert_at_head(&head, tmp);
    tail = traverseList_d(head);
    tmp = append(&tail, 30);
    tmp = append(&tail, 40);
    tmp = append(&tail, 50);
    tmp = append(&tail, 60);
    tmp = append(&tail, 70);
    tmp = insert(&head, &tail,21111, 80);
    printf("length: %lu\n", length);
    /*----------------------------------------------------------------------------------------*/
    printf("test for freeHead ,append, insert, insert_at_head and find node\n\n\n");
    count = print_list(head);
    list_d *what = find_node(head, 30);
    printf("what->value: %d\n", what->value);
    freeHead(&head);
    count = print_list(head);
    printf("length: %ld\n", length);
    /*----------------------------------------------------------------------------------------*/
    printf("\n\n\ntest for freeNode\n\n\n");
    count = print_list(head);
    freeNode(&head, &tail, 999);
    count = print_list(head);
    printf("length: %lu\n", length);
    /*----------------------------------------------------------------------------------------*/
    //printf("\n\n\ntest for freeList_t\n\n\n");
    //freeList_d(&head);
    //count = print_list(head);
    //printf("length: %lu", length);
    /*----------------------------------------------------------------------------------------*/
    printf("\n\n\ntest for reverseList\n\n\n");
    count = print_list(head);
    printf("length: %lu\n", length);
    reverseList(&head, &tail);
    count = print_list(head);
    printf("%lu\n", length);
    return (0);
}
