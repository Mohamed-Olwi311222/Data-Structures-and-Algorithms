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
    list_t *what = find_node(head, 30);
    size_t count = print_list(head);
}
